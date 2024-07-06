#include<stdio.h>
#include<semaphore.h>

int shared=0;
sem_t sem;

void* thread1(){
    sem_wait(&sem);
    int x=shared;
    printf("The thread2 accessed the shared variable as %d",x);
    x++;
    printf("The thread2 locally updated the shared variable as %d",x);
    shared=x;
    printf("The thread2 updating the shared variable as %d",shared);
    sem_post(&sem);
}

void* thread2(){
    sem_wait(&sem);
    int x=shared;
    printf("The thread2 accessed the shared variable as %d",x);
    x--;
    printf("The thread2 locally updated the shared variable as %d",x);
    shared=x;
    printf("The thread2 updating the shared variable as %d",shared);
    sem_post(&sem);
}

int main(){
    pthread_t t1[10],t2[10];
    sem_init(&sem,0);
    
    for(int i=0;i<5;i++){
        pthread_create(&t1[i],NULL,(void*) thread1,NULL);
    }
    for(int i=0;i<5;i++){
        pthread_create(&t2[i],NULL,(void*) thread2,NULL);
    }
    for(int i=0;i<5;i++){
        pthread_join(t1[i],NULL);
    }
    for(int i=0;i<5;i++){
        pthread_join(t1[i],NULL);
    }
    printf("The final value of shared variable is:");
    
}
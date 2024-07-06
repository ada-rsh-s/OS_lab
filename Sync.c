#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

int shared=1;
sem_t sem;

void* thread1(){
    sem_wait(&sem);
    int x=shared;
    printf("The thread1 accessed the shared variable as %d\n",x);
    x++;
    printf("The thread1 locally updated the shared variable as %d\n",x);
    sleep(1);
    shared=x;
    printf("The thread1 updating the shared variable as %d\n",shared);
    sem_post(&sem);
}

void* thread2(){
    sem_wait(&sem);
    int x=shared;
    printf("The thread2 accessed the shared variable as %d\n",x);
    x--;
    printf("The thread2 locally updated the shared variable as %d\n",x);
    sleep(1);
    shared=x;
    printf("The thread2 updating the shared variable as %d\n",shared);
    sem_post(&sem);
}

int main(){
    pthread_t t1,t2;
    sem_init(&sem,0,1);
    
    pthread_create(&t1,NULL,(void*) thread1,NULL);
    pthread_create(&t2,NULL,(void*) thread2,NULL);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    printf("The final value of shared variable is : %d",shared);
    
}
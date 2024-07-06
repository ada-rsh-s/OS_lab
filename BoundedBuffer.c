#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t empty,full;
pthread_mutex_t mutex;
int buffer[5];
int item,count=0;

void* producer(void* arg){
    long int num=(long int)arg;
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    item=rand()%10;
    buffer[count]=item;
    printf("Producer %ld produced %d\n",num+1,item);
    count++;
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    pthread_exit(NULL);

}

void* consumer(void* arg){
    long int num=(long int)arg;
    sem_post(&empty);
    pthread_mutex_lock(&mutex);
    count--;
    printf("Consumer %ld consumerd %d\n",num+1,buffer[count]);
    pthread_mutex_unlock(&mutex);
    sem_wait(&full);
    pthread_exit(NULL);

}


int main(){
    pthread_t pro[5],cons[5];
    sem_init(&empty,0,5);
    sem_init(&full,0,0);
    pthread_mutex_init(&mutex,NULL);

    for(long int i=0;i<5;i++){
        pthread_create(&pro[i],NULL,(void*)producer,(void*)i);
    }
    for(long int i=0;i<5;i++){
        pthread_create(&cons[i],NULL,(void*)consumer,(void*)i);
    }
    for(int i=0;i<5;i++){
        pthread_join(pro[i],NULL);
    }
    for(int i=0;i<5;i++){
        pthread_join(cons[i],NULL);
    }

    pthread_mutex_destroy(&mutex);

}
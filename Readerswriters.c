#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t wrt;
pthread_mutex_t mutex;
int cnt=1;
int numreader;

void *reader(int* rno){
    pthread_mutex_lock(&mutex);
    numreader++;
    if(numreader==1)
     sem_wait(&wrt);
    pthread_mutex_unlock(&mutex); 

    printf("Reader %d updated cnt to %d",*((int*)rno),cnt);
    
    pthread_mutex_lock(&mutex);
    numreader--;
    if(numreader==0)
     sem_post(&wrt);
    pthread_mutex_unlock(&mutex);
}

void *writer(int* wno){
    sem_wait(&wrt);
    cnt*=2;
    printf("Writer %d updated cnt to %d",*((int*)wno),cnt);
    sem_post(&wrt);
}

int main(){

    int a[10]={1,2,3,4,5,6,7,8,9,10};

    pthread_t read[10],write[5];
    sem_init(&wrt,0,1);
    pthread_mutex_init(&mutex,NULL);

    for(int i=0;i<10;i++){
        pthread_create(&read[i],NULL,(void*)reader,(void*)&a[i]);
    }
    for(int i=0;i<5;i++){
        pthread_create(&write[i],NULL,(void*)writer,(void*)&a[i]);
    }

    for(int i=0;i<10;i++){
        pthread_join(read[i],NULL);
    }
    for(int i=0;i<5;i++){
        pthread_join(write[i],NULL);
    }
    
    pthread_mutex_destroy(&mutex);
}
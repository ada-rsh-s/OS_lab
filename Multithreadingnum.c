#include<stdio.h>
#include<pthread.h>

void* even(void* arg){
    long int num = (long int)arg;
    printf("Even numbers : ");
    for(int i=1;i<=num;i++){
        if(i%2==0)
         printf("%d ",i);
    }
}

void* odd(void* arg){
    long int num = (long int)arg;
    printf("Odd numbers : ");
    for(int i=1;i<=num;i++){
        if(i%2!=0)
         printf("%d ",i);
    }
}

void* sum(void* arg){
    long int num = (long int)arg,sum=0;
    printf("Sum of numbers : ");
    for(int i=1;i<=num;i++){
        sum+=i;
    }
    printf("%ld ",sum);
}


int main(){
    pthread_t t1,t2,t3;
    long int num;
    
    printf("Enter a number");
    scanf("%ld",&num);

    pthread_create(&t1,NULL,(void*)even,(void*)num);
    pthread_create(&t2,NULL,(void*)odd,(void*)num);
    pthread_create(&t3,NULL,(void*)sum,(void*)num);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    
}
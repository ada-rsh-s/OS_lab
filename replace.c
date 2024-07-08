#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    pid=fork();
    if(pid==0){
        execl("/bin/ps","ps",NULL);
        printf("child  id %d\n",getpid());

    }
    else
    {
        wait(NULL);
        printf("parent id %d\n",getpid());
    }   
}
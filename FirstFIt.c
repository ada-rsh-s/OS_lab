#include<stdio.h>

void firstFit(int process[],int process_size,int blocks[],int memory_size){
    int allocation[20];
    for(int i=0;i<process_size;i++)
        allocation[i]=-1;

    for(int i=0;i<process_size;i++){
        for(int j=0;j<memory_size;j++){
            if(process[i]<blocks[j] && blocks[j]!=-1)
            {
                allocation[i]=j+1;
                blocks[j]=-1;                                
                break;
            }
        }
    }

    printf("Process No\tProcess Size\tMemory Block\t\n");
    for(int i=0;i<process_size;i++){
        if(allocation[i]!=-1){
         printf("P%d\t\t %d\t\t%d\n",i+1,process[i],allocation[i]);
        }else{
         printf("P%d\t\t %d\t\tNot allocated\n",i+1,process[i]);
        }
    }
}

int main(){
    int process[20],blocks[20],process_size,memory_size;
    printf("Enter the number of process");
    scanf("%d",&process_size);
    printf("Enter the process");
    for(int i=0;i<process_size;i++){
        scanf("%d",&process[i]);
    }

    printf("Enter the number of memory");
    scanf("%d",&memory_size);
    printf("Enter the memory blocks");
    for(int i=0;i<memory_size;i++){
        scanf("%d",&blocks[i]);
    }
    firstFit(process,process_size,blocks,memory_size);

}
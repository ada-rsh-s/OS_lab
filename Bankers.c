#include<stdio.h>
int main(){
    int proc_no,res_no,max[20][20],alloc[20][20],avail[20],safeseq[20],safe_ind=0;
    
    printf("Enter number of process\n");
    scanf("%d",&proc_no);
    printf("Enter number of resources\n");
    scanf("%d",&res_no);

    printf("Enter max matrix:\n");
    for(int i = 0; i < proc_no; i++){
        for(int j = 0; j < res_no; j++){
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter alloc matrix:\n");
    for(int i = 0; i < proc_no; i++){
        for(int j = 0; j < res_no; j++){
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter avail matrix: ");
    for(int i = 0; i < res_no; i++){
        scanf("%d", &avail[i]);
    }

    int finish[proc_no],need[proc_no][res_no];

    for(int i=0;i<proc_no;i++)
      finish[i]=0;

    for(int i=0;i<proc_no;i++){
      for(int j=0;j<res_no;j++){
        need[i][j]=max[i][j]-alloc[i][j]; 
      }               
    }

    printf("The need matrix is \n");
    for(int i=0;i<proc_no;i++){
      for(int j=0;j<res_no;j++){
        printf("%d ",need[i][j]); 
      }      
      printf("\n");
    }

    for(int i=0;i<proc_no;i++){
      for(int j=0;j<proc_no;j++){
        if(finish[j]==0){
         int flag=0;
         for(int k=0;k<res_no;k++){
             if(need[j][k]>avail[k]){
                 flag=1;
                 break;
             }        
         }
         if(flag==0){
             safeseq[safe_ind++]=j;
             for(int l=0;l<res_no;l++)
             avail[l]+=alloc[j][l];
             finish[j]=1;
         }
       }
      }
    }

    printf("\nSafe seq\n");
    for(int i=0;i<proc_no;i++)
    printf("P%d ",safeseq[i]);
     
}
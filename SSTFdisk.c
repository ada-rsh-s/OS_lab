#include<stdio.h>
#include<stdlib.h>
int main(){
    int req[20],num_req,curr_p,curr_p_copy,nearest,nearest_ind,index[20],finish[20],sequence[20];
    
    printf("Enter number of requests");
    scanf("%d",&num_req);
    printf("Enter the requests");
    for(int i=0;i<num_req;i++){
        scanf("%d",&req[i]);
    }

    printf("Enter current pointer");
    scanf("%d",&curr_p);

    curr_p_copy=curr_p;
    
    for(int i=0;i<num_req;i++){
     for(int j=0;j<num_req;j++){ 
        if (req[j] != -1) { // Only calculate distance for unprocessed requests
                index[j] = abs(curr_p - req[j]);
            } else {
                index[j] = 9999; // Large number to ignore processed requests
            }
     }
     nearest=index[0];
     nearest_ind=0;
     for(int k=1;k<num_req;k++){
     if(nearest>index[k]){
        nearest_ind=k;
        nearest=index[k];
     }
    }
    
     sequence[i]=req[nearest_ind];
     curr_p=req[nearest_ind];
     req[nearest_ind]=-1;

    }
    printf(" %d",curr_p_copy);
    for(int i=0;i<num_req;i++){
     printf(" -> %d",sequence[i]);
    }

}
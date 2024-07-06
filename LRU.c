#include<stdio.h> 

void main() {
    int k,PF = 0,PH = 0,ref_str[25],frames[10],ref_length,frame_length; 

    printf("\n Enter the length of reference string -- "); 
    scanf("%d", &ref_length); 

    printf("\n Enter the reference string -- "); 
    for(int i = 0; i < ref_length; i++) 
        scanf("%d", &ref_str[i]); 

    printf("\n Enter no. of frames -- "); 
    scanf("%d", &frame_length); 

    for(int i = 0; i <frame_length; i++) 
    {
        frames[i] = -1;
    }
        
    printf("\n The Page Replacement Process is \n");

    for(int i = 0; i < ref_length; i++) { 
        for(k = 0; k < frame_length; k++) { 
            if(frames[k] == ref_str[i]) 
                break; 
        }  

        for(int j = frame_length-2; j >=0; j--){
            frames[j+1]=frames[j];                
        } 

        frames[0]=ref_str[i];
        for(int j = 0; j < frame_length; j++)
         printf("\t%d", frames[j]); 

        if(k == frame_length) { 
           PF++; 
           printf("\tPF No. %d\n", PF); 
        } else {
           PH++; 
           printf("\tPH No. %d\n", PH);  
        }    
    } 

    printf("\n The number of Page Faults using FIFO are %d", PF);
    printf("\n The number of Page Hits using FIFO are %d", PH);
}

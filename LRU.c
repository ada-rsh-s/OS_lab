// #include<stdio.h> 

// void main() {
//     int k,PF = 0,PH = 0,ref_str[20],frames[20],ref_length,frame_length; 

//     printf("\n Enter the length of reference string -- "); 
//     scanf("%d", &ref_length); 

//     printf("\n Enter the reference string -- "); 
//     for(int i = 0; i < ref_length; i++) 
//         scanf("%d", &ref_str[i]); 

//     printf("\n Enter no. of frames -- "); 
//     scanf("%d", &frame_length); 

//     for(int i = 0; i <frame_length; i++) {
//         frames[i] = -1;
//     }
        
//     printf("\n The Page Replacement Process is \n");

//     for(int i = 0; i < ref_length; i++) { 
//         for(k = 0; k < frame_length; k++) { 
//             if(frames[k] == ref_str[i]) 
//                 break; 
//         }  
                
//         if (k == frame_length) { 
//             for (int j = frame_length - 1; j >= 0; j--) {
//                 frames[j] = frames[j - 1];
//             }
//             frames[0] = ref_str[i];
//             for (int j = 0; j < frame_length; j++) {
//                 printf("\t%d", frames[j]);
//             }       
//             PF++;
//             printf("\tPF No. %d\n", PF);
//         } else { 
//             for (int j = 0; j < frame_length; j++) {
//                 printf("\t%d", frames[j]);
//             }
//             for (int j = frame_length - 1; j >= 0; j--) {
//                 frames[j] = frames[j - 1];
//             }
//             frames[0] = ref_str[i];
//             PH++;
//             printf("\tPH No. %d\n", PH);
//         }

//     } 

//     printf("\n The number of Page Faults using LRU are %d", PF);
//     printf("\n The number of Page Hits using LRU are %d", PH);
// }


#include<stdio.h> 

void main() {
    int i,j,k,PF = 0,PH = 0,ref_str[20],frames[20],ref_length,frame_length; 

    printf("\n Enter the length of reference string -- "); 
    scanf("%d", &ref_length); 

    int flag[ref_length]={0};
    printf("\n Enter the reference string -- "); 
    for(int i = 0; i < ref_length; i++) 
        scanf("%d", &ref_str[i]); 

    printf("\n Enter no. of frames -- "); 
    scanf("%d", &frame_length); 
    
    int count[frame_length]={0};
    for(int i = 0; i <frame_length; i++) {
        frames[i] = -1;
    }
        
    printf("\n The Page Replacement Process is \n");

    for(int i = 0; i < ref_length; i++) { 
        for(j = 0; j < frame_length; j++) { 
            if(frames[j] == ref_str[i]){
                flag[i]=1;
                count[j]=next;
                next++;
            } 
        }  

        if(flag[i]==0){
            if(i<frame_length){
                frames[i]=ref_str[i];
                count[i]=next;
                next++;                
            }else{
                
            }
            PF++;
        }

        for(int j = 0; j < frame_length; j++)
          printf("\t%d", frames[j]); 
        
        if(flag[i]==1) printf("\tPH No. %d\n", PH)
        else printf("\tPF No. %d\n", PF);
    }
}

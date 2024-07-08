#include <stdio.h>

int main() {
    int i, j, k, ref_str[10], frames[10], flag[25] = {0}, ref_length, frame_length, page_fault = 0;
    
    printf("Enter the length of the reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    printf("\nThe Page Replacement process is \n");
    for(i = 0; i < ref_length; i++){
        for(j = 0; j < frame_length; j++){
            if(ref_str[i] == frames[j]){
                
                flag[i] = 1;
                break;
            }
        }

        if(flag[i] == 0){
          int replace,farthest = i+1;

          for(j = 0; j < frame_length; j++){
             for(k = farthest; k < ref_length; k++){
               if(frames[i] == ref_str[j]){
                 break;
               }
             }
          }
        }
    }
}
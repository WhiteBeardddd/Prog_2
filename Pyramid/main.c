// Full Pyramid using Pointer Reference

#include <stdio.h>
#include <stdlib.h>

int main(){
    int height = 5;
    int *ptr = &height;
    int i, j;
    
    while(*ptr > 0)
    {
        for(j = 0; j < *ptr; j++)
        {
            printf("*");   
        }
        printf("\n");
        (*ptr)--;
    } 
    
    return 0;
}


//   int i; 
//   int j; 
//   int rows = 5; 
//   int k = 0;
//   int *ptr = &rows;
  
//   for (i = 1; i <= *ptr; ++i, k = 0) {
//       for (j = 1; j <= *ptr - i; ++j) {
//          printf("   ");
//       }
//       while (k != 2 * i - 1) {
//          printf("*  ");
//          ++k;
//       }
//       printf("\n");
//   }
 


  
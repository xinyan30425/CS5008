#include <stdio.h>
#include <stdlib.h>

// //checkpoint 1
// int main() {
//     int arr[20][30];
//     int i, j;

//     for (i = 0; i < 20; i++) {
//         for (j = 0; j < 30; j++) {
//             arr[i][j] = i + j;
//         }
//     }

//     // Print the array
//     for (i = 0; i < 20; i++) {
//         for (j = 0; j < 30; j++) {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
//     printf("Hello world!I have created a 2-D array of 20x30 integers\n");
//     return 0;
// }


// checkpoint 2

int main()
{
int **arr,i,j; //Declaration of pointer variables.

//allocate memory for the rows
//allocate 20 rows that contain pointers to integer
arr=(int**)malloc(20*sizeof(int*)); 

// allocate memory for the columns
// allocate 30 columns for each row
// each row representing an array with 30 columns
for(i=0;i<20;i++)
    arr[i]=(int*)malloc(30*sizeof(int));

// fill up integers to each index of each corresponding row and column
// which equals to the sum of the row index and the column index
for(i=0;i<20;i++)
    for(j=0;j<30;j++)
        arr[i][j]=i+j;
    
//print the array
for(i=0;i<20;i++){
    for(j=0;j<30;j++){
        printf("%d ",arr[i][j]);}
        printf("\n");}
    

printf("Hello world!I have created a 2-D array of 20x30 integers\n"); 

//free the memory
for(i=0;i<20;i++)
    free(arr[i]);    
    free(arr);

return 0;
}


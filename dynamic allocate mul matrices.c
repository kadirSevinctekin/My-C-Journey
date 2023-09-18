#include<stdio.h>
#include<stdlib.h>
int main()
{
	// define variables
	int i, j, k, row1, column1, row2, column2;
   int** arr1;
   int** arr2;
   printf("enter the number of rows of first matrix: ");
   scanf("%d", &row1);
   printf("enter the number of columns of first matrix: ");
   scanf("%d", &column1);
   printf("enter the number of rows of second matrix: ");
   scanf("%d", &row2);
   printf("enter the number of columns of second matrix: ");
   scanf("%d", &column2);
   if(column1==row2){
   	// allocate memory
   int** arr3 = malloc(row1*sizeof(int*));
   for(i=0;i<row1;i++){
   	arr3[i]=malloc(column2*sizeof(int));
   }
   arr1=malloc(row1*sizeof(int*));
   arr2=malloc(row2*sizeof(int*));
   if(arr1==NULL){
   	printf("can not allocate memory. ");
   	return -1;
   }
   if(arr2==NULL){
   	printf("can not allocate memory. ");
   	return -1;
   }
   // allocate
   for(i=0;i<row1;i++){
   	arr1[i]=malloc(column1*sizeof(int));
   }
   for(i=0;i<row2;i++){
   	arr2[i]=malloc(column2*sizeof(int));
   }
   // ask for elements
   for(i=0;i<row1;i++){
   		for(j=0;j<column1;j++){
   			printf("enter the %d x %d element of first matrix: ", i+1, j+1);
   			scanf("%d", &arr1[i][j]);
		   }
   }
   for(i=0;i<row2;i++){
   		for(j=0;j<column2;j++){
   			printf("enter the %d x %d element of second matrix: ", i+1, j+1);
   			scanf("%d", &arr2[i][j]);
		   }
   }
   // mul
   for(i=0;i<row1;i++){
   		for(j=0;j<column2;j++){
   			arr3[i][j]=0;
   			for(k=0;k<column1;k++){
   				arr3[i][j]+=arr1[i][k]*arr2[k][j];
			   }
		   }
   }
   // print arrys
   for(i=0;i<row1;i++){    
            for(j=0;j<column1;j++){    
                printf("%d\t",arr1[i][j]);    
            }    
            printf("\n");    
    }
	printf("\n"); 
	for(i=0;i<row2;i++){    
            for(j=0;j<column2;j++){    
                printf("%d\t",arr2[i][j]);    
            }    
            printf("\n");    
    } 
    printf("\n");
   printf("multiplied matrix\n");
   for(i=0;i<row1;i++){    
            for(j=0;j<column2;j++){    
                printf("%d\t",arr3[i][j]);    
            }    
            printf("\n");    
    } 
   // free array
   for(i=0;i<row1;i++){
   	free(arr1[i]);
   }
   free(arr1);
   for(i=0;i<row2;i++){
   	free(arr2[i]);
   }
   free(arr2);
   for(i=0;i<row1;i++){
   	free(arr3[i]);
   }
   free(arr3);
   }
   else{
   	printf("not available matrices. ");
   }
   
    return 0;
}

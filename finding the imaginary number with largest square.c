#include <stdio.h>
#include <stdlib.h>
// Finding the largest sum of the squares of the real and imaginary parts of complex numbers obtained from the user (e.g., (7+5i), (1-9i)).

int findLargest(int **matrix, int n);

int main(){
	int i, j, N, indis;
	int **matrix;
	printf("Enter value of N: ");
	scanf("%d", &N);
	// create dynamic matrix
	matrix=(int**)malloc(N*sizeof(int*)); 
	if(matrix==NULL){
		printf("couldnt allocate!\n");
		return -1;
	}
	for(i=0;i<N;i++){
		matrix[i]=(int*)malloc(2*sizeof(int));
		if(matrix==NULL){
			printf("couldnt allocate!\n");
			return -2;
		}
	}
	// scanf matrix elements
	for(i=0;i<N;i++){
		printf("Please enter the real part of the %d. number: ",i+1);
		scanf("%d", &matrix[i][0]);
		printf("Please enter the imaginary part of the %d. number: ",i+1);
		scanf("%d", &matrix[i][1]); printf("\n");
	}
	indis=findLargest(matrix, N);
	printf("\nThe number with the largest square is number %d", indis+1);
	// free
	for(i=0;i<N;i++){
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}
// func that finds the largest squared number
int findLargest(int **matrix, int n){
	int i, k1, k2,tmp,indis=0;
	k1=(matrix[0][0]*matrix[0][0])-(matrix[0][1]*matrix[0][1]); // SQUARE THE VIRTUAL PART FROM THE REAL PART TO K1
	for(i=1;i<n;i++){
		k2=(matrix[i][0]*matrix[i][0])-(matrix[i][1]* matrix[i][1]);
		if(k1<k2){
			tmp=k1;
			k1=k2;
			k2=tmp;
			indis=i;
		}
	}
	return indis;
}

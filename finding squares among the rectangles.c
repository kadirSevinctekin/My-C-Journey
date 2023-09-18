#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **verileriOku(int size);
int **kareBul(int ** mat, int a);

void yazdir(int**arr1, int size1, int**bellek, int karesayisi);
static int a =0;

int main(){
	srand(time(NULL));
	int i, j, N, **tut;
	printf("Enter the value of N: ");
	scanf("%d", &N);
	tut = verileriOku(N);
	
	int **arrkare1;
	
	arrkare1=kareBul(tut, a);
	yazdir(tut, N, arrkare1, a);
	return 0;
}


int **verileriOku(int size){
	int i, j;
	
	int **matris=(int**)malloc(size*sizeof(int*));
	for(i=0;i<size;i++){
		matris[i]=(int*)malloc(2*sizeof(int));
	}
	for(i=0;i<size;i++){
		matris[i][0]=rand()%7+1;
		matris[i][1]=rand()%7+1;
		if(matris[i][0]==matris[i][1]){
			a++;
		}
	}
	return matris;
}

int **kareBul(int **mat, int b){
	int i,j=0;
	int **arrkare=(int**)malloc(b*sizeof(int*));
	for(i=0;i<b;i++){
		if(mat[i][0]==mat[i][1]){
			arrkare[j]=mat[i];
			j++;
		}
	}
	return arrkare;
}

void yazdir(int**arr1, int size1, int**bellek, int karesayisi){
	printf("Edge-1\tEdge-2\tInfo: Number of squares = %d\n", karesayisi);
	int i, j, k;
	for(i=0;i<size1;i++){
		printf("%d\t%d\t", arr1[i][0], arr1[i][1]);
		for(j=0;j<karesayisi;j++){
			if(arr1[i]==bellek[j]){
				printf("Square");
			}
		}
		printf("\n");
	}
}

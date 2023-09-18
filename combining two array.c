#include <stdio.h>

int *combining(int *d1, int size1, int* d2, int size2);
void print(int *dizi, int size);

int main(){
	int n, m, *merged;
	int ar1[]={1,3,31,31,5};
	int ar2[]={123,31,1,2};
	n = sizeof(ar1)/sizeof(ar1[0]);
	m = sizeof(ar2)/sizeof(ar2[0]);
	merged=combining(ar1, n, ar2, m);
	print(merged, n+m);
	free(merged);
	return 0;
}
// Combining two array
int *combining(int *d1, int size1, int* d2, int size2){
	int i, j;
	int *kk;
	kk=(int*)malloc((size1+size2)*sizeof(int));
	for(i=0;i<size1;i++){
		kk[i]=d1[i];
	}
	for(i=size1, j=0; i<size1+size2; i++,j++){
		kk[i]=d2[j];
	}
	return kk;
}
// printing combined array
void print(int *dizi, int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d ", dizi[i]);
	}
}

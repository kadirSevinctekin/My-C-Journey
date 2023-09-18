#include <stdio.h>
#include <stdlib.h>
int main(){
	int i, n, j, temp;
	printf("enter array size: ");
	scanf("%d", &n);
	int* array = malloc(n*sizeof(int));
	if(array==NULL){
		printf("couldnt allocate!\n");
		return -1;
	}
	for(i=0;i<n;i++){
		printf("enter the %d. value: ", i+1);
		scanf("%d", array+i);
	}
	//sorting
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(*(array+j)>*(array+j+1)){
				temp = *(array+j+1);
				*(array+j+1) = *(array+j);
				*(array+j) = temp;
			}
		}
	}
	printf("sorted array: ");
	for(i=0;i<n;i++){
		printf("%d ", *(array+i));
	}
	free(array);
	return 0;
}

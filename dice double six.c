// Keep rolling dices until double six meanwhile malloc array
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int i=0, j, k=2, dice, jj;
	int* matrix =malloc(k*sizeof(int));
	if(matrix==NULL){
		printf("allocation error!\n");
		return -1;
	}
	// assigning first two dice
	dice = rand()%6+1;
	matrix[i]=dice;
	i++;
	dice = rand()%6+1;
	matrix[i]=dice;
	while(matrix[i]!=6 || matrix[i-1]!=6){
			if(i==k-1){ // malloc control
				k*=2;
				matrix=realloc(matrix, k*sizeof(int));
				if(matrix==NULL){
					printf("allocation error!\n");
					return -1;
				}
				else{
					i++;
					dice = rand()%6+1;
					matrix[i]=dice;
				}
			} // if malloc control okay operations goes on
			else{
					i++;
					dice = rand()%6+1;
					matrix[i]=dice;
			}
	//printing array
	}
	for(jj=0;jj<=i;jj++){
		printf("%d ", matrix[jj]);
	}
	printf("\nnumber of element in array: %d ", i);
	printf("\nsize of array: %d ", k);
	free(matrix);
	return 0;
}


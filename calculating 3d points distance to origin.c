#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
typedef struct dot{
	int dist;
}DOT;

void print(DOT** , int );
float calcu(DOT**, int );
void order(DOT** , int, int );
int main(){
	int i, j, choice;
	srand(time(NULL));
	int dots;
	printf("enter the number of points: ");
	scanf("%d", &dots);
	DOT **p=(DOT**)malloc(dots*sizeof(DOT*));
	for(i=0;i<dots;i++){
		p[i]=(DOT*)malloc(3*sizeof(DOT));
	}
	for(i=0;i<dots;i++){
		for(j=0;j<3;j++){
			p[i][j].dist=rand()%8+1;
		}
	}
	print(p, dots);
	printf("1-for ascending 2-for descending");
	scanf("%d", &choice);
	order(p, dots, choice);
	print(p, dots);
	return 0;
}

void print(DOT** p, int size){
	int i, j;
	for(i=0;i<size;i++){
		for(j=0;j<3;j++){
			printf("%d ", p[i][j].dist);
		}
		printf("--- (%2.2f)", calcu(p, i));
		printf("\n");
	}
}

float calcu(DOT**p, int row){
	int i= 2;
	float h;
	float a=pow(p[row][0].dist, i);
	float b=pow(p[row][1].dist, i);
	float c=pow(p[row][2].dist, i);
	h=a+b+c;
	float sonuc=pow(h,0.5);
	return sonuc;
}

void order(DOT** p, int size, int choice){
	int i,j, minindex, maxindex; 
	float tmp;
	DOT* temp1;
	if(choice==1){
		for(i=0;i<size;i++){
			minindex=i;
			for(j=1+i;j<size;j++){
				if(calcu(p,j)<calcu(p,minindex)){
					minindex=j;
				}
			}
			temp1=p[i];
			p[i]=p[minindex];
			p[minindex]=temp1;
		}
	}
	else{
		for(i=0;i<size;i++){
			maxindex=i;
			for(j=1+i;j<size;j++){
				if(calcu(p,j)>calcu(p,maxindex)){
					maxindex=j;
				}
			}
		temp1=p[i];
		p[i]=p[maxindex];
		p[maxindex]=temp1;
		}
	}
	
}

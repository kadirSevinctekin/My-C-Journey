#include <stdio.h>
#define MAX 100

int findprime(int x, int y);

int main(){
	int a, b, temp;
	printf("Enter two numbers: ");
	scanf("%d%d", &a,&b);
	if(a>b){
		temp=a;
		a=b;
		b=temp;
	}
	findprime(a, b);
	return 0;
}

findprime(int x, int y){
	int i, j, flag, dizi[MAX], k=0;
	if(x==1){
		x++;
	}
	if(x==0){
		x=x+2;
	}
	for(i=x;i<=y;i++){
		flag=0;
		for(j=2;j<=i/2;j++){
			if(i%j==0){
				flag = 1;
			}
		}
		if(flag==0){
			dizi[k]=i;
			k++;
		}
	}
	for(i=0;i<k;i++){
		printf("%d ", dizi[i]);
	}
}

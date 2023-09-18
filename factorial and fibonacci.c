#include <stdio.h>

int fact(int);
int fib(int);

int main(){
	int x;
	printf("Enter the number to be calculated: ");
	scanf("%d", &x);
	printf("Factorial of the entered number: %d\n", fact(x));
	int y;
	printf("Calculate which term of fibonacci: ");
	scanf("%d", &y);
	printf("\n%d", fib(y-1));
	return 0;
}
// Factorial
	fact(int a){
		if(a==1){
			return 1;
		}
		return a*fact(a-1);
	}
// Fibonacci
	fib(int n){
		if(n==1 || n==0){
			return 1;
		}
		return fib(n-1)+fib(n-2);
	}


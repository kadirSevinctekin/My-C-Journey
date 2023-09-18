#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
A program will be written to perform calculations to determine whether a point P, given its x and y coordinates, lies within a circle with 
center point M and radius r. Hint: 
For a point P(x, y) to be inside a circle centered at M(z, t) with radius r, the equation (x-z)2 + (y-t)2 <= r2 must be satisfied.

a. Define a struct named "Point" responsible for storing the X and Y coordinates of a point.
b. Define a struct named "Circle" that contains members of type "Point" to store the center and radius of a circle.
c. Write a function that returns whether a point P lies within a circle D.
d. Implement a main method that prompts the user to enter information about a circle and N points, 
and prints which points are inside or outside the circle.
*/

typedef struct node{
	int x,y;
}NODE;

typedef struct circle{
	int r;
	NODE center;
}CIRCLE;

void insideControl(CIRCLE circle, NODE *nodeArr, int n){
	int a,b,c,i;
	for(i=0;i<n;i++){
		a=nodeArr[i].x-circle.center.x; a=pow(a,2);
		b=nodeArr[i].y-circle.center.y; b=pow(b,2);
		c=pow(circle.r,2);
		if(a+b<=c) printf("%d. point (%d,%d) is inside the circle\n", i+1, nodeArr[i].x, nodeArr[i].y);
		else printf("%d. point (%d,%d) is outside the circle\n", i+1, nodeArr[i].x, nodeArr[i].y);
	}
}

int main(){
	int i, n;
	CIRCLE circle;
	printf("enter center points of the circle: "); scanf("%d %d", &circle.center.x, &circle.center.y);
	printf("enter radius of the circle: "); scanf("%d", &circle.r);
	printf("how many points will there be? "); scanf("%d", &n);
	NODE* nodeArr=(NODE*)malloc(n*sizeof(NODE));
	if(nodeArr==NULL) printf("allocation error\n");
	for(i=0;i<n;i++){
		printf("enter x y values of %d. point ", i+1); scanf("%d %d", &nodeArr[i].x, &nodeArr[i].y);
	}	
	insideControl(circle, nodeArr, n);
	return 0;
}

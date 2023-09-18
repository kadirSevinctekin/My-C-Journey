#include <stdio.h>
#include<string.h>
#define MAX_CHAR 50

int indexofV1(char *ptr1, char *ptr2);

int main(){
	int result;
	char str1[MAX_CHAR], str2[MAX_CHAR];
	printf("enter the 1st string (max. %d characters): ", MAX_CHAR);
	scanf(" %[^\n]", str1);
	printf("enter the 2st string (max. %d characters): ", MAX_CHAR);
	scanf(" %[^\n]", str2);
	result=indexofV1(str1, str2);
	if(result==-1)	
		printf("not found");
	else
		printf("found at from %d. letter", result+1);
	return 0;
}

int indexofV1(char *ptr1, char *ptr2){
	int i, matchcount=0;
	int len1=strlen(ptr1), len2=strlen(ptr2);
	for(i=0;i<=len1-len2;i++){
		while(*ptr1==*ptr2 && matchcount!=len2){
			matchcount++;
			ptr1++; ptr2++;
		}
		if(matchcount==len2) return i;
		else{
			ptr1-=(matchcount-1);
			ptr2-=matchcount; matchcount=0;
		}
	}
	return -1;
}

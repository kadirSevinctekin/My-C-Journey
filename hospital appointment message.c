#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hasta{ 
	int  randevu_no;
	char isim[10]; 
	char poliklinik[10]; 
	char gun[10];	      
}HASTA;

void readFromFile(HASTA* ptr, char* fileName, int N, FILE* fp){
	int i=0;
	if(fp==NULL){
		printf("could not be opened\n");
	}
	fread(&N, sizeof(int), 1, fp);
	fread(ptr, sizeof(HASTA), 4, fp);	
}

void print(HASTA* ptr, int N){
	int i;
	if(ptr==NULL){
		printf("list is empty\n");
	}
	else{
		for(i=0;i<4;i++){
			printf("%d %s %s %s\n", ptr[i].randevu_no, ptr[i].isim, ptr[i].poliklinik, ptr[i].gun);
		}		
	}
}

void mesajYazdir(HASTA *ptr, int N){
	int i;
	for(i=0;i<N;i++){
		printf("merhaba %s %s gununde %s polikliniginde %d numarali randevunuz bulunmaktadir\n", ptr[i].isim, ptr[i].gun, ptr[i].poliklinik, ptr[i].randevu_no);
	}
}

int main(){
	FILE *fp;
	char fileName[15];
	HASTA h[4]={{1,"ali","dahiliye","sali"},{2,"veli","goz","cuma"},{3,"ayse","cerrahi","pazar"},{4,"fatma","goz","sali"}};
	int N = 4;
	HASTA *ptr = (HASTA*) malloc(N*sizeof(HASTA));
	fp = fopen("input.txt","w");
	fwrite(&N,sizeof(int),1,fp);
	fwrite(h,sizeof(HASTA)*N,1,fp);
	fclose(fp);
	strcpy(fileName, "input.txt");
	fp=fopen("input.txt", "rb");
	readFromFile(ptr, fileName, N, fp);
	fclose(fp);
	print(ptr, N);
	printf("\n");
	mesajYazdir(ptr, N);
	return 0;
}




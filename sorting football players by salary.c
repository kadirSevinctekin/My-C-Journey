// SORTING PLAYERS ACCORDING TO SALARYxCONTRACT and FINDING MIN OR MAX SALARY CERTAIN POSITION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player{
    int salary, contract;
    char position[15];
}PLAYER;

void taking(PLAYER *p1, int n);
void printing(PLAYER *p1, int n);
void sort(PLAYER *p1, int n);
int find(PLAYER *p1, int n, char* search, int maxmin);
int main(){
    int i,j,n,maxmin,indis;
    PLAYER *p1;
    char search[15];
    printf("enter the number of players: ");
    scanf("%d", &n);
    p1=(PLAYER*)malloc(n*sizeof(PLAYER));
    // enter data
    taking(p1, n);
    // print list
    printing(p1, n);
    // sorting according to contract*salary
    sort(p1, n);
    // finding lowest or highest salary in a certain position
    printf("enter the position and max or min salary (1 for max 0 for min):"); scanf("%s %d", search,&maxmin);
    indis=find(p1, n, search, maxmin);
    printf("\nplayer's position: %s contract: %d salary: %d", p1[indis].position,p1[indis].contract,p1[indis].salary);
    free(p1);
    return 0;
}
void taking(PLAYER *p1, int n){
    int i;
    for(i=0;i<n;i++){
        printf("enter the position of %d. player: ", i+1); scanf("%s", p1[i].position);
        printf("enter the contract of %d. player: ", i+1); scanf("%d", &p1[i].contract);
        printf("enter the salary of %d. player: ", i+1); scanf("%d", &p1[i].salary);
    }
}
void printing(PLAYER *p1, int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d. player's position: %s contract: %d salary: %d\n",i+1, p1[i].position,p1[i].contract,p1[i].salary);
    }
}
void sort(PLAYER *p1, int n){
    int i,j, tmp;
    char temp[15];
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p1[j].contract*p1[j].salary<p1[j+1].contract*p1[j+1].salary){
                // swap contract
                tmp=p1[j].contract;
                p1[j].contract=p1[j+1].contract;
                p1[j+1].contract=tmp;
                // swap salary
                tmp=p1[j].salary;
                p1[j].salary=p1[j+1].salary;
                p1[j+1].salary=tmp;
                // swap position
                strcpy(temp,p1[j].position);
                strcpy(p1[j].position,p1[j+1].position);
                strcpy(p1[j+1].position,temp);
            }
        }
    }
    printf("new sorted list:\n");
    for(i=0;i<n;i++){
        printf("%d. player's position: %s contract: %d salary: %d (%d)\n",i+1, p1[i].position,p1[i].contract,p1[i].salary,p1[i].contract*p1[i].salary);
    }
}
int find(PLAYER *p1, int n, char* search, int maxmin){
    int i,cmp=1,arr[n],k=0;
    for(i=0;i<n;i++){
            cmp=strcmp(p1[i].position, search);
            if(cmp==0){
                arr[k]=i;
                k++;
            }
    }
    if(maxmin==0){
        // find min
        cmp=0;
        for(i=1;i<k;i++){
            if(p1[arr[i]].salary<p1[cmp].salary){
                cmp=arr[i];
            }
        }
    }
    else{
        // find max
        cmp=0;
        for(i=1;i<k;i++){
            if(p1[arr[i]].salary>p1[cmp].salary)
            cmp=arr[i];
        }
    }
    return cmp;
}

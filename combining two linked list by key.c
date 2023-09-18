// Combining 2 linked lists according to their key values and making them compact.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int v1, key;
	struct Node *next;
}NODE;

void printList(NODE* n); // print
void insert(NODE** head_ref, int key, int v1);// add from last
NODE* reduce(NODE* start1, NODE* start2, int(*reduce_f)(NODE*, NODE*));
int reduce_sum(NODE* node1, NODE* node2);
int reduce_max(NODE* node1, NODE* node2); 
NODE* createNode(int key, int v1);

int main(){
	NODE* start=NULL;
	insert(&start, 1, 10); insert(&start, 2, 20);
	insert(&start, 4, 20), insert(&start, 7, 30);
	
	NODE* start2=NULL;
	insert(&start2, 1, 10), insert(&start2, 4, 25); insert(&start2, 7, 25);
	
	
	NODE* node3=reduce(start, start2, reduce_sum);
	printList(node3); // key=1 v1=20 --> key=2 v1=20
	NODE* node4=reduce(start, start2, reduce_max);
	printList(node4);
	
	free(start); free(start2);
	free(node3); free(node4);

	return 0;
}

void printList(NODE *n){
	NODE* tmp= n;
	while(tmp!=NULL){
		printf("v1: %d key: %d\n", tmp->v1, tmp->key);
		tmp=tmp->next;
	}
	printf("\n");
}

NODE* createNode(int key, int v1){
	NODE* newNode=(NODE*)malloc(1*sizeof(NODE));
	newNode->key=key;
	newNode->v1=v1;
	newNode->next=NULL;
	return newNode;
}

void insert(NODE** head, int key, int v1){
	NODE* tmp;
	NODE* newNode=createNode(key, v1);
	// head is null
	if(*head==NULL){
		*head=newNode;
	}
	// head is not null
	else{
		tmp=*head;
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=newNode;
	}
}

int reduce_sum(NODE* node1, NODE* node2){
		return node1->v1+node2->v1;
}

int reduce_max(NODE* node1, NODE* node2){
		if(node1->v1 > node2->v1){
			return node1->v1;
		}
		else{
			return node2->v1;
		}
}

NODE* reduce(NODE* start1, NODE* start2, int(*reduce_f)(NODE*, NODE*)){
	int v1, key, found; 
	NODE* temp1, *temp2; 
	temp1=start1;
	NODE* start3=NULL;
	while(temp1!=NULL){
		found=0;
		temp2=start2;
		while(temp2!=NULL){
			if(temp1->key==temp2->key){
				found=1;
				v1=(*reduce_f)(temp1, temp2);
				key=temp2->key;
				insert(&start3, key, v1);
			}
			temp2=temp2->next;
		}
		if(found==0){
			insert(&start3, temp1->key, temp1->v1);
		}
		temp1=temp1->next;
	}
	return start3;
}

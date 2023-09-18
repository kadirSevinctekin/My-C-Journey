// enroll patients according to prior
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct patient{
	char name[30], surname[30], ID[12];
	int age, prior;
}PATIENT;

typedef struct Patient_Node{
	PATIENT data;
	struct Patient_Node *next;
}PATIENT_NODE;

PATIENT_NODE* createNode(char* name, char* surname, char* id, int age, int prior){
	PATIENT_NODE *newNode=(PATIENT_NODE*)malloc(sizeof(PATIENT_NODE));
	if(newNode==NULL){
		printf("allocation error\n");
	}
	else{
		strcpy(newNode->data.name, name);
		strcpy(newNode->data.surname, surname);
		strcpy(newNode->data.ID, id);
		newNode->data.age=age;
		newNode->data.prior=prior;
		newNode->next=NULL;
	}
	return newNode;	
}

void insertPatient(PATIENT_NODE **head){
	char name[30], surname[30], id[12];
	int age, prior;
	printf("name: "); scanf("%s", name);
	printf("surname: "); scanf("%s", surname);
	printf("ID: "); scanf("%s", id);
	printf("age: "); scanf("%d", &age);
	printf("prior: (1-emergency, 0-normal)"); scanf("%d", &prior);
	PATIENT_NODE *newPatient=createNode(name, surname, id, age, prior);
	PATIENT_NODE *tmp;
	//head control
	if((*head)==NULL){
		*head=newPatient;
	}
	else{
		if(newPatient->data.prior==1){
			if((*head)->data.prior==0){
				newPatient->next=*head;
				*head=newPatient;
			}
			//
			else{
				tmp=*head;
				while(tmp->next->data.prior==1){
					tmp=tmp->next;
				}
				newPatient->next=tmp->next;
				tmp->next=newPatient;									
			}
		}
		else{
			tmp=*head;
			while(tmp->next!=NULL){
				tmp=tmp->next;
			}
			newPatient->next=tmp->next;
			tmp->next=newPatient;
		}
	}
}

void deletePatient(PATIENT_NODE **head){
	if(*head==NULL){
		printf("list is empty. there is no person to delete\n");
	}
	else{
		char id[12];
		printf("enter the id of the patient: "); scanf("%s", id);
		PATIENT_NODE* tmp=*head;
		if(strcmp((*head)->data.ID, id)==0){
			*head=(*head)->next;
			printf("%s %s (%s) is deleted\n", tmp->data.name, tmp->data.surname, tmp->data.ID);
			free(tmp);
		}
		else{
			PATIENT_NODE* tmp2=tmp;
			while(tmp!=NULL && strcmp(tmp->data.ID, id)!=0){
				tmp2=tmp;
				tmp=tmp->next;
			}
			if(tmp==NULL){
				printf("there is no patient record with %s id\n", id);
			}
			else{
				tmp2->next=tmp->next;
				printf("%s %s (%s) is deleted\n", tmp->data.name, tmp->data.surname, tmp->data.ID);
				free(tmp);			
			}
		}
	}
}

void list(PATIENT_NODE* head){
	if(head==NULL){
		printf("list is empty\n");
	}
	else{
		PATIENT_NODE* tmp=head;
		while(tmp!=NULL){
			printf("name: %s surname: %s ID: %s age: %d prior: %d\n", tmp->data.name, tmp->data.surname, tmp->data.ID, tmp->data.age, tmp->data.prior);
			tmp=tmp->next;
		}
	}
}

void freeLL(PATIENT_NODE **head){
	if(head!=NULL){
		PATIENT_NODE* tmp=*head;
		PATIENT_NODE* tmp2;
		while(tmp!=NULL){
			tmp2=tmp;
			tmp=tmp->next;
			free(tmp2);
		}
	}
}

int main() {
    int i, k, cho=1;
    PATIENT_NODE *head=NULL;
    while(cho>0){
    	printf("1-add patient\n2-delete patient\n3-list\n0-exit\n");
    	scanf("%d", &cho);
    	switch(cho){
    		case 1: //add
    			insertPatient(&head);
    		break;
    		case 2: //delete
    			deletePatient(&head);
    		break;
    		case 3: // list
    			list(head);
    		break;
    		case 0: // exit
    		break;
    		default: 
    			printf("wrong choice\n");
    		break;	
		}
	}
	freeLL(&head);
	return 0;
}


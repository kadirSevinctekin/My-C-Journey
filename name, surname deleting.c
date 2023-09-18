#include <stdio.h>
#include <stdlib.h>   
#include <string.h>

typedef struct student{
    char name[20], surname[20];
    int age;
    struct student *next;
}STD;   
  
STD* createRecord(char* name, char* surname, int age){
    STD* newRecord=(STD*)malloc(sizeof(STD));
    strcpy(newRecord->name, name);
    strcpy(newRecord->surname, surname);
    newRecord->age=age;
    newRecord->next=NULL;
    return newRecord;
}   
   
void addStudent(STD** head){
    char name[20], surname[20]; int age;
    printf("enter the name, surname, age\n"); scanf("%s%s%d", name, surname, &age);
    STD* newRecord=createRecord(name, surname, age);
    // add last
    if(*head==NULL){
        *head=newRecord;
    }
    else{
        STD* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newRecord;
    }
}   

void deleteStudent(STD** head){
    if(*head==NULL) {
        printf("there is no person to be delete\n");
    }
    else{
    char name[20], surname[20];
	STD* temp=*head;
   	STD* temp2;
   	printf("enter the name and surname of the person to be delete");
   	scanf("%s%s", name, surname);
    if(strcmp((*head)->name, name)==0 && strcmp((*head)->surname, surname)==0){
        *head=(*head)->next;
        free(temp);
        printf("%s %s was deleted\n", name, surname);
    }
    else{
        while(temp->next!=NULL && (strcmp(temp->next->name, name)!=0 && strcmp(temp->next->surname, surname)!=0)){
            temp=temp->next;
        }
        if(temp->next==NULL){
            printf("%s %s is not  in the list\n", name, surname);
        }
        else{
            temp2=temp->next;
            temp->next=temp->next->next;
            free(temp2);
            printf("%s %s was deleted\n", name, surname);
        }
    }
	}
    
}

void print(STD* head){
    if(head==NULL){
    printf("there is no student to be list\n");
    }
    STD* temp=head;
    while(temp!=NULL){
        printf("%s %s %d\n", temp->name, temp->surname, temp->age);
        temp=temp->next;
    }
}
   
int main() {
    STD* head=NULL;
    int k=0, choice;
    while(k==0){
        printf("choose a option\n1-add student\n2-delete student\n3-list\n4-exit\n"); scanf("%d", &choice);
        switch(choice){
            case 1:
            // add student
            addStudent(&head);
            break;
            case 2:
            // delete student
            deleteStudent(&head);
            break;
            case 3:
            // print list
            print(head);
            break;
            case 4:
            // exit
            k=1;
            break;
            default: 
            printf("wrong choice\n");
            break;
        }
    }

    return 0;
}

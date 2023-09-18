#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bank{
	int balance;
}BANK;

typedef struct customer{
	char *name, *surname;
	int age;
	int ID;
	BANK Bank;
}CUSTOMER;

CUSTOMER* addCustomer(char *, char *, int , int , int);
void addNew(CUSTOMER*** , int *, int *, CUSTOMER* );
void printList(CUSTOMER** , int );
int searchCustomer(CUSTOMER **, int , int );
void deleteCustomer(CUSTOMER **, int *, int  );
void freeCustomer(CUSTOMER *);
void freeDatabase(CUSTOMER** , int );
void deposit(CUSTOMER** , int , int, int);
void withdraw(CUSTOMER** , int , int , int );
int main() {
	int i, j, cho,w=1, age, id, balance, money;
	char name[20], surname[20];
	CUSTOMER* newcustomer;
	CUSTOMER **Database;
	int databaseCount=1, customerCount=0;
	// create database
	Database=(CUSTOMER**)malloc(databaseCount*sizeof(CUSTOMER*));
	
	while(w==1){
		printf("1-for add new customer:\n2-for delete certain customer:\n3-for listing customers:\n4-for search customer:\n5-for deposit money:\n6-for withdraw money:\n7-for quit:\n");
		scanf("%d", &cho);
		switch(cho){
			case 1:
				//add new customer
				printf("enter name: ");
				scanf("%s", name);
				printf("enter surname: ");
				scanf("%s", surname);
				printf("enter age: ");
				scanf("%d", &age);
				printf("enter ID: ");
				scanf("%d", &id);
				printf("enter balance: ");
				scanf("%d", &balance);
			
				newcustomer=addCustomer(name, surname, age, id, balance);
				
				addNew(&Database, &databaseCount, &customerCount, newcustomer);
				
				break;
			case 2:
				// delete customer
				printf("enter ID: ");
				scanf("%d", &id);
				deleteCustomer(Database, &customerCount, id);
				break;
			case 3:
				// list customers
				printList(Database, customerCount);
				break;
			case 4:
				// search customer
				printf("enter ID: ");
				scanf("%d", &id);
				searchCustomer(Database, customerCount, id);
				break;
			case 5:
				// deposit
				printf("enter ID: ");
				scanf("%d", &id);
				printf("enter the deposit: ");
				scanf("%d", &money);
				deposit(Database, customerCount, id, money);
				break;
			case 6:
				// withdraw
				printf("enter ID: ");
				scanf("%d", &id);
				printf("enter the deposit: ");
				scanf("%d", &money);
				withdraw(Database, customerCount, id, money);
			break;
			case 7:
				// quit
				w=2;
				break;
			default:
				printf("wrong choice\n");	
									
		}
	}
	freeDatabase(Database, customerCount);
	return 0;
}

CUSTOMER* addCustomer(char *Name, char *Surname, int Age, int id, int Balance){
	CUSTOMER *newCustomer=(CUSTOMER*)malloc(1*sizeof(CUSTOMER));
	newCustomer->name=(char*)malloc((strlen(Name)+1)*sizeof(char));
	strcpy(newCustomer->name, Name);
	newCustomer->surname=(char*)malloc((strlen(Surname)+1)*sizeof(char));
	strcpy(newCustomer->surname, Surname);
	newCustomer->age=Age;
	newCustomer->ID=id;
	newCustomer->Bank.balance=Balance;
	return newCustomer;
	
}

void addNew(CUSTOMER*** Database, int *databaseCount, int *customerCount, CUSTOMER* newCustomer){
	(*Database)[(*customerCount)++]=newCustomer;
	if(*customerCount==*databaseCount){
		*databaseCount*=2;
		(*Database)=(CUSTOMER**)realloc(*Database, (*databaseCount)*sizeof(CUSTOMER*));
	}
}

void printList(CUSTOMER** Database, int customerCount){
	int i;
	for(i=0;i<customerCount;i++){
		printf("Name: %s Surname: %s Age: %d ID: %d Balance: %d\n", Database[i]->name, Database[i]->surname, Database[i]->age, Database[i]->ID, Database[i]->Bank.balance);
	}
}

int searchCustomer(CUSTOMER **Database, int customerCount, int ID){
	int i;
	for(i=0;i<customerCount;i++){
		if(Database[i]->ID==ID){
			printf("Customer Found\n");
			printf("Name: %s Surname: %s Age: %d ID: %d Balance: %d\n", Database[i]->name, Database[i]->surname, Database[i]->age, Database[i]->ID, Database[i]->Bank.balance);
			return i;
		}
	}
	printf("Customer not found\n");
	return -1;
}

void deleteCustomer(CUSTOMER **Database, int *customerCount, int ID ){
	int customerPosition=searchCustomer(Database, *customerCount, ID);
	if(customerPosition==-1){
		printf("Customer not found\n");
		return;
	}
	Database[customerPosition]=Database[(*customerCount)-1];
	freeCustomer(Database[(*customerCount)-1]);
	(*customerCount)--;
}

void freeCustomer(CUSTOMER *customer){
	free(customer->name);
	free(customer->surname);
	free(customer);
}

void freeDatabase(CUSTOMER** Database, int customerCount){
	int i;
	for(i=0;i<customerCount;i++){
		freeCustomer(Database[i]);
	}
	free(Database);
}

void deposit(CUSTOMER** Database, int customerCount, int ID, int money){
	int customerPosition=searchCustomer(Database, customerCount, ID);
	Database[customerPosition]->Bank.balance+=money;
}

void withdraw(CUSTOMER** Database, int customerCount, int ID, int money){
	int customerPosition=searchCustomer(Database, customerCount, ID);
	Database[customerPosition]->Bank.balance-=money;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account
{
	char cin[8];
	char lname[100];
	char fname[100];
	float amount;
};

// functions signitures
// void populateAccounts(struct account *, int);
void populateAccounts(struct account *, int);
void printAccounts(struct account *, int);
void printfMenu();

int main()
{

	// srand(time(0));
	struct account *accounts;
	int size = 4, menu = 1;
	accounts = (struct account *)malloc(size * sizeof(struct account));
	for (int i = 0; i < size; i++)
	{
		sprintf(accounts[i].cin, "cin%d", i + 1);
		sprintf(accounts[i].lname, "lname%d", i + 1);
		sprintf(accounts[i].fname, "fname%d", i + 1);
		accounts[i].amount = rand() * 0.0001;
	}
	while (menu != 0)
	{
		printfMenu();
		scanf("%d", &menu);
		if (menu == 1)
		{
			system("clear");
			//system("cls");
			printf("\nadd 1 account process\n");
		}
		else if (menu == 2)
		{
			system("clear");
			//system("cls");
			printf("\nadd multiple accounts process\n");
		}
		else if (menu == 3)
		{
			system("clear");
			//system("cls");
			printf("\noperations on accounts process\n");
		}
		else if (menu == 4)
		{
			system("clear");
			//system("cls");
			printAccounts(accounts, size);
		}
		else if (menu == 5)
		{
			system("clear");
			//system("cls");
			printf("\nloyalty process\n");
		}
		else if (menu == 0)
		{

			system("clear");
			//system("cls");
			printf("\nquitting program\n");
		}
		else
		{
			system("clear");
			//system("cls");
			printf("\nchoose a number showing on the screen (0 to quite)\n");
		}
	}
	// printf("enter size : ");
	// scanf("%d", &size);
	// accounts = (struct account *)malloc(size * sizeof(struct account));
	// populateAccounts(accounts, size);
	// printAccounts(accounts, size);
}

void populateAccounts(struct account *accounts, int size)
{
	for (int i = 0; i < size; i++)
	{
		// char *cin;
		printf("\n** Account %d **\n", i + 1);
		printf("enter cin : ");
		scanf("%s", accounts[i].cin);
		printf("enter last name : ");
		scanf("%s", accounts[i].lname);
		printf("enter first name : ");
		scanf("%s", accounts[i].fname);
		printf("enter amount : ");
		scanf("%f", &accounts[i].amount);
		// strcpy(accounts[i].cin, cin);
	}
}
void printAccounts(struct account *accounts, int size)
{
	printf("\n**** Accounts ****\n");
	for (int i = 0; i < size; i++)
	{
		// printf("%s\n", accounts[i].cin);
		printf("%s\t%s\t%s\t%f\n", accounts[i].cin, accounts[i].lname, accounts[i].fname, accounts[i].amount);
	}
}

void printfMenu()
{
	printf("\n** menu **\n");
	printf("1 --> add 1 account\n");
	printf("2 --> add multiple accounts\n");
	printf("3 --> operations on accounts\n");
	printf("4 --> show accounts\n");
	printf("5 --> loyalty\n");
	printf("0 --> add 1 account\n");
}
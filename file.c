#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct account
{
	char cin[8];
	char lname[100];
	char fname[100];
	float amount;
};
struct transaction
{
	// struct account *account;
	char cin[8];
	float amount;
};

// functions signitures
// void populateAccounts(struct account *, int);
void printfMenu();
void populateAccounts(struct account *, int *, int, struct transaction *, int *);
void printAccounts(struct account *, int, int);
void printMenuShow();
void ascendingSort(struct account *, int, int);
void descendingSort(struct account *, int, int);
int lookUpWithCin(struct account *, int, char *);
void loyalty(struct account *, int, float);
void deposit(struct account *, float, int);
void withdraw(struct account *, float, int);
void printTransactions(struct transaction *, int);
void addTransaction(struct transaction *, char *, int *, float);
void writeFiles(struct account *, int, struct transaction *, int);

int main()
{
	srand(time(NULL));
	struct account *accounts;
	struct transaction *transactions;
	int size = 4, menu = 1, transCount = size;
	float loyaltyPourc = 0.013;
	accounts = (struct account *)malloc(size * sizeof(struct account));
	transactions = malloc(transCount * sizeof(struct transaction));
	for (int i = 0; i < size; i++)
	{
		sprintf(accounts[i].cin, "cin%d", i + 1);
		sprintf(accounts[i].lname, "lname%d", i + 1);
		sprintf(accounts[i].fname, "fname%d", i + 1);
		accounts[i].amount = rand() /** 0.0001*/;
		// transactions[i].account = &accounts[i];
		strcpy(transactions[i].cin, accounts[i].cin);
		transactions[i].amount = accounts[i].amount;
	}
	while (menu != 0)
	{
		printfMenu();
		printf("your choice : ");
		scanf("%d", &menu);
		if (menu == 1)
		{
			system("clear");
			//system("cls");
			printf("\nadd 1 account process\n");
			populateAccounts(accounts, &size, 1, transactions, &transCount);
		}
		else if (menu == 2)
		{
			int newSize;
			system("clear");
			//system("cls");
			printf("\nadd multiple aucounts process\n");
			printf("\nenter the number of accounts to add :");
			scanf("%d", &newSize);
			populateAccounts(accounts, &size, newSize, transactions, &transCount);
		}
		else if (menu == 3)
		{
			int choice = -1;
			system("clear");
			//system("cls");
			printf("\noperations on accounts process\n");
			while (choice < 0 || choice > 2)
			{
				printf("\n** menu **\n");
				printf("1 --> deposit\n");
				printf("2 --> witdraw\n");
				printf("0 --> quite\n");
				printf("your choice : ");
				scanf("%d", &choice);
				switch (choice)
				{
					int idx;
					float amount;
					char cin[8];
				case 1:
					system("clear");
					//system("cls");
					printf("\ndeposit process\n");
					printf("\nenter cin : ");
					scanf("%s", cin);
					idx = lookUpWithCin(accounts, size, cin);
					if (idx == -1)
					{
						printf("\naccount doesn't exist\n");
						break;
					}
					else
					{
						printf("%s\t%s\t%s\t%f\n", accounts[idx].cin, accounts[idx].lname, accounts[idx].fname, accounts[idx].amount);
						printf("\nenter an amount to deposit\n");
						scanf("%f", &amount);
						deposit(accounts, amount, idx);
						addTransaction(transactions, accounts[idx].cin, &transCount, amount);
					}
					break;
				case 2:
					system("clear");
					//system("cls");
					printf("\nwithdraw porcess\n");
					printf("\nenter cin : ");
					scanf("%s", cin);
					idx = lookUpWithCin(accounts, size, cin);
					if (idx == -1)
					{
						printf("\naccount doesn't exist\n");
						break;
					}
					else
					{
						printf("%s\t%s\t%s\t%f\n", accounts[idx].cin, accounts[idx].lname, accounts[idx].fname, accounts[idx].amount);
						printf("\nenter an amount to withdraw\n");
						scanf("%f", &amount);
						withdraw(accounts, amount, idx);
						addTransaction(transactions, accounts[idx].cin, &transCount, amount * -1);
					}
					break;

				default:
					break;
				}
			}
		}
		else if (menu == 4)
		{
			int choice = -1, min = -1;
			system("clear");
			//system("cls");
			while (choice < 0 || choice > 5)
			{
				printMenuShow();
				printf("your choice : ");
				scanf("%d", &choice);
				switch (choice)
				{
				case 0:
					system("clear");
					//system("cls");
					printf("\nback to the main menu\n");
					break;

				case 1:
					system("clear");
					//system("cls");
					printf("ascending process\n");
					ascendingSort(accounts, size, min);
					break;
				case 2:
					system("clear");
					//system("cls");
					printf("descending process\n");
					descendingSort(accounts, size, min);
					break;
				case 3:
					system("clear");
					//system("cls");
					printf("ascending process 2\n");
					printf("\nenter minimum (higher than 0) : ");
					scanf("%d", &min);
					ascendingSort(accounts, size, min);
					break;
				case 4:
					system("clear");
					//system("cls");
					printf("descending process 2\n");
					printf("\nenter minimum (0 or higher) : ");
					scanf("%d", &min);
					if (min >= 0)
						descendingSort(accounts, size, min);
					else
						printf("minimum should be higher than 0!!!");
					break;
				case 5:
					system("clear");
					//system("cls");
					printf("look up process\n");
					char cin[8];
					printf("enter cin to look up : ");
					scanf("%s", cin);
					int idx = lookUpWithCin(accounts, size, cin);
					// printf("idx = %d", idx);
					if (idx != -1)
						printf("%s\t%s\t%s\t%f\n", accounts[idx].cin, accounts[idx].lname, accounts[idx].fname, accounts[idx].amount);
					else
						printf("\naccount doesn't exist\n");
					break;
				default:
					system("clear");
					//system("cls");
					printf("\nchoose a number showing on the screen (0 to quite)\n");
					break;
				}
			}
			// printAccounts(accounts, size);
		}
		else if (menu == 5)
		{
			system("clear");
			//system("cls");
			printf("\nloyalty process\n");
			loyalty(accounts, size, loyaltyPourc);
		}
		else if (menu == 6)
		{
			system("clear");
			//system("cls");
			printTransactions(transactions, transCount);
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
	writeFiles(accounts, size, transactions, transCount);
	free(transactions);
	free(accounts);
}

void populateAccounts(struct account *accounts, int *size, int newSize, struct transaction *transactions, int *transCount)
{
	accounts = (struct account *)realloc(accounts, ((*size) + newSize) * sizeof(struct account));
	for (int i = *size; i < (*size) + newSize; i++)
	{
		char cin[8];
		printf("\n** Account %d **\n", i + 1);
		printf("enter cin : ");
		scanf("%s", cin);
		if (lookUpWithCin(accounts, (*size) + newSize, cin) == -1)
		{
			strcpy(accounts[i].cin, cin);
			// scanf("%s", accounts[i].cin);
			printf("enter last name : ");
			scanf("%s", accounts[i].lname);
			printf("enter first name : ");
			scanf("%s", accounts[i].fname);
			printf("enter amount : ");
			scanf("%f", &accounts[i].amount);
			addTransaction(transactions, cin, transCount, accounts[i].amount);
		}
		else
		{
			printf("\ncin already exists!!\n");
			i--;
		}
	}
	*size += newSize;
	printAccounts(accounts, *size, -1);
}
void printAccounts(struct account *accounts, int size, int min)
{
	printf("\n**** Accounts ****\n");
	for (int i = 0; i < size; i++)
	{
		// printf("%s\n", accounts[i].cin);
		if (accounts[i].amount > min)
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
	printf("6 --> transactions\n");
	printf("0 --> quite\n");
}

void printMenuShow()
{
	printf("\n** menu **\n");
	printf("1 --> ascending order\n");
	printf("2 --> descending order\n");
	printf("3 --> ascending order (having balance greater than given amount)\n");
	printf("4 --> descending order (having balance greater than given amount)\n");
	printf("5 --> look up with CIN\n");
	printf("0 --> quite\n");
}
void ascendingSort(struct account *accounts, int size, int min)
{
	for (int i = 0; i < size - 1; i++)
	{
		int idx = i;
		for (int j = i + 1; j < size; j++)
		{
			if (accounts[j].amount < accounts[idx].amount)
				idx = j;
		}
		if (idx != i)
		{
			struct account tmp = accounts[i];
			accounts[i] = accounts[idx];
			accounts[idx] = tmp;
		}
	}
	printAccounts(accounts, size, min);
}

void descendingSort(struct account *accounts, int size, int min)
{
	for (int i = 0; i < size - 1; i++)
	{
		int idx = i;
		for (int j = i + 1; j < size; j++)
		{
			if (accounts[j].amount > accounts[idx].amount)
				idx = j;
		}
		if (idx != i)
		{
			struct account tmp = accounts[i];
			accounts[i] = accounts[idx];
			accounts[idx] = tmp;
		}
	}
	printAccounts(accounts, size, min);
}
int lookUpWithCin(struct account *accounts, int size, char *cin)
{
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(accounts[i].cin, cin))
			return i;
	}
	return -1;
}
void loyalty(struct account *accounts, int size, float pourc)
{
	descendingSort(accounts, size, -1);
	system("clear");
	//system("cls");
	for (int i = 0; i < 3; i++)
	{
		accounts[i].amount += (accounts[i].amount * pourc);
		// accounts[i].amount = accounts[i].amount + accounts[i].amount * pourc;
	}
	printAccounts(accounts, size, -1);
}
void deposit(struct account *accounts, float amount, int idx)
{
	accounts[idx].amount += amount;
	printf("%s\t%s\t%s\t%f\n", accounts[idx].cin, accounts[idx].lname, accounts[idx].fname, accounts[idx].amount);
}
void withdraw(struct account *accounts, float amount, int idx)
{
	if (accounts[idx].amount < amount)
	{
		printf("\ntransaction can't be done, available balance is les than the amount you want to withdraw!!\n");
		return;
	}
	else
	{
		accounts[idx].amount -= amount;
		printf("%s\t%s\t%s\t%f\n", accounts[idx].cin, accounts[idx].lname, accounts[idx].fname, accounts[idx].amount);
	}
}

void printTransactions(struct transaction *transactions, int transCount)
{
	printf("cin\tamount\n");
	printf("------------------\n");
	for (int i = 0; i < transCount; i++)
	{
		printf("%s\t%f\n", transactions[i].cin, transactions[i].amount);
	}
}
void addTransaction(struct transaction *transactions, char *cin, int *transCount, float amount)
{
	// printf("\ntransCount = %d\n", *transCount);
	transactions = realloc(transactions, ((*transCount) + 1) * sizeof(struct transaction));
	strcpy(transactions[*transCount].cin, cin);
	transactions[*transCount].amount = amount;
	*transCount += 1;
	// printf("\ntransCount = %d\n", *transCount);
	// printTransactions(transactions, *transCount);
}

void writeFiles(struct account *accounts, int accountsSize, struct transaction *transactions, int transSize)
{
	FILE *file;

	file = fopen("accounts.txt", "w");
	for (int i = 0; i < accountsSize; i++)
	{
		fprintf(file, "%s %s %s %f\n", accounts[i].cin, accounts[i].lname, accounts[i].fname, accounts[i].amount);
	}
	fclose(file);
	file = fopen("transactions.txt", "w");
	for (int i = 0; i < transSize; i++)
	{
		fprintf(file, "%s %f\n", transactions[i].cin, transactions[i].amount);
	}
	fclose(file);
}
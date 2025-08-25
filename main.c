#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account
{
    char name[50];
    int accNumber;
    int PIN;
    float Deposit;
};
int main()
{
    int choice;
    system("cls");
    printf("==========================================\n");
    printf("                 MEIN MENU                \n");
    printf("==========================================\n");
    printf("1.Create Account\n");
    printf("1.Login (Existing User)\n");
    printf("1.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        RegisterAccount();
        LoginAccount();
    }
    else if (choice == 2)
    {
        LoginAccount();
    }

    else if (choice == 3)
    {
        printf("Thank you for using ATM. Goodbye!\n");
        exit(0);
    }
    else
    {
        printf("Invalid choice. Returning to Main Menu...\n");
        system("pause");
    }
    return 0;
}
void RegisterAccount()
{
    struct Account p1;
    FILE *fp;

    system("cls");
    printf("==========================================\n");
    printf("           ATM Account Registration              \n");
    printf("==========================================\n");
    do
    {
        printf("Enter your name: ");
        scanf("%s", p1.name);
        if (strlen(p1.name) == 0)
        {
            printf("Name can not be empty! try again.\n");
        }

    } while (strlen(p1.name) == 0);
    do
    {
        printf("Enter Account Number: ");
        scanf("%d", &p1.accNumber);
        if (p1.accNumber <= 0)
        {
            printf("Invalid account number! Try again.\n");
        }

    } while (p1.accNumber <= 0);

    do
    {
        printf("Set a 4-digit PIN: ");
        scanf("%d", &p1.PIN);
        if (p1.PIN < 1000 || p1.PIN > 9999)
        {
            printf("Invalid PIN!\n");
        }

    } while (p1.PIN < 1000 || p1.PIN > 9999);
    do
    {
        printf("Enter Initial Deposit: ");
        scanf("%f", &p1.Deposit);
        if (p1.Deposit < 1000)
        {
            printf("Minimum deposit shoud be 1000.\n");
        }

    } while (p1.Deposit < 1000);
    fp = fp = fopen("C:\\ATM_project\\Account.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "%d,%s,%d,%.2f,\n", p1.accNumber, p1.name, p1.PIN, p1.Deposit);
    fclose(fp);
    printf("Account Number: %d\n", p1.accNumber);
    printf("Name: %s\n", p1.name);
    printf("Set PIN: %d\n", p1.PIN);
    printf("Initial Deposit: %2.f\n", p1.Deposit);
    system("cls");
}
void LoginAccount()
{
    struct Account p1;
    FILE *fp;
    int accNo, Pin;
    int found = 0;

    system("cls");
    printf("==========================================\n");
    printf("                   LOGIN                  \n");
    printf("==========================================\n");
    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter a PIN: ");
    scanf("%d", &Pin);

    fp = fopen("C:\\ATM_project\\Account.txt", "r");
    if (fp == NULL)
    {
        printf("NO account found! please rigister first.\n");
        return;
    }

    while (fscanf(fp, "%d,%s,%d,%f,\n", &p1.accNumber, p1.name, &p1.PIN, &p1.Deposit) == 4)
    {
        if (p1.accNumber == accNo && p1.PIN == Pin)
        {
            found = 1;
            printf("\nlogin Successful!\n");
            printf("\nWelcome, %s\n", p1.name);
            printf("Your Balance: %.2f\n", p1.Deposit);
            fclose(fp);
            system("pause");
            ATMmenu(p1);
        }
    }
    fclose(fp);
    if (!found)
    {
        printf("Invalid Account Number or PIN!\n");
        system("pause");
    }
}
void ATMmenu()
{
}

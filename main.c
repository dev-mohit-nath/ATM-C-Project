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
void RegisterAccount();
void LoginAccount();
void ATMmenu(struct Account user);
void updateBalance(struct Account user);
int main()
{
    int choice;
    system("cls");
    printf("==========================================\n");
    printf("                 MEIN MENU                \n");
    printf("==========================================\n");
    printf("[1] Create Account\n");
    printf("[2] Login (Existing User)\n");
    printf("[3] Exit\n");
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
    struct Account user;
    FILE *fp;

    system("cls");
    printf("==========================================\n");
    printf("           ATM Account Registration              \n");
    printf("==========================================\n");
    do
    {
        printf("Enter your name: ");
        scanf(" %[^\n]", user.name);
        if (strlen(user.name) == 0)
        {
            printf("Name can not be empty! try again.\n");
        }

    } while (strlen(user.name) == 0);
    do
    {
        printf("Enter Account Number: ");
        scanf("%d", &user.accNumber);
        if (user.accNumber <= 0)
        {
            printf("Invalid account number! Try again.\n");
        }

    } while (user.accNumber <= 0);

    do
    {
        printf("Set a 4-digit PIN: ");
        scanf("%d", &user.PIN);
        if (user.PIN < 1000 || user.PIN > 9999)
        {
            printf("Invalid PIN!\n");
        }

    } while (user.PIN < 1000 || user.PIN > 9999);
    do
    {
        printf("Enter Initial Deposit: ");
        scanf("%f", &user.Deposit);
        if (user.Deposit < 1000)
        {
            printf("Minimum deposit shoud be 1000.\n");
        }

    } while (user.Deposit < 1000);
    fp = fopen("Account.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "%d,%s,%d,%.2f\n", user.accNumber, user.name, user.PIN, user.Deposit);
    fclose(fp);
    printf("Account Number: %d\n", user.accNumber);
    printf("Name: %s\n", user.name);
    printf("Set PIN: %d\n", user.PIN);
    printf("Initial Deposit: %.2f\n", user.Deposit);
    system("cls");
}
void LoginAccount()
{
    struct Account user;
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

    fp = fopen("Account.txt", "r");
    if (fp == NULL)
    {
        printf("NO account found! please rigister first.\n");
        return;
    }

    while (fscanf(fp, "%d,%49[^,],%d,%f",
                  &user.accNumber, user.name, &user.PIN, &user.Deposit) == 4)
    {
        if (user.accNumber == accNo && user.PIN == Pin)
        {
            found = 1;
            printf("\nlogin Successful!\n");
            printf("\nWelcome, %s\n", user.name);
            printf("Your Balance: %.2f\n", user.Deposit);
            fclose(fp);
            system("pause");
            ATMmenu(user);
            return;
        }
    }
    fclose(fp);
    if (!found)
    {
        printf("Invalid Account Number or PIN!\n");
        system("pause");
    }
}

void ATMmenu(struct Account user)
{
    int choice;
    float amount;

    while (1)
    {
        system("cls");
        printf("==========================================\n");
        printf("              ATM Main Menu               \n");
        printf("==========================================\n");
        printf("Welcome, %s\n", user.name);
        printf("[1] check balance\n");
        printf("[2] Deposite Money\n");
        printf("[3] withdraw Money\n");
        printf("[4] logout\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            FILE *fp = fopen("Account.txt", "r");
            struct Account acc;
            if (fp == NULL)
            {
                printf("Error opening file!\n");
                system("pause");
                break;
            }
            int found = 0;
            while (fscanf(fp, "%d,%49[^,],%d,%f", &acc.accNumber, acc.name, &acc.PIN, &acc.Deposit) == 4)
            {
                if (acc.accNumber == user.accNumber)
                {
                    printf("Your balance: %.2f\n", acc.Deposit);
                    found = 1;
                    break;
                }
            }
            fclose(fp);

            if (!found)
            {
                printf("Account not found!\n");
            }

            system("pause");
            break;
        }
        case 2:
            printf("Enter Deposit Amount: ");
            scanf("%f", &amount);
            if (amount > 0)
            {
                user.Deposit += amount;
                updateBalance(user);
                printf("Deposited %.2f successfully!\n", amount);
            }
            else
            {
                printf("Invalid Amount!\n");
            }
            system("pause");
            break;
        case 3:
            printf("Enter withdraw amount: ");
            scanf("%f", &amount);
            if (amount > 0 && amount <= user.Deposit)
            {
                user.Deposit -= amount;
                updateBalance(user);
                printf("withdraw %.2f successfully!\n", amount);
            }
            else
            {
                printf("Insufficient balance or Invalid ammount!\n");
            }
            system("pause");
            break;
        case 4:
            printf("Loggin out....");
            system("pause");
            main();
            return;
        default:
            printf("invalid choice!\n");
            system("pause");
            break;
        }
    }
}
void updateBalance(struct Account user)
{
    FILE *fp, *temp;
    struct Account acc;

    fp = fopen("Account.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("File error!\n");
        return;
    }
    while (fscanf(fp, "%d,%49[^,],%d,%f", &acc.accNumber, acc.name, &acc.PIN, &acc.Deposit) == 4)
    {
        if (acc.accNumber == user.accNumber)
        {
            fprintf(temp, "%d,%s,%d,%.2f\n", user.accNumber, user.name, user.PIN, user.Deposit);
        }
        else
        {
            fprintf(temp, "%d,%s,%d,%.2f\n", acc.accNumber, acc.name, acc.PIN, acc.Deposit);
        }
    }
    fclose(fp);
    fclose(temp);

    remove("Account.txt");
    rename("temp.txt", "Account.txt");
}

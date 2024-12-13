#include <stdio.h>
#include <conio.h> //for getch()
#include <string.h> //for strcmp()
struct atm
{
    float balance;  // Initial balance
    float amount; //final amount
    char minista[1000];
}t;

int main()
{
    int choice,i; //choice is for selection, i is for array
    char pin[4]; //array for pin code
    FILE *fp;
    FILE *ep=fopen("balance.dat","r");
    fscanf(ep,"%f",&t.balance);
    fclose(ep);

    while (1) //for continious process
    {
        printf("\nWelcome to the ATM!\n"); //for information
        printf("1. Check balance\n");
        printf("2. Withdraw money\n");
        printf("3. Deposit money\n");
        printf("4. Mini Statement\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); //for choice in switch statement
        switch (choice)
        {
            case 1:
            printf("Enter your PIN code: ");
            for (i = 0; i < 4; i++)
            {
                pin[i] = getch();  // Read a character from the keyboard without echoing it
                printf("*");
            }
            pin[4] = '\0';  // Add a null character to the end of the string
            if (strcmp(pin, "1234") == 0)
            {
                printf("\nYour balance is: Rs.%.2f\n", t.balance);
                getch();
            }
            else  // Incorrect PIN code
            {
                printf("\nIncorrect PIN code!\n");
                getch();
            }
            break;

            case 2:
            printf("Enter your PIN code: ");
            for (i = 0; i < 4; i++)
            {
                pin[i] = getch();  // Read a character from the keyboard without echoing it
                printf("*");
            }
            pin[4] = '\0';  // Add a null character to the end of the string

            if (strcmp(pin, "1234") == 0)
            {
                if (t.amount > t.balance)
                {
                    printf("Insufficient balance!\n");
                    getch();
                    return 0;
                }
                else
                {
                    printf("\nEnter the amount to withdraw: ");
                    scanf("%f", &t.amount);
                    t.balance -= t.amount; 
                    printf("Withdrew Rs.%.2f.\n", t.amount);
                    ep=fopen("balance.dat","w");
                    fp = fopen ( "mini.dat", "a" );
                    fprintf(fp,"Withdrew Rs.%.2f.\n", t.amount);
                    fprintf(ep,"%f", t.balance);
                    fclose(ep);
                    fclose(fp);
                    getch();
                }
            }
            else  // Incorrect PIN code
            {
                printf("\nIncorrect PIN code!\n");
                getch();
            }
            break;

            case 3:
            printf("Enter your PIN code: ");
            for (i = 0; i < 4; i++)
            {
                pin[i] = getch();  // Read a character from the keyboard without echoing it
                printf("*");
            }
            pin[4] = '\0';  // Add a null character to the end of the string

            if (strcmp(pin, "1234") == 0)
            {
                printf("\nEnter the amount to deposit: ");
                scanf("%f", &t.amount);
                t.balance += t.amount;
                printf("Deposited Rs.%.2f.\n", t.amount);
                ep=fopen("balance.dat","w");
                fp = fopen ( "mini.dat", "a" );
                fprintf(fp,"Deposited Rs.%.2f.\n", t.amount);
                fprintf(ep,"%f", t.balance);
                fclose(ep);
                fclose(fp);
                getch();
            }
            else  // Incorrect PIN code
            {
                printf("\nIncorrect PIN code!\n");
                getch();
            }
            break;

            case 4:
            fp = fopen ( "mini.dat", "r" );
            printf("Enter your PIN code: ");
            for (i = 0; i < 4; i++)
            {
                pin[i] = getch();  // Read a character from the keyboard without echoing it
                printf("*");
            }
            printf("\n");
            pin[4] = '\0';  // Add a null character to the end of the string
            if (strcmp(pin, "1234") == 0)
            {
                while (fgets(t.minista, 1000, fp) != NULL)
                {
                    printf("%s", t.minista);
                }
            }
            getch();

            fclose(fp);
            break;

            case 5:
            printf("Thank you for using the ATM. Goodbye!\n");
            getch();
            return 0;
            break;
            
            default:
            printf("Invalid choice!\n");
            getch();
            break;
        }
    }
}

#include <stdio.h>
#include <math.h>
#include <string.h>
int choice=0;
char ans=0;
void DWARF();
void PERFECT_ABUNDANT_DEFICIENT();
void FIBO();


int main(){
    char Pass[10];
    int guessCount=0;
    int guessLimit=3;
    int outOfGuesses=0;

    printf("\nLogin to the program\n\n");

    while (!strcmp(Pass,"BSCS11N")==0 && outOfGuesses==0)
    {
        if (guessCount<guessLimit)
        {
            printf("Enter Password: ");
            scanf("%s", Pass);
            guessCount++;
        }
        else
        {
            outOfGuesses=1;
        }
        
    }
    if(outOfGuesses==1){
        printf("\nAccess Denied!");
        return 0;

    }
    else
    {
        printf("\nYou are logged in");
    }


    do{
    printf("\n\n=========================================");
    printf("\nWELCOME TO THE GENERAL PROGRAM!");
    printf("\n=========================================");

    printf("\n\nChoose your cup of tea: ");

    printf("\n\n----------------------------------------------------");
    printf("\n1. DWARF NUMBER\n2. PERFECT, ABUNDANT, DEFICIENT\n3. FIBONACCI RABBIT\n");
    printf("----------------------------------------------------");

    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice){
        case 1:
            DWARF();
            break;
        case 2:
            PERFECT_ABUNDANT_DEFICIENT();
            break;
        case 3:
            FIBO();
            break;
        default:
            printf("Invalid choice");
            break;
    }
    printf("\n\nDo you like to continue? (y/n): ");
    scanf(" %c", &ans);
    }while (ans=='y' || ans=='Y');

    printf("\nThank you for using the program!");
}


void DWARF(){
    float num;
    float sum=0;
    float half=0;
        printf("\n--------------------------");
        printf("\nThe DWARF Program");
        printf("\n--------------------------\n\n");
        do
        {
            printf("Enter a non-negative number: ");
            scanf("%f", &num);

        }while (num<0);
        printf("\nThe factors are: ");
    for (int i = 1; i < num; ++i)
    {
        if (fmod(num,i) ==0){
            printf("%d  ", i);
            sum += i;
        }
    }
        printf("\nSum of its factors: %.2f", sum);

        half = num/2;
        printf("\nHalf of number: %.2f/2 = %.2f", num, half);

    if (sum>half){
        printf("\n\n%.2f is DWARF NUMBER", num);
    }

    else{
        printf("\n\n%.2f is NOT DWARF NUMBER", num);
    }

}


void PERFECT_ABUNDANT_DEFICIENT (){
    int num;
    int sum=0;
        printf("\n----------------------------------------------------");
        printf("\nThe PERFECT, ABUNDANT, DEFICIENT Program");
        printf("\n----------------------------------------------------\n\n");
        do
         {
        printf("Enter a non-negative number: ");
        scanf("%d", &num);
         } while (num<0);
         printf("The Proper divisors are: ");
            for (int i = 1; i < num; ++i)
            {
                if (num % i==0){
                printf("%d  ", i);
                 sum += i;
                }
            }
             printf("\nSum of its factors: %d", sum);


            if (sum<num){
            printf("\n\n%d < %d is DEFICIENT", sum, num);
            }

            else if (sum==num){
            printf("\n\n%d = %d is PERFECT", sum, num);
             }

            else{
            printf("\n\n%d > %d is ABUNDANT", sum, num);
            }
}


void FIBO(){
    int rabbit[12], r1, r2, total=0;
    printf("\n-------------------------------------");
    printf("\nThe FIBONACCI RABBIT Program");
    printf("\n-------------------------------------");

    printf("\n\nMonths \tRabbits ");
    for (int i = 1; i < 13; ++i)
    {
        if (i==1){
            rabbit[i] = 1;
            printf("\n%d \t=%d", i, rabbit[i]);
        }
        else if (i==2){
            rabbit[i] = 1;
            printf("\n%d \t=%d", i, rabbit[i]);
        }
        else{
            r1 = rabbit[i-1];
            r2 = rabbit[i-2];
            rabbit[i] = rabbit[i-1] + rabbit[i-2];
            printf("\n%d \t=%d", i, rabbit[i]);
        }
        total += rabbit[i];
    }
    printf("\n\nTotal number of rabbits after 12 months is %d", total);
}




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main (void){
    srand(time(NULL));

    int playerChoice=0;
    int computerChoice=0;
    int win=0;
    int lose=0;

    bool draw= false;

    char ans, ans2;



        printf("\n---------------------------------------------");
        printf("\nWELCOME TO ROCK PAPER SCISSORS GAME!");
        printf("\n---------------------------------------------");

        printf("\n\nlaro ka teh? (y/n): ");
        scanf(" %c", &ans2);
        if (ans2 == 'n' || ans2 == 'N')
        {
            printf("\n\nOkay... di ka kawalan!");
            return 0;
        }
        else{
            printf("\n\nLets G!"); 
        }    
        do
        {
            do
            {
                do
                {
                
                    printf("\n\nChoose your tea bading: \n\n");
                    printf("1. Rock\n2. Paper\n3. Scissors\n\n");
                    printf("Enter your choice: ");
                    scanf("%d", &playerChoice);
                }while (playerChoice < ROCK || playerChoice > SCISSORS);

                computerChoice= (rand() % 3) + 1;

                if (computerChoice == ROCK)
                {
                    printf("\n\nComputer throw ROCK.");
                }
                else if (computerChoice == PAPER)
                {
                    printf("\n\nComputer throw PAPER.");
                }
                else if (computerChoice == SCISSORS)
                {
                    printf("\n\nComputer throw SCISSORS.");
                }

                draw= false;

                if (playerChoice == ROCK && computerChoice == SCISSORS)
                {
                    printf("\nROCK beats SCISSORS. YOU WIN! Galing yarn?");
                    win++;
                }
                else if (playerChoice == ROCK && computerChoice == PAPER)
                {
                    printf("\nPAPER beats ROCK. YOU LOSE! Tanga!");
                    lose++;
                }
                else if (playerChoice == SCISSORS && computerChoice == PAPER)
                {
                    printf("\nSCISSORS beats PAPER. YOU WIN! Galing yarn?");
                    win++;
                }
                else if (playerChoice == SCISSORS && computerChoice == ROCK)
                {
                    printf("\nROCK beats SCISSORS. YOU LOSE! Tanga!");
                    lose++;
                }
                else if (playerChoice == PAPER && computerChoice == ROCK)
                {
                    printf("\nPAPER beats ROCK. YOU WIN! Galing yarn?");
                    win++;
                }
                else if (playerChoice == PAPER && computerChoice == SCISSORS)
                {
                    printf("\nSCISSORS beats PAPER. YOU LOSE! Tanga!");
                    lose++;
                }
                else
                {
                    printf("\nDRAW! PLAY AGAIN!");
                    draw= true;
                }
            } while (draw);

            printf("\nYou won %d times and lost %d times.\n", win, lose);
            printf("\n\nGusto mo pa mag-laro teh? (y/n): ");
            scanf(" %c", &ans);
        } while (ans == 'y' || ans == 'Y');

        if (win > lose)
        {
            printf("\n\nCongrats! Panalo si bading!");
        }
        else
        {
            printf("\n\nMy gadh talo si accla! Ang bobo mo naman.");
        }

        printf("\n\nBalk ka ulit.. ems.. bye!");
    
}
//
// Created by dindar.oz on 12/4/2023.
//


#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "numbers.h"

#define C_QUIT 1000
#define C_GIVEUP 2000
#define C_RESTART 3000


#define MAXDIGIT 10
bool gGameOver ;

int gDigitCount;

int gSecretNumber;

void goodBy() {
    printf("Thank you for playing the game!\n");
}

void intro() {
    printf(" __  ______   _________________    __  ________  _____ \n"
           "  /  |/  / _ | / __/_  __/ __/ _ \\  /  |/  /  _/ |/ / _ \\\n"
           " / /|_/ / __ |_\\ \\  / / / _// , _/ / /|_/ // //    / // /\n"
           "/_/  /_/_/ |_/___/ /_/ /___/_/|_| /_/  /_/___/_/|_/____/ \n"
           "                                                         ");

           printf("\n\n");
}

int readDigitCount() {
    int n;

    do {
        printf("Enter the digitcount ( btw. 1-10 ):\n");
        scanf_s("%d",&n);
    } while (n<=0 || n>=10);

    return n;
}

void displayMenu() {

    printf("Special Instructions:\n");
    printf("-----------------------\n");

    printf("[%d]   QUIT\n", C_QUIT);
    printf("[%d]   GIVEUP\n", C_GIVEUP);
    printf("[%d]   RESTART\n", C_RESTART);


}

int pickANumber() {
    int n;
    do {
        n = randomNumber(gDigitCount);
    } while (hasDuplicateDigits(n));

    return n;
}

void initGame() {
    srand(time(0));
    intro();
    gDigitCount = readDigitCount();
    displayMenu();
    gSecretNumber = pickANumber();
    gGameOver = false;
}

int readPositiveNumber() {
    int n;

    do {
        printf("Enter a poisitive integer:\n");
        scanf_s("%d",&n);
    } while (n<=0);

    return n;
}

bool isValid(int input) {
    int dc= log10(input)+1;
    return  dc == gDigitCount && !hasDuplicateDigits(input);
}

void quit() {
    printf ("We were about to cut  the watermelon!\n");
    exit(0);
}

void giveUp() {
    printf("HA HA HA You are too weak!\n");
    printf("My secret number was %d", gSecretNumber);
    gGameOver = true;
}

void restart() {
    printf("My secret number was %d", gSecretNumber);
    printf("The secret number is being reset\n");
    gSecretNumber = pickANumber();


}

void congratulate() {
    printf("Congratulations!!");
    gGameOver = true;

}

void answerUserGuess(int guess) {
    int dSecretNumber[MAXDIGIT];
    int dGuess[MAXDIGIT];

    digitsOf(gSecretNumber,dSecretNumber);
    digitsOf(guess,dGuess);

    int plus = plusComparison(dGuess,dSecretNumber,gDigitCount);
    int minus = minusComparison(dGuess,dSecretNumber,gDigitCount);

    printf("%d +%d-%d\n", guess,plus,minus);

    if (guess == gSecretNumber)
        congratulate();
}

void processInput(int input) {
    if (!isValid(input))
    {
        switch (input)
        {
            case C_QUIT:
            {
                quit();
                break;
            }
            case C_GIVEUP:
            {
                giveUp();
                break;
            }
            case C_RESTART:
            {
                restart();
                break;
            }
            default:

        }
    }
    else
    {
        answerUserGuess(input);
    }
}

void playMastermind() {
    initGame();



    while (!gGameOver)
    {
        int input = readPositiveNumber();
        processInput(input);
        
    }

    goodBy();

}

void main()
{
    playMastermind();
}

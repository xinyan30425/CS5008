#include<stdio.h> //This is an include preprocessor directive
#include<stdlib.h>
#include<time.h>
#include<math.h>

//Any function declarations need to be here
int guessgame()
{
    int number,guess,numberofguess=0;
    //generate a random number between 1 and 10
    number = rand() % 10 + 1;
    printf("Guess the number between 1 and 10 \n");
    
    do
    {
        printf("Enter your guess between 1 and 10: ");
        scanf("%d",&guess);
        numberofguess++;

        if (guess > number){
            printf("The correct number is lower than your guess \n");
        }
        else if (guess < number){
            printf("The correct number is higher than your guess \n");
        }
        else{
            printf("You guessed it in %d attempts \n",numberofguess);
            printf("Your guess is correct, game ends \n");
        }
    } while (guess != number);
    return numberofguess;

}
// run the game program 5 times
int main() 
{   
    int numberofguesslist[5];
    int i=0;
    int numberattempt;
    while(i<=4)
    {
    printf("Game %d \n",i);
    //call main game function
    numberattempt=guessgame();
    numberofguesslist[i]=numberattempt; 
    i++;
}
    printf("Here are the results of your guessing abilities! \n");
    printf("Game 0 took you: %d guesses \n",numberofguesslist[0]);
    printf("Game 1 took you: %d guesses \n",numberofguesslist[1]);
    printf("Game 2 took you: %d guesses \n",numberofguesslist[2]);
    printf("Game 3 took you: %d guesses \n",numberofguesslist[3]);
    printf("Game 4 took you: %d guesses \n",numberofguesslist[4]);

    return 0;   
}




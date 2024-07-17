#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>


int random_number()
{
  int x = (rand() % 1000) + 1;

  return x;
}
int main()
{
  srand(time(0));
  int random; 
  int guess;
  char answer;

    do{
    random = random_number();
    printf("I have a number between 1 and 1000.\n");
    printf("Can you guess my number?\n");
    printf("Please type your first guess: ");
    scanf("%d",&guess);

    while(guess != random){
      if(guess<random){
        printf("Too low. Try again.\n");
        scanf("%d",&guess);
      }
      else if(guess>random){
        printf("Too high. Try again.\n");
        scanf("%d",&guess);
      }
    }
    printf("Excellent! You guessed the number! Would you like to play again (y or n)?\n");
    scanf("%s",&answer);
    answer = toupper(answer);
    while(answer != 'Y' || answer !="N"){
      printf("Please enter y(for yes) or n(for no)");
      scanf("%s",&answer);
      answer = toupper(answer);
    }
    }while(answer == 'Y');
  printf("END");

  return 0;
}
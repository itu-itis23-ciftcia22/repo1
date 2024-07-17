#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

int first_class_random()
{
  int x = rand() %  5;
  return x;
}

int eco_class_random()
{
  int x = rand() %  5 + 5;
  return x;
}

bool is_first_free(int arr[])
{
  for(int i = 0; i<5 ; i++){
      if(arr[i]==0){
       return true; 
      }
    }
  return false;
}

bool is_eco_free(int arr[])
{
  for(int i = 5; i<10 ; i++){
      if(arr[i]==0){
       return true; 
      }
    }
  return false;
}

int first_seat_atama(int arr[]){

  int e ;
    do{
      e = first_class_random();
    }while(arr[e] != 0);

    arr[e]++;
    return e+1;

}

int eco_seat_atama(int arr[]){

  int e ;
    do{
      e = eco_class_random();
    }while(arr[e] != 0);

    arr[e]++;
    return e+1;

}


int main() 
{
  int seats[10]={0}; // dolan koltuklari 1 yapacagiz.

  int type;

  do{
  printf("Please type 1 for \"first class\"\n");
  printf("Please type 2 for \"economy\"\n");
  printf("Please type 3 for \"free seats\"\n");
  printf("Please type 4 to end the program.\n"); 
  scanf("%d",&type);

  if(type == 1){
    char answer;
    if(!is_first_free(seats)){
      printf("The first class is full. Would you like to be assigned to an economy class seat? (Y/N)\n");
      scanf("%s",&answer);
      answer = toupper(answer);
      if(answer == 'N'){
        printf("Next flight leaves in 3 hours.\n");
        break;
      }
      else if(answer == 'Y'){
        if(!is_eco_free(seats)){
          printf("Economy class is also full.\n");
          printf("Next flight leaves in 3 hours.\n");
          break;
        }
        int seat_eco = eco_seat_atama(seats);
        printf("Seat Number: %d, Economy Class.\n",seat_eco);
        printf("New Selection Starts…\n"); 
        continue;    
      }
    }
    int seat_first = first_seat_atama(seats);
    printf("Seat Number: %d, First Class.\n",seat_first);
    printf("New Selection Starts…\n");
    continue;
  }

  if(type == 2){
    char answer;
    if(!is_eco_free(seats)){
      printf("The economy class is full. Would you like to be assigned to an first class seat? (Y/N)\n");
      scanf("%s",&answer);
      answer = toupper(answer);
      if(answer == 'N'){
        printf("Next flight leaves in 3 hours.\n");
        break;
      }
      else if(answer == 'Y'){
        if(!is_first_free(seats)){
          printf("First class is also full.\n");
          printf("Next flight leaves in 3 hours.\n");
          break;
        }
        int seat_first = first_seat_atama(seats);
        printf("Seat Number: %d, First Class.\n",seat_first);
        printf("New Selection Starts…\n");
        continue;
      }
    }
    int seat_eco = eco_seat_atama(seats);
    printf("Seat Number: %d, Economy Class.\n",seat_eco);
    printf("New Selection Starts…\n");
    continue;
   }

   if(type == 3){ 

      int seats_x[10];
      for(int i = 0;i<10;i++){
        if(seats[i] == 1){
          seats_x[i] = i+1;
        }
        else{
          seats_x[i] = 0;
        }
      }
      for(int i = 0;i<10;i=i+2){
        printf("%5d\t|%5d\n",seats_x[i],seats_x[i+1]);
        printf("------------------\n");
      }
      continue;
    }
  }while(type !=4);

    printf("END\n");
  return 0;

}
#include <stdio.h>

int main()
{
  int type=0;
  int size = 10;


  do{
    printf("sola yatik azalan icin 1\n");
    printf("sola yatik artan icin 2\n");
    printf("saga yatik azalan icin 3\n");
    printf("saga yatik artan icin 4\n");
    printf("cikmak icin 5 i tuslayiniz.\n");
    scanf("%d",&type);

    if(type == 1){
      for(int i = 1; i<= size; i++){
        for(int j = 1; j<=i;j++){
          printf("*");
        }
        printf("\n");
      }

    }
    else if(type == 2){
      for(int i = size; i>=1; i--){
        for(int j = 1; j<=i;j++){
          printf("*");
        }
        printf("\n");
      }
      
    }
    else if(type == 3){
      for(int i = size; i>=1; i--){
        for(int k = 0;k<size-i;k++){
          printf(" ");
        }
        for(int j = 1; j<=i;j++){
          printf("*");
        }
        printf("\n");
      }
      
    }
    else if(type == 4){
      for(int i = 1; i<=size; i++){
        for(int k = 0;k<size-i;k++){
          printf(" ");
        }
        for(int j = 1; j<=i;j++){
          printf("*");
        }
        printf("\n");
      }
      
    }
  }while(type !=5);
  
  printf("END\n");
  return 0;

}
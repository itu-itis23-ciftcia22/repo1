#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int number) 
{

  for(int i = 2; i<= sqrt(number); i++){
    if(number % i == 0) return false;
  }
  return true;

}

int main(){

  int count=0;
  int sayi=2;
  int nthprime;

  printf("kacinci asal sayiyi gormek istersiniz: ");
  scanf("%d", &nthprime);

  while(1){

    if(is_prime(sayi)){
      count++;
      if(count==nthprime){
        printf("%d\n",sayi);
        break;
      }
    }
    sayi++;
  }

}
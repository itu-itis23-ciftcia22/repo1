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

  long int toplam=2+3;
  int i, j;
  for(i=5; i<2000000; i+=6){
    if(is_prime(i)){
      toplam+=i;
    }
  }
  for(j=7; j<2000000; j+=6){
    if(is_prime(j)){
      toplam+=j;
    }
  }
  printf("%ld\n", toplam);

}
#include <stdio.h>

int pbs_bulma(int number) {

  int asal = 2;
  int pbs=1;
  int count=0;
  while(number != 1){

    if (number % asal == 0){
         number /= asal;
         count++;

         if(number==1){
          pbs *= (count+1);
         }
         
    }    
    else {
      pbs *= (count+1);
      asal++;
      count = 0;
    }
  }
  return pbs;
}  

int main() {

  int baslatici=1;
  long int i=1;
  int ucgen=2;

  while(baslatici){

    int x= pbs_bulma(i);

    if(x>=500){
      printf("%ld", i);
      baslatici=0;
    }
    else{
      i+=ucgen;
      ucgen++;
    }

  }

}
#include <stdio.h>

int main(){

  int a, b;

  for(a=1; a<500; a++){
    for(b=1; b<500; b++){
      if(a*a + b*b == (1000-a-b)*(1000-a-b)){
        int sayi= a*b*(1000-a-b);
        printf("%d\n%d\n%d\n",a,b,sayi);
        
      }
    }
  }

}
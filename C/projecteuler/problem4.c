#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(int number){

 int sayi, son, ters = 0;
 sayi=number;

 do 
 {
  son = number % 10;
  ters = (ters*10) + son ;
  number /= 10 ;
 }while(number!=0);

 if(sayi==ters) return true;
 else return false;

}

int main(){

int ilk_sayi, son_sayi, sayi, max;


for(ilk_sayi=900; ilk_sayi<1000; ilk_sayi++){
  for(son_sayi=900; son_sayi<1000; son_sayi++){
    sayi= ilk_sayi * son_sayi;
    if(is_palindrome(sayi)==true) max=sayi;
  }
}
printf("%d", max);
}


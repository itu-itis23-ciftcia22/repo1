#include <stdio.h>

int main(){

   int f1=1;
   int f2=1;
   int f=0;
   long int toplam=0;

   while(f<=4000000){
   f=f1+f2;
   if(f%2==0) toplam = toplam + f;
   f1=f2;
   f2=f;
   }

   printf("toplaminiz %ld \n",toplam);
   return 0;

}
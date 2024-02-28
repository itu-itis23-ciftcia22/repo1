#include <stdio.h> 

int main (){
   
   double kilo;
   double boy;
  
   printf("Lutfen kilonuzu kilogram cinsinden giriniz: ");
   scanf("%lf", &kilo);

   printf("Lutfen boyunuzu metre cinsinden giriniz: ");
   scanf("%lf", &boy);

   double bmi = kilo / (boy * boy);

   printf("Vucut kitle endeksiniz: %.2lf \n", bmi);

}
#include <stdio.h>


int oncekare (int number){

  int toplam=0;

  for(int i=1; i<=number; i++){
 
  toplam += (i*i);

  }
  return toplam;
}
int oncetoplam (int number){

  int toplam=0;

  for(int i=1; i<=number; i++){
 
  toplam += i;

  }
  return toplam*toplam;
}

int main()
{
 int fark= oncetoplam(100)-oncekare(100);

 printf("%d\n",fark);

}


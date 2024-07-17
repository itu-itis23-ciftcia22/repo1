#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


#define SIZE 10 

int countCommas(char *str) {
    int count = 0; // Virgül sayısını saklayacak değişken

    // strchr() fonksiyonunu kullanarak bir sonraki virgülü bulun
    char *ptr = strchr(str, ',');

    // Virgül bulunduğu sürece döngüyü devam ettir
    while (ptr != NULL) {
        count++; // Virgül sayısını artır
        ptr = strchr(ptr + 1, ','); // Bir sonraki virgülü bul
    }

    return count; // Virgül sayısını döndür
}
int countPoints(char *str) {
    int count = 0; // Virgül sayısını saklayacak değişken

    // strchr() fonksiyonunu kullanarak bir sonraki virgülü bulun
    char *ptr = strchr(str, '.');

    // Virgül bulunduğu sürece döngüyü devam ettir
    while (ptr != NULL) {
        count++; // Virgül sayısını artır
        ptr = strchr(ptr + 1, '.'); // Bir sonraki virgülü bul
    }

    return count; // Virgül sayısını döndür
}


int main()  // sayi1_1,sayi1_2,sayi1_3,kusurat formatinda yazilacaklar
{
  int c;
  char amount[SIZE];

  puts("Enter a amount:");
  int i = 0;
  while(i<(SIZE-1)&&(c=getchar()) != '\n')
  {
    amount[i] = c;
    i++;
  }
  amount[i] = '\0'; 

  char temp[10];
  strcpy(temp,amount);

  int uzunluk = (int)strlen(temp);


  int virgul_sayisi = countCommas(temp); // 0 mi 1 mi 2 mi? == 0 sa yalniz birler, 1 se birler,onlar 2 ise binler,onlar,milyonlar var demektir.
  int nokta_sayisi = countPoints(temp); // 0 mi 1 mi ? 0 sa kusurat yok, 1 ise kusurat var demektir.

  char* tam_kisim = NULL;
  char* kusurat_kisim = NULL; 
  char* tam_kisim_0 = NULL;
  char* tam_kisim_1 = NULL;
  char* tam_kisim_2 = NULL;

  if(nokta_sayisi==1){
     tam_kisim = strtok(temp, ".");
     kusurat_kisim = strtok(NULL, ".");
  } else {
     tam_kisim = temp;
     kusurat_kisim = "0";
  }

  if(virgul_sayisi == 2){
     tam_kisim_2 = strtok(tam_kisim, ",");
     tam_kisim_1 = strtok(NULL, ",");
     tam_kisim_0 = strtok(NULL, ",");
  }
  else if(virgul_sayisi == 1){
     tam_kisim_2 = "0";
     tam_kisim_1 = strtok(tam_kisim, ",");
     tam_kisim_0 = strtok(NULL, ",");
  } else {
     tam_kisim_2 = "0";
     tam_kisim_1 = "0";
     tam_kisim_0 = strtok(tam_kisim, ",");
  }

  int tam = (1e6 * atoi(tam_kisim_2)) + (1e3 * atoi(tam_kisim_1)) + (1e0 * atoi(tam_kisim_0)) ;

  int kusurat = atoi(kusurat_kisim);

  printf("%d\n%d\n",tam,kusurat); 

  if(tam<1000){
    for(int i = 0; i < 9-uzunluk ; i++){
      printf("*");
    }
    printf("%s",amount);
    
  } else {
    if(virgul_sayisi == 2){
      printf("%s",amount);
    } else {
        printf("%s",amount);
        if(nokta_sayisi==0){
          printf(".");
          for(int i = 0;i <8-uzunluk;i++){
          printf("0");
          }
        } else {
          for(int i = 0;i <9-uzunluk;i++){
          printf("0");
          }
        }
        
    }
  }

  printf("\n");
  return 0;

}
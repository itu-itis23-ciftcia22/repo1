#include <stdio.h>
#include <stdbool.h>


int pbs(int number){

  int pbs = 0;

  for(int i = 0;i<=number;i++){
    if(number % i == 0){
      pbs++;
    }
  }
  return pbs;
}

int main()
{

  int number = 0;
  printf("Enter a number: ");
  scanf("%d",&number);

  int toplam = 0;
  int arr[pbs(number)-1];
  for(int i=0;i<pbs(number)-1;i++){
    arr[i]=0;
  }
  
  int k=0;

  for(int i=1;i<number;i++)
  {
    if(number % i ==0){
      toplam += i;
      arr[k]=i;
      k++;
    }
    
  }

  if(number != toplam){
    printf("%d is not a perfect number.\n",number);
    for(int i = 0;i<pbs(number)-1;i++){
      printf("%d ",arr[i]);
      if(i!=pbs(number)-2){
        printf("+ ");
      }
    }
    printf("= %d\n",toplam);
  }
  else {
    printf("The number %d is a perfect number.\n",number);
    for(int i = 0;i<pbs(number)-1;i++){
      printf("%d ",arr[i]);
      if(i!=pbs(number)-2){
        printf("+ ");
      }
    }
    printf("= %d\n",number);
  }

  printf("END\n");
  return 0;
}
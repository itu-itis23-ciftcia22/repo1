#include <stdio.h>
#include <stdbool.h>

int main ()
{
  // olusturdugumuz variable lara bsalangic degeri atiyoruz.
  int month = 0;
  int days = 0;
  int year = 0 ;

  bool is_leap_year = false;
  bool is30days = false ;


  printf ("Enter Month: ");
  scanf("%d", &month);

  // check if month Feb 
  if (month == 2) 
  /* iceriye month=2 yazsaydik bir assignment olurdu ve degeri 2 yani non-zero integer olacagi icin direkt dogru kabul edilirdi.
      assigmentin degeri atandigi deger olur. */
  {
    printf ("Enter Year: ");
    scanf("%d", &year);

    // is it lap year
    is_leap_year = (year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0;

    days = is_leap_year ? 29 : 28 ;
  }
  else 
  { 
    is30days = month == 4 || month == 6 || month == 9 || month == 11; 
   
    days = is30days ? 30 : 31 ;
  }

  printf("Month is %d days \n", days);

}
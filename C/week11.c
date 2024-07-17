// MEMORY MANAGEMENT // DYNAMIC PROGRAMMING

#include <stdio.h>
#include <stdlib.h> // dynamic memory allocation
#include <stdbool.h>
#include <string.h>

void print_gpas (const double* const gpas, int size) 
{
  for(int i = 0; i < size ; i++)
  {
    printf("%.2lf", gpas[i]);
    if(i < size - 1)
    {
      printf(" | ");
    }
  }
  printf("\n");
}

void print_arr(int* arr, int size)
{
  for(int i = 0; i < size; i++){
    printf("arr[%d]:%d ", i ,arr[i]);
  }
  printf("\n");
}

#define NAMELEN 20
int main()
{
  char name[NAMELEN];
  char name2[NAMELEN];
  printf("Enter a name: ");
  scanf("%s", name);

  for(int i = strlen(name); i >= 0; i--)
  {
    //putchar(name[i]);
    name2[strlen(name) - i] = name[i-1];
  }
  name2[strlen(name)] = '\0';

  puts(name);
  if(strcmp(name,name2)== 0){
    printf("palindrome\n");
  } else {
    printf("not palindrome\n");
  }

  puts(name2);
  
  return 0;
}

int main3()
{
  int *arr1 = (int*) malloc(2 * sizeof(int));

  arr1[0] = 5;
  arr1[1] = 10;

  print_arr(arr1,2);

  int *arr2 = (int*) realloc(arr1, 3 * sizeof(int));

  print_arr(arr2,3);
  arr2[2] = 7;
  print_arr(arr2,3);

  free(arr2);
  // free(arr1) e gerek yok realloc yapiyor

  return 0;
}
int main2() 
{ 

	int num_students = 0;
	double *gpas = NULL; // pointer
	printf("Enter the number of students: ");
	scanf("%d", &num_students);

	gpas = (double *)malloc(num_students*sizeof(double)); // memory allocation function = malloc, for reserve memory; 
												// malloc has no type it returns void *ptr so we cast to double *
												// that is the total bytes I need

	double gpa = 0;
	int index = 0;
	printf("Enter the student grades (-1 to finish): \n");
	while (index < num_students) 
  {
		printf(" > ");
		scanf("%lf", &gpa);
		if (gpa < 0) {
			break;
		}
		gpas[index] = gpa; // pointers like arrays, they point the first eleman of the array
		index++;
	}

  if(index<num_students){
    gpas = realloc(gpas, index*sizeof(double));
  }

  print_gpas(gpas, index);

  free(gpas); // malloc la aldigimiz memory i birakmakliyiz
  gpas = NULL;
  /*
  ptr = null;
  ptr = malloc();
  .
  .
  .
  .
  free(ptr);
  ptr = null;
  */
	return 0;
}
#include <stdio.h>

#define SIZE 10
#define NUM_STU 8



int main()
{
  int current_size = 5;
  int grades[SIZE] = {5,8,10,15,25};

  //int remove_pos = 1;

  for(int i = 0; i < current_size ; i++){
    printf(" %d |", grades[i]);
  }
  printf("\nAfter insertion\n");

  /* code to remove an entry from a sorted array
  for(int i = remove_pos; i < current_size - 1; i++){
    grades[i] = grades[i+1];
  }
  current_size--;
  */
  /* code to remove an entry from a unsorted array
    grades[removed_pos] = grades[current_size-1];
    current_size--;
  */

  /* direkt ilk bosluga yeni eleman ekleme
     grades[current_size] = 20;
     current_size++;
  */

  int new_value = 6;
  int pos_of_insertion = 0;
  // artan seri oldugunu varsayalim

  for(int i = 0; i < current_size ; i++){
    if(grades[i] > new_value){
        pos_of_insertion = i;
        break;
    }
  } 

  current_size++ ;
  for( int i = current_size - 1; i > pos_of_insertion; i--){
    grades[i] = grades[i-1];
  } 
  grades[pos_of_insertion] = new_value;

  // yeni array i yazdir
  for(int i = 0; i < current_size ; i++){
    printf(" %d |", grades[i]);
  }

  return 0;
}












void array_example3()
{
  int grades[SIZE] = {10,20,15,50,35};

  int copy_of_grades[SIZE];

  for(int i = 0 ;i < SIZE; i++){
  copy_of_grades[i] = grades[i];
  }

  for (int i = 0; i < SIZE; i++){
    printf("grades[%d]: %d <-> copy_of_grades[%d]: %d\n", i, grades[i], i, copy_of_grades[i]);
  }

  grades[1]=100;

  printf("\n\n");
  for (int i = 0; i < SIZE; i++){
    printf("grades[%d]: %d <-> copy_of_grades[%d]: %d\n", i, grades[i], i, copy_of_grades[i]);
  }


}



void array_example2()
{
  int num_students = 0;

  do{
    printf("Enter the number of student: ");
    scanf("%d", &num_students);
  } while(num_students < 1);

  int grades[num_students];

  printf("Enter student grades (-1 to finish):\n");

  int grade = 0;
  int index = 0;

  do {
    scanf("%d", &grade);
    if(grade < 0) break;

    grades[index] = grade;
    index++;

  } while(index < num_students);

  for(int i = 0; i < num_students; i++){
    printf("grades[%d] = %d\n",i, grades[i]);
  }
  int selection = 0;
  do{
    printf("\nmake a selection from the following menu items (-1 to exit):\n\n");
    printf("  1: compute the avg of the class\n");
    printf("  2: compute the min of the class\n");
    printf("  3: compute the max of the class\n");
    printf("  4: swap two students\n");

    printf(" \nYour choice: ");

    scanf("%d", &selection);

  
    if(selection == 1){
      int sum = 0;
      double avg = 0;
      for(int i = 0; i < num_students; i++){
          sum += grades[i];
      }
      avg = sum / num_students ;

      printf("avg of the class: %.2lf", avg);
    }

    else if (selection == 2){
      int smallest = grades[0];
      int id_smallest = 0;
      for(int i = 0; i< num_students ; i++){
        if(grades[i] < smallest){
          smallest = grades[i];
          id_smallest = i;
        }
      }
      printf("The student %d has the lowest grade of %d", id_smallest, smallest);
    }

    else if (selection == 3){
      int highest = grades[0];
      int id_highest = 0;
      for(int i = 0; i< num_students ; i++){
        if(grades[i] > highest){
          highest = grades[i];
          id_highest = i;
        }
      }
      printf("The student %d has the highest grade of %d", id_highest, highest);
    }

    else if( selection == 4){
        int id1,id2;
        printf("Enter ids of students you want to swap: ");
        scanf("%d %d", &id1, &id2);

        int x = grades[id1];
        grades[id1] = grades[id2];
        grades[id2] = x;

        printf("Swap completed\n");
        for(int i = 0; i < num_students; i++){
          printf("grades[%d] = %d\n",i, grades[i]);
        }

    }
    
  } while(selection > 0 && selection < 5);
 
}



void array_example1()
{
  /*
  int stu1 = 80;
  int stu2 = 50;
  int stu3 = 70;
  */
  // int size = 10; bole tanimlayinca direkt = {1,2,3,4,..} yazamiyoruz.

  int grades[NUM_STU]= {99,10,50,70,60,20,30,20}; //initializing yapiyoruz yoksa memoryde eski kalan degerleri okuyabiliyor.

  for(int i = 0; i < NUM_STU ; i++){
      printf("grades[%d]: %d \n", i, grades[i]);
  }

  //Q1 find the min grade
  int smallest = grades[0];
  int largest = grades[0];

  for(int i = 1;i < NUM_STU; i++){
    if(grades[i] < smallest){
      smallest = grades[i];
    } 
    else if(grades[i] > largest) {
      largest = grades[i];
    }
  }
  /*
  
  
  if(stu1 < stu2){
    smallest = stu1;
  } else {
    smallest = stu2;
  }

  if(stu3 < smallest) {
    smallest = stu3;
  }
  */

  printf("The smallest of the above numbers is %d\n",smallest);
  printf("The largest of the above numbers is %d\n",largest);

}
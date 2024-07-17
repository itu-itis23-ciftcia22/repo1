#include <stdio.h>
#include <string.h>

struct parent{
    int age;
    char name[50];
};
typedef struct {
    int id;
    char name[50];
    int age;
    double gpa;
    // struct student sibling; // not legal
    //struct student *sibling; // legal
    //struct parent *mother; // legal
    //struct parent *father; // legal
}student;

// typedef struct student Stu;


void print_student(student *std){
  printf("Id: %d\n",std->id);
  printf("Name: %s\n", std->name);
  printf("Age: %d\n", std->age);
  printf("GPA: %f\n", std->gpa);
}

int (create_student_file(char* file_name))
{
  FILE* fptr = NULL;
  if((fptr = fopen("Student.dat",  "wb")) == NULL){
    printf("File opening error!");
    return -1;
  }
  int i = 0;
  while (i<100)
  {
    student empty_std = {0,"",0,0};
    fwrite(&empty_std, sizeof(empty_std), 1, fptr);
    i++;
  }
  fclose(fptr);
  return 1;
}
int main()
{

  if(create_student_file("Student.dat")<0){
    return 0;
  }

  int choice;
  while(1)
  {
    printf("1. Add a new student\n");
    printf("2. Delete a student\n");
    printf("3. Search for a student\n");
    printf("0. Exit\n");
    printf("    Choice:  ");

    scanf("%d",&choice);
    if(choice == 1)
    {
      FILE* fptr = fopen("Student.dat", "rb+");
      student std;
      printf("Enter student id, name, age, gpa: ");
      scanf("%d %49s %d %lf", &std.id, std.name, &std.age, &std.gpa);

      fseek(fptr, (std.id-1) * sizeof(student), SEEK_SET);
      fwrite(&std, sizeof(student), 1, fptr);
      fclose(fptr);
    }
    else if(choice == 3)
    {
      FILE* fptr = fopen("Student.dat", "rb");
      student std;
      int id;
      printf("Enter student id:");
      scanf("%d", &id);
      fseek(fptr, (id-1) * sizeof(student), SEEK_SET);

      fread(&std, sizeof(student), 1, fptr);
      if(std.id == 0){
        printf("Student with id %d does not exist\n", id);
      } else {
        print_student(&std);
      }
      fclose(fptr);
    }
    else if(choice == 2)
    {
      FILE* fptr = fopen("Student.dat", "rb+");
      student std;
      int id;
      printf("Enter student id: ");
      scanf("%d", &id);

      fseek(fptr, (id-1) * sizeof(student), SEEK_SET);
      fread(&std, sizeof(student), 1, fptr);
      if(std.id == 0){
        printf("There is no student with the provided id!\n");
      } else {
        student empty_std = {0,"",0,0};
        fseek(fptr, (id-1) * sizeof(student), SEEK_SET);
        fwrite(&empty_std, sizeof(student), 1, fptr);
      }
      fclose(fptr);
    }
    else if(choice == 0)
    {
      break;
    }
  }

  return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

void addStudent(int **ids, char ***names, float **gpas, int id, char *name, float gpa, int *size){
    *ids = realloc(*ids, (*size + 1) * sizeof(int));
    *gpas = realloc(*gpas, (*size + 1) * sizeof(float));
    *names = realloc(*names, (*size + 1) * sizeof(char *));
    
    // Check if memory allocation was successful
    if (*ids == NULL || *gpas == NULL || *names == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Allocate memory for the new student's name
    (*names)[*size] = malloc((strlen(name) + 1) * sizeof(char));
    if ((*names)[*size] == NULL) {
        fprintf(stderr, "Memory allocation for name failed\n");
        exit(1);
    }
    
    // Assign the new student's id, name, and GPA
    (*ids)[*size] = id;
    strcpy((*names)[*size], name);
    (*gpas)[*size] = gpa;
    
    // Increment the size
    (*size)++;
}
void deleteStudent(int **ids, char ***names, float **gpas, int id, int *size){
    int idx = -1;
    for (int i = 0; i < *size; i++) {
        if (*ids[i] == id) {
            idx = i;
            break;
        }
    }
    if (idx != -1) {
        for(int j=idx; j<*size-1;j++){
            (*gpas)[j] = (*gpas)[j+1];
            (*names)[j] = (*names)[j+1];
            (*ids)[j] = (*ids)[j+1];
        }
        *gpas=realloc(*gpas, (*size-1)*sizeof(float));
        *names=realloc(*names, (*size-1)*sizeof(char));
        *ids=realloc(*ids, (*size-1)*sizeof(int));
    } else {
        printf("Student with ID %d not found\n", id);
    }
    (*size)--;
}
void updateGPA(int *ids, float **gpas, int id, float newGPA, int size){
    int idx = -1;
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) {
            idx = i;
            break;
        }
    }
    if (idx != -1) {
        (*gpas)[idx] = newGPA;
    } else {
        printf("Student with ID %d not found\n", id);
    }
}
void printRecords(int *ids, char **names, float *gpas, int size){
    for(int k=0;k<size;k++){
        printf("%d %s %.2f\n",ids[k],names[k], gpas[k]);
        
    }
}

int main(){

    int choice=0;
    int *ids = NULL;
    char **names = NULL;
    float *gpas= NULL;
    int size=0;
    int id;
    char *name=malloc(MAX_NAME_LENGTH*sizeof(char));
    float gpa;
    char c;
    
    while(choice!=-1){
        printf("Please press 1 to add a student\n");
        printf("Please press 2 to delete a student\n");
        printf("Please press 3 to update a student's GPA\n");
        printf("Please press 4 to print all records\n");
        printf("Press -1 to exit!\n");
        scanf("%d", &choice);
    
        switch(choice){
            case 1:
                printf("Please enter the id:");
                scanf("%d", &id);
                
                while ((c = getchar()) != '\n' && c != EOF);
                printf("Please enter the name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';
                
                printf("Please enter the GPA:");
                scanf("%f", &gpa);
                addStudent( &ids, &names, &gpas, id, name, gpa, &size);
                break;
    
            case 2:
                printf("Please enter the id of the student you want to delete:");
                scanf("%d",&id);
                deleteStudent(&ids, &names, &gpas, id, &size);
                break;
    
            case 3:
                printf("Please enter the id of the student you want to update:");
                scanf("%d",&id);
                printf("Please enter the new GPA:");
                scanf("%f",&gpa);
                updateGPA(ids, &gpas, id, gpa, size);
                break;
    
            case 4:
                printRecords(ids, names, gpas, size);
                break;
        }
    
        
    }
    free(name);

    return 0;
}
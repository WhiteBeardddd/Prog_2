#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50

typedef struct
{
    char name[50]; 
    int age;      
} Student;

void createStudent(Student *students, int *size)
{
    printf("\n");
    int age;
    char name[50];
    
    if(*size >= 10){
        printf("Student List is full: ");
        return;
    }

    printf("Enter Student's name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter Student's age: ");
    scanf("%d", &age);

    printf("\n");
    strcpy(students[*size].name, name); 
    students[*size].age = age;          
    (*size)++;                          
}

void readStudents(Student *students, int size)
{
    printf("\n");
    if(size == 0){
        printf("No students are on the list!!");
        return;
    }

    for (int i = 0; i < size; i++)
    {                                                                                          
        printf("Student %d: Name = %s, Age = %d\n", i + 1, students[i].name, students[i].age);
    }
    printf("\n");
}

void updateStudent(Student *students, int size)
{
    int newAge; 
    int index;
    char newName[MAX];
    
    printf("\n");

    if(size == 0){
        printf("No students in the List to update\n");
        return;
    }

    printf("Enter the student number to update (1 to %d): ", size);
    scanf("%d", &index);

    printf("\n");

    if(index >= 1 && index <= size){
        printf("Enter Student's new name: ");
        scanf("%s", newName);
        newName[strcspn(newName, "\n")] = '\0';

        printf("Enter Student's new age: ");
        scanf("%d", &newAge);

        strcpy(students[index-1].name, newName);
        students[index-1].age = newAge;
    }else{
        printf("Invalid student number\n");
        return;
    }
    printf("\n");
}

void deleteStudent(Student *students, int *size)
{
    int index;
    
    printf("\n");

    if(size == 0){
        printf("No students in the List to delete\n");
        return;
    }

    printf("Enter student number to delete (1 to %d): ", *size);
    scanf("%d", &index);
    
    if(index - 1 > *size && index - 1 < 0){
        printf("Invalid number to delete");
    }

    printf("\n");

    for (int i = index; i < *size - 1; i++)
    {                                
        students[i - 1] = students[i + 1];
    }
    (*size)--;
}

int main()
{
    Student students[10];
    int size = 0;
    int choice;

    do{
        printf("Student Management System:\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Delete Student\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
        case 1:
            createStudent(students, &size);
            break;
        case 2:
            updateStudent(students, size);
            break;
        case 3:
            deleteStudent(students, &size);
            break;
        case 4:
            readStudents(students, size);
            break;
        case 5:
            printf("Exiting Program...");
            break;
        default:
            printf("Invalid input...");
        }
    }while(choice != 5);


    return 0;
}


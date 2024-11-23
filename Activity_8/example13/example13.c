#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
typedef struct Student
{
    int id;
    char name[50];
    struct Student *next;
} Student;

// Function to create a new student node
Student *createStudent(int id, const char *name)
{
    Student *newStudent = (Student *)malloc(sizeof(Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->next = NULL;
    return newStudent;
}

// Function to add a student to the linked list
void addStudent(Student **head, int id, const char *name)
{
    Student *newStudent = createStudent(id, name);
    newStudent->next = *head;
    *head = newStudent;
}

// Function to save the student list to a file
void saveToFile(Student *head, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Failed to open file");
        return;
    }

    Student *current = head;
    while (current != NULL)
    {
        fprintf(file, "%d %s\n", current->id, current->name);
        current = current->next;
    }

    fclose(file);
}

// Function to print the student list
void printStudents(Student *head)
{
    Student *current = head;
    while (current != NULL)
    {
        printf("ID: %d, Name: %s\n", current->id, current->name);
        current = current->next;
    }
}

int main()
{
    Student *head = NULL;

    // Add some students to the list
    addStudent(&head, 1, "Alice");
    addStudent(&head, 2, "Bob");
    addStudent(&head, 3, "Charlie");

    // Print the student list
    printf("Student List:\n");
    printStudents(head);

    // Save the student list to a file
    saveToFile(head, "students.txt");

    // Free the allocated memory
    Student *current = head;
    while (current != NULL)
    {
        Student *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
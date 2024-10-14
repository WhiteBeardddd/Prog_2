#include <stdio.h>
#include <string.h>
#define MAX 50

// Define a struct for Student
typedef struct
{
    char name[50]; // Declare a character array of size 50 to store the student's name
    int age;       // Declare an integer to store the student's age
} Student;

// Function to create a student (Add to the array)
void createStudent(Student students[], int *size)
{
    int age;
    char name[MAX];
    
    if(*size >= 10){
        printf("Student List is full: ");
    }


    printf("Enter Student's name: ");
    scanf("%s", name);
    name[strcspn(name, "\n")] = '0';

    printf("Enter Student's age: ");
    scanf("%d", &age);

    strcpy(students[*size].name, name); // Copy the provided name into the name field of the student at the current size index
    students[*size].age = age;          // Assign the provided age to the age field of the student at the current size index
    (*size)++;                          // Increment the size to indicate a new student has been added
}

// Function to read all students (Display the array)
void readStudents(Student students[], int size)
{
    if(size == 0){
        printf("No students are on the list!!");
        return;
    }

    for (int i = 0; i < size; i++)
    {                                                                                          // Iterate through all students
        printf("Student %d: Name = %s, Age = %d\n", i + 1, students[i].name, students[i].age); // Print the details of each student
    }
}

// Function to update a student's details by index
void updateStudent(Student students[], int size)
{
    int newAge, index;
    char newName[MAX];

    if(size == 0){
        printf("No students in the List to update");
        return;
    }

    printf("Enter the student number to update (1 to %d): ", size);
    scanf("%d", &index);

    if(index >= 1 && index <= size){
        printf("Enter Student's new name: ");
        scanf("%s", newName);
        newName[strcspn(newName, "\n")] = '\0';

        printf("Enter Student's new age: ");
        scanf("%d", &newAge);

        strcpy(students[index].name, newName); // Copy the new name into the name field of the student at the specified index
        students[index].age = newAge;          // Assign the new age to the age field of the student at the specified index
    }else{
        printf("Invalid student number");
        return;
    }
}

// Function to delete a student (Remove from the array)
void deleteStudent(Student students[], int *size)
{
    int index;

    if(size == 0){
        printf("No students in the List to delete");
        return;
    }

    printf("Enter student number to delete (1 to %d): ", size);
    scanf("%d", &index);

    for (int i = index; i < *size - 1; i++)
    {                                  // Iterate from the index to be deleted to the last element
        students[i] = students[i + 1]; // Shift elements to the left, overwriting the deleted element
    }
    (*size)--; // Reduce the size to indicate a student has been removed
}

int main()
{
    Student students[10]; // Create an array to store up to 10 students
    int size = 0;         // Initialize the current number of students to 0
    int choice;
    // Create students (Add)

    do{
        printf("Student Management System:\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Delete Student\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
        default:
            printf("Invalid input...");
        }
    }while(choice != 5);


    return 0;
}
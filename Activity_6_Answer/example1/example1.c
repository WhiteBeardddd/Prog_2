#include <stdio.h>
#include <string.h>

// Define a struct for Student
typedef struct
{
    char name[50]; // Declare a character array of size 50 to store the student's name
    int age;       // Declare an integer to store the student's age
} Student;

// Function to create a student (Add to the array)
void createStudent(Student students[], int *size, const char *name, int age)
{
    strcpy(students[*size].name, name); // Copy the provided name into the name field of the student at the current size index
    students[*size].age = age;          // Assign the provided age to the age field of the student at the current size index
    (*size)++;                          // Increment the size to indicate a new student has been added
}

// Function to read all students (Display the array)
void readStudents(Student students[], int size)
{
    for (int i = 0; i < size; i++)
    {                                                                                          // Iterate through all students
        printf("Student %d: Name = %s, Age = %d\n", i + 1, students[i].name, students[i].age); // Print the details of each student
    }
}

// Function to update a student's details by index
void updateStudent(Student students[], int index, const char *newName, int newAge)
{
    strcpy(students[index].name, newName); // Copy the new name into the name field of the student at the specified index
    students[index].age = newAge;          // Assign the new age to the age field of the student at the specified index
}

// Function to delete a student (Remove from the array)
void deleteStudent(Student students[], int *size, int index)
{
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

    // Create students (Add)
    createStudent(students, &size, "Alice", 20);   // Add Alice to the array
    createStudent(students, &size, "Bob", 22);     // Add Bob to the array
    createStudent(students, &size, "Charlie", 19); // Add Charlie to the array

    // Read all students (Display)
    printf("After Adding Students:\n");
    readStudents(students, size);

    // Update the second student's details (Update)
    updateStudent(students, 1, "Bobby", 23); // Update Bob's details
    printf("\nAfter Updating Bob's details:\n");
    readStudents(students, size);

    // Delete the first student (Delete)
    deleteStudent(students, &size, 0); // Delete Alice
    printf("\nAfter Deleting Alice:\n");
    readStudents(students, size);

    return 0;
}
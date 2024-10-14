#include <stdio.h>
#include <string.h>

// Define a struct for Student
typedef struct
{
    char name[50];
    int age;
} Student;

// Define a struct for Course
typedef struct
{
    char name[50];
    int credits;
} Course;

// Define a struct for Enrollment
typedef struct
{
    Student student;
    Course course;
    char grade;
} Enrollment;

// Function to create a student (Add to the array)
void createStudent(Enrollment enrollments[], int *size, const char *name, int age)
{
    strcpy(enrollments[*size].student.name, name);
    enrollments[*size].student.age = age;
    (*size)++;
}

// Function to read all students (Display the array)
void readStudents(Enrollment enrollments[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Student %d: Name = %s, Age = %d\n", i + 1, enrollments[i].student.name, enrollments[i].student.age);
    }
}

// Function to update a student's details by index
void updateStudent(Enrollment enrollments[], int index, const char *newName, int newAge)
{
    strcpy(enrollments[index].student.name, newName);
    enrollments[index].student.age = newAge;
}

// Function to delete a student (Remove from the array)
void deleteStudent(Enrollment enrollments[], int *size, int index)
{
    for (int i = index; i < *size - 1; i++)
    {
        enrollments[i] = enrollments[i + 1];
    }
    (*size)--;
}

// Function to enroll a student in a course
void enrollStudent(Enrollment enrollments[], int *size, const char *studentName, const char *courseName, int courseCredits)
{
    // Find the student index
    int studentIndex = -1;
    for (int i = 0; i < *size; i++)
    {
        if (strcmp(enrollments[i].student.name, studentName) == 0)
        {
            studentIndex = i;
            break;
        }
    }

    // If student is found, enroll them in the course
    if (studentIndex != -1)
    {
        strcpy(enrollments[studentIndex].course.name, courseName);
        enrollments[studentIndex].course.credits = courseCredits;
    }
    else
    {
        printf("Student %s not found.\n", studentName);
    }
}

// Function to read all enrollments (Display the array)
void readEnrollments(Enrollment enrollments[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enrollment %d: Student = %s, Course = %s, Credits = %d\n", i + 1, enrollments[i].student.name, enrollments[i].course.name, enrollments[i].course.credits);
    }
}

// Function to update a student's grade in a course
void updateGrade(Enrollment enrollments[], int studentIndex, char newGrade)
{
    enrollments[studentIndex].grade = newGrade;
}

// Function to calculate a student's GPA based on their enrollments
double calculateGPA(Enrollment enrollments[], int studentIndex)
{
    int totalCredits = 0;
    double totalGradePoints = 0;

    for (int i = 0; i < enrollments[studentIndex].course.credits; i++)
    {
        totalCredits += enrollments[studentIndex].course.credits;
        if (enrollments[studentIndex].grade == 'A')
        {
            totalGradePoints += 4.0 * enrollments[studentIndex].course.credits;
        }
        else if (enrollments[studentIndex].grade == 'B')
        {
            totalGradePoints += 3.0 * enrollments[studentIndex].course.credits;
        }
        else if (enrollments[studentIndex].grade == 'C')
        {
            totalGradePoints += 2.0 * enrollments[studentIndex].course.credits;
        }
        else if (enrollments[studentIndex].grade == 'D')
        {
            totalGradePoints += 1.0 * enrollments[studentIndex].course.credits;
        }
        else if (enrollments[studentIndex].grade == 'F')
        {
            totalGradePoints += 0.0 * enrollments[studentIndex].course.credits;
        }
    }

    return totalGradePoints / totalCredits;
}

int main()
{
    Enrollment enrollments[10];
    int size = 0;

    // Create students (Add)
    createStudent(enrollments, &size, "Alice", 20);
    createStudent(enrollments, &size, "Bob", 22);
    createStudent(enrollments, &size, "Charlie", 19);

    // Enroll students in courses
    enrollStudent(enrollments, &size, "Alice", "Math 101", 3);
    enrollStudent(enrollments, &size, "Bob", "History 202", 4);
    enrollStudent(enrollments, &size, "Charlie", "English 101", 3);
    enrollStudent(enrollments, &size, "Alice", "Science 101", 3);

    // Update a student's grade
    updateGrade(enrollments, 0, 'B');

    // Calculate a student's GPA
    double aliceGPA = calculateGPA(enrollments, 0);
    printf("Alice's GPA: %.2f\n", aliceGPA);

    // Read all enrollments
    readEnrollments(enrollments, size);

    return 0;
}
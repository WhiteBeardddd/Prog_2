#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Student;

typedef struct {
    char name[50];
    int credits;
} Course;

typedef struct {
    Student student;
    Course course;
    char grade;
} Enrollment;

void createStudent(Enrollment enrollments[], int *size) {
    if (*size >= 10) {
        printf("Student list is full.\n");
        return;
    }

    char name[50];
    int age;

    printf("Enter student name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove trailing newline

    printf("Enter student age: ");
    scanf("%d", &age);
    getchar(); // Consume newline

    strcpy(enrollments[*size].student.name, name);
    enrollments[*size].student.age = age;
    (*size)++;
}

void readStudents(Enrollment enrollments[], int size) {
    if (size == 0) {
        printf("No students available.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("Student %d: Name = %s, Age = %d\n", i + 1, enrollments[i].student.name, enrollments[i].student.age);
    }
}

void updateStudent(Enrollment enrollments[], int index) {
    char newName[50];
    int newAge;

    printf("Enter new name: ");
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = '\0';  // Remove trailing newline

    printf("Enter new age: ");
    scanf("%d", &newAge);
    getchar(); // Consume newline

    strcpy(enrollments[index].student.name, newName);
    enrollments[index].student.age = newAge;
}

void deleteStudent(Enrollment enrollments[], int *size, int index) {
    for (int i = index; i < *size - 1; i++) {
        enrollments[i] = enrollments[i + 1];
    }
    (*size)--;
}

void enrollStudent(Enrollment enrollments[], int size) {
    char studentName[50], courseName[50];
    int courseCredits;

    printf("Enter student name: ");
    fgets(studentName, sizeof(studentName), stdin);
    studentName[strcspn(studentName, "\n")] = '\0';  // Remove trailing newline

    int studentIndex = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(enrollments[i].student.name, studentName) == 0) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex != -1) {
        printf("Enter course name: ");
        fgets(courseName, sizeof(courseName), stdin);
        courseName[strcspn(courseName, "\n")] = '\0';  // Remove trailing newline

        printf("Enter course credits: ");
        scanf("%d", &courseCredits);
        getchar(); // Consume newline

        strcpy(enrollments[studentIndex].course.name, courseName);
        enrollments[studentIndex].course.credits = courseCredits;
    } else {
        printf("Student %s not found.\n", studentName);
    }
}

void readEnrollments(Enrollment enrollments[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enrollment %d: Student = %s, Course = %s, Credits = %d, Grade = %c\n",
               i + 1, enrollments[i].student.name, enrollments[i].course.name,
               enrollments[i].course.credits, enrollments[i].grade);
    }
}

void updateGrade(Enrollment enrollments[], int studentIndex) {
    char newGrade;

    printf("Enter new grade (A-F): ");
    scanf(" %c", &newGrade);  // Notice the space before %c to consume any leftover newline
    enrollments[studentIndex].grade = newGrade;
}

double calculateGPA(Enrollment enrollments[], int studentIndex) {
    int totalCredits = enrollments[studentIndex].course.credits;
    double totalGradePoints = 0;

    if (enrollments[studentIndex].grade == 'A') {
        totalGradePoints = 4.0 * totalCredits;
    } else if (enrollments[studentIndex].grade == 'B') {
        totalGradePoints = 3.0 * totalCredits;
    } else if (enrollments[studentIndex].grade == 'C') {
        totalGradePoints = 2.0 * totalCredits;
    } else if (enrollments[studentIndex].grade == 'D') {
        totalGradePoints = 1.0 * totalCredits;
    } else if (enrollments[studentIndex].grade == 'F') {
        totalGradePoints = 0.0 * totalCredits;
    }

    return totalGradePoints / totalCredits;
}

int main() {
    Enrollment enrollments[10];
    int size = 0;
    int choice, studentIndex;

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Delete Student\n");
        printf("4. Enroll Student in Course\n");
        printf("5. Update Grade\n");
        printf("6. Calculate GPA\n");
        printf("7. Read Enrollments\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                createStudent(enrollments, &size);
                break;
            case 2:
                printf("Enter student index to update: ");
                scanf("%d", &studentIndex);
                getchar(); // Consume newline
                updateStudent(enrollments, studentIndex - 1);
                break;
            case 3:
                printf("Enter student index to delete: ");
                scanf("%d", &studentIndex);
                getchar(); // Consume newline
                deleteStudent(enrollments, &size, studentIndex - 1);
                break;
            case 4:
                enrollStudent(enrollments, size);
                break;
            case 5:
                printf("Enter student index to update grade: ");
                scanf("%d", &studentIndex);
                getchar(); // Consume newline
                updateGrade(enrollments, studentIndex - 1);
                break;
            case 6:
                printf("Enter student index to calculate GPA: ");
                scanf("%d", &studentIndex);
                getchar(); // Consume newline
                double gpa = calculateGPA(enrollments, studentIndex - 1);
                printf("GPA: %.2f\n", gpa);
                break;
            case 7:
                readEnrollments(enrollments, size);
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);

    return 0;
}


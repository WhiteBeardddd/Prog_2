#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Student;

void createStudent(Student students[], int *size) {
    if (*size >= 10) {
        printf("Student list is full. Can't add more students.\n");
        return;
    }

    char name[50];
    int age;

    printf("Enter Student Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter Student Age: ");
    scanf("%d", &age);

    strcpy(students[*size].name, name);
    students[*size].age = age;
    (*size)++;
}

void readStudents(Student students[], int size) {
    if (size == 0) {
        printf("No students available.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("Student %d: Name = %s, Age = %d\n", i + 1, students[i].name, students[i].age);
    }
}

void updateStudent(Student students[], int size) {
    int index;
    char newName[50];
    int newAge;

    if (size == 0) {
        printf("No students available to update.\n");
        return;
    }

    printf("Enter the student number to update (1 to %d): ", size);
    scanf("%d", &index);

    if (index >= 1 && index <= size) {
        getchar();
        printf("Enter New Name: ");
        fgets(newName, sizeof(newName), stdin);
        newName[strcspn(newName, "\n")] = '\0';

        printf("Enter New Age: ");
        scanf("%d", &newAge);

        strcpy(students[index - 1].name, newName);
        students[index - 1].age = newAge;
        printf("Student %d updated successfully.\n", index);
    } else {
        printf("Invalid student number.\n");
    }
}

void deleteStudent(Student students[], int *size) {
    int index;

    if (*size == 0) {
        printf("No students available to delete.\n");
        return;
    }

    printf("Enter the student number to delete (1 to %d): ", *size);
    scanf("%d", &index);

    if (index >= 1 && index <= *size) {
        for (int i = index - 1; i < *size - 1; i++) {
            students[i] = students[i + 1];
        }
        (*size)--;
        printf("Student %d deleted successfully.\n", index);
    } else {
        printf("Invalid student number.\n");
    }
}

int main() {
    Student students[10];
    int size = 0;
    int choice;

    do {
        printf("\nStudent Management System:\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Delete Student\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
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
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}


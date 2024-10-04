#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
#define NUM_GRADES 5

typedef struct{
    char name[MAX];
    int studentID;
    float grade[NUM_GRADES];
}StudentList;

void createStudent(StudentList *student, char *name, int id, float *grades, int *index);
void readStudent(StudentList *student, int *index);
void updateStudentGrades(StudentList *student, int updateValue, float *newGrade, int *index);

int main(){
    int size = 3;          // Variable to hold the current number of students
    int arraySize = 5; // Fixed array size for demonstration purposes
    int index = 0;
    
    StudentList *student = malloc(sizeof(student) * size);
    
    float stud1Grade[NUM_GRADES] = {85.00, 90.00, 78.50, 88.00, 92.50};
    float stud2Grade[NUM_GRADES] = {70.00, 75.00, 80.00, 82.00, 79.00};
    float stud3Grade[NUM_GRADES] = {95.00, 93.50, 97.00, 91.00, 89.50};
    float newGrade[NUM_GRADES] = {88.00, 90.00, 85.50, 87.00, 89.00};

    createStudent(student, "Alice Johnson", 101, stud1Grade, &index);
    createStudent(student, "Bob Smith", 102, stud2Grade, &index);
    createStudent(student, "Carol Davis", 103, stud3Grade, &index);

    printf("Students in the system:\n");
    readStudent(student, &index);

    printf("\n");

    updateStudentGrades(student, 102, newGrade, &index);
    readStudent(student, &index);

    free(student);

    // printf("%s", student[0].name);
    // printf("%d", student[0].studentID);
    // printf("%.2f", student[0].grade[0]);

    return 0;
}

void updateStudentGrades(StudentList *student, int ID, float *newGrade, int *index){
    for(int i = 0; i < *index; i++)
    {
        if(student[i].studentID == ID)
        {
            printf("After updating %s's grades:\n", student[i].name);
            memcpy(student[i].grade, newGrade, NUM_GRADES * sizeof(float));
        }
    }
}

float calculateAverage(float *grades){
    float avg;
    float sum = 0;

    for(int i = 0; i < NUM_GRADES; i++)
    {
        sum += grades[i];
    }
    return avg = sum / NUM_GRADES;
}

void createStudent(StudentList *student, char *name, int id, float *grades, int *index){
    strcpy(student[(*index)].name, name);
    student[(*index)].studentID = id;
    memcpy(student[(*index)].grade, grades, NUM_GRADES * sizeof(int));

    (*index)++;
}

void readStudent(StudentList *student, int *index){
    for(int i = 0; i < *index; i++)
    {
        printf("Student %d: Name = %s, ID = %d, Grade = ", i+1, student[i].name, student[i].studentID);
        for(int j = 0; j < NUM_GRADES; j++)
        {
            printf("%.2f ", student[i].grade[j]);
        }
        float average = calculateAverage(student[i].grade);
        printf("Average = %.2f", average);
        printf("\n");
    }
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX 50
// #define NUM_GRADES 5

// typedef struct{
//     char name[MAX];
//     int studentID;
//     float grade[NUM_GRADES];
// }Students;

// void createStudents(Students *studentList, char *name, int ID, float *grades, int *index);
// void display(Students *studentList, int *index);
// float calculateAverage(Students *studentList, int *index);

// int main(){
//     int size;          // Variable to hold the current number of students
//     int arraySize = 5; // Fixed array size for demonstration purposes
//     int index = 0;
    
//     Students *studentList = malloc(sizeof(studentList) * 3);
    
//     float stud0Grade[NUM_GRADES] = {85.00, 90.00, 78.50, 88.00, 92.50};
//     float stud1Grade[NUM_GRADES] = {85.00, 90.00, 78.50, 88.00, 92.50};
//     float stud2Grade[NUM_GRADES] = {70.00, 75.00, 80.00, 82.00, 79.00};
//     float stud3Grade[NUM_GRADES] = {95.00, 93.50, 97.00, 91.00, 89.50};
    
//     createStudents(studentList, "Alice Johnson", 101, stud0Grade, &index);
//     createStudents(studentList, "Alice Johnson", 101, stud1Grade, &index);
//     createStudents(studentList, "Bob Smith", 102, stud2Grade, &index);
//     createStudents(studentList, "Carol Davis", 103, stud3Grade, &index);
    
//     printf("Students in the system:\n");
    
//     display(studentList, &index);
    
//     // printf("%.2f\n", studentList[0].grade[0]);
//     // printf("%s\n", studentList[1].name);
//     // printf("%d\n", studentList[0].studentID);
//     // printf("%d\n", studentList[0].studentID);
    
//     return 0;
// }

// float calculateAverage(Students *studentList, int *index){
//     float avg;
//     float sum = 0;
//     for(int i = 0; i < 5; i++)
//     {
//         if(i != 0){
//             sum += studentList->grade[i];
//         }
//     }
//     avg = sum / 5;
    
//     return avg;
// }
// float calculateAverage(float* grades){
//     float avg;
//     float sum = 0;
//     for(int i = 0; i < 5; i++)
//     {
//         if(i != 0){
//             sum += grades[i];
//         }
//     }
//     avg = sum / 5;
    
//     return avg;
// }

// void createStudents(Students *studentList, char *name, int ID, float *grades, int *index){
//     strcpy(studentList[(*index)].name, name);
//     studentList[(*index)].name[strcspn(studentList[(*index)].name, "\n")] = '\0';
//     studentList[(*index)].studentID = ID;
    
//     for(int i = 0; i < 5; i++)
//     {
//             studentList[(*index)].grade[i] = grades[i];
//     }
//     (*index)++;
// }

// void display(Students *studentList, int *index){
//     for(int i = 0; i < 4; i++){
//         if(i != 0){
//         printf("Student %d:", i);
//         printf(" Name = %s,", studentList[i].name);
//         printf(" ID = %d", studentList[i].studentID);
//         printf(" Grade = ");
//         for(int j = 0; j < 5; j++)
//         {
//             printf("%.2f", studentList[i].grade[j]);    
//         }
//         printf("Average = ");
//         float average = calculateAverage(studentList, index);
//         printf("%.2f", average);
        
//         printf("\n");
//         }
//     }
// }
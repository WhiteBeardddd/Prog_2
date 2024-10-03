#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct{
    char fname[MAX];
    char lname[MAX];
    char mi;
    int age;
}Student;



int main (){


    return 0;
}

































// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX 20


// typedef struct{
//     char fname[MAX];
//     char lname[MAX];
//     char Mi;
// }Name;

// typedef struct{
//     char month[MAX];
//     int day;
//     int year;
// }BirthDate;

// typedef struct{
//     char department[MAX];
//     char location[MAX];
// }Department;

// typedef struct {
//     Name name;
//     BirthDate birthDate;
//     Department department;
//     char school[MAX];
// }Student;

// typedef struct {
//     Student *student;
//     int idnum;
// }StudentList;

// Department createDepartment(char *department, char *location);
// BirthDate createBirthdate(char *month, int day, int year);
// Name createName(char *lname, char *fname, char mi);
// Student createStudent(Name name, BirthDate birthday, Department department, char *school);
// void addStudent(StudentList *Stud, Student newStud);

// int main(){
//     StudentList Stud;
//     Stud.student = malloc(sizeof(Student) * MAX);
//     Stud.idnum = 8;

//     Student stuD1 = createStudent(createName("Jumong", "Jimping", 'I'), createBirthdate("September", 8, 2004),createDepartment("DCISM", "4th Floor"), "San Carlos");

//     printf("%s %s %c\n", stuD1.name.lname, stuD1.name.fname, stuD1.name.Mi);
//     printf("%s %d %d\n", stuD1.birthDate.month, stuD1.birthDate.day, stuD1.birthDate.year);
//     printf("%s %s %s\n", stuD1.department.department, stuD1.department.location, stuD1.school);

//     return 0;
// }

// Name createName(char *lname, char *fname, char mi){
//     Name newName;
//     strcpy(newName.lname, lname);
//     strcpy(newName.fname, fname);
//     newName.Mi = mi;

//     return newName;
// }
// BirthDate createBirthdate(char *month, int day, int year){
//     BirthDate newBirthday;
//     strcpy(newBirthday.month, month);
//     newBirthday.day = day;
//     newBirthday.year = year;

//     return newBirthday;
// }
// Department createDepartment(char *department, char *location){
//     Department newDepartment;
//     strcpy(newDepartment.department, department);
//     strcpy(newDepartment.location, location);

//     return newDepartment;
// }
// Student createStudent(Name name, BirthDate birthday, Department department, char *school){
//     Student newStudent;
//     newStudent.name = name;
//     newStudent.birthDate = birthday;
//     newStudent.department = department;
//     strcpy(newStudent.school, school);

//     return newStudent;
// }


// void addStudent(StudentList *Stud, Student newStud){
    
// }
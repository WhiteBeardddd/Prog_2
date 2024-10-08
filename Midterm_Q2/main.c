#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUD 10

typedef struct{
	char fName[32];
	char mi;
	char lName[16];
}fullName;

typedef struct{
	int score;			//Score of the student.
	int totalScore;		//Total score of the exam.
}exam;

typedef struct{
	exam exams[4];
	int numExams;
    int numPassedExams;
}grades;

typedef struct{
	fullName name;
	char idNum[9];
	char course[5];
	char gender;
	grades examScores;
}student;

typedef struct{
    student *studPass;
	int index;
}studIndex;

studIndex getExamPassers(student *students, int numStuds);
void init_student_index(studIndex *array);
void display(studIndex passers);

int main(void)
{
	student students[MAX_STUD] = {
	    {{"Alice", 'B', "Johnson"}, "22101234", "BSCS", 'F', {{{85, 100}, {75, 100}, {60, 100}, {90, 100}}, 4 }},
	    {{"Bob", 'C', "Smith"}, "21102345", "BSIT", 'M', {{{45, 100}, {70, 100}, {80, 100}, {65, 100}}, 4 }},
	    {{"Charlie", 'D', "Brown"}, "20103456", "BSIS", 'M', {{{78, 100}, {60, 100}, {85, 100}, {55, 100}}, 4 }},
	    {{"Diana", 'E', "Clark"}, "19104567", "BSCS", 'F', {{{60, 100}, {62, 100}, {90, 100}, {50, 100}}, 4 }},
	    {{"Ethan", 'F', "Lewis"}, "18105678", "BSIT", 'M', {{{70, 100}, {80, 100}, {90, 100}, {30, 100}}, 4 }},
	    {{"Fiona", 'G', "Martinez"}, "22106789", "BSIS", 'F', {{{85, 100}, {88, 100}, {90, 100}, {40, 100}}, 4 }},
	    {{"George", 'H', "Wilson"}, "21107890", "BSCS", 'M', {{{67, 100}, {75, 100}, {80, 100}, {90, 100}}, 4 }},
	    {{"Hannah", 'I', "Moore"}, "20108901", "BSIT", 'F', {{{55, 100}, {60, 100}, {85, 100}, {95, 100}}, 4 }},
	    {{"Ian", 'J', "Taylor"}, "19109012", "BSIS", 'M', {{{30, 100}, {40, 100}, {60, 100}, {70, 100}}, 4 }},
	    {{"Julia", 'K', "Anderson"}, "18101234", "BSCS", 'F', {{{90, 100}, {85, 100}, {70, 100}, {40, 100}}, 4 }}
	};
	int numStuds = MAX_STUD;

    studIndex PASS;
    init_student_index(&PASS);

    PASS = getExamPassers(students, numStuds);
    display(PASS);

	return 0;
}

void init_student_index(studIndex *array) {
    array->index = 0;
    array->studPass = malloc(MAX_STUD * sizeof(student));
}


studIndex getExamPassers(student *students, int numStuds){
    student temp[MAX_STUD];
    int index = 0;
    for(int i = 0; i < numStuds; i++)
    {
        students[i].examScores.numPassedExams = 0;
        for (int examNum = 0; examNum < 4; ++examNum) 
        {
                if(students[i].examScores.exams[examNum].score >= students[i].examScores.exams[examNum].totalScore * 0.6)
                {
                    students[i].examScores.numPassedExams++;
                }
        }
        if (students[i].examScores.numPassedExams > 0) {
            temp[index] = students[i];
            index++;
        }
    }
    studIndex passers;
    passers.studPass = malloc(sizeof(student) * index);
    if (passers.studPass) {
        memcpy(passers.studPass, temp, sizeof(student) * index);
        passers.index = index;
    }
    return passers;
}

void display(studIndex passers){
    for(int i = 0; i < passers.index; i++)
    {
        for (int j = 0; j < passers.studPass[i].examScores.numPassedExams; ++j) {
            printf("ID: %s | Name: %s %c %s | Program: %s | Scores: %d \n", 
            passers.studPass[i].idNum, 
            passers.studPass[i].name.fName, 
            passers.studPass[i].name.mi,
            passers.studPass[i].name.lName,
            passers.studPass[i].course,
            passers.studPass[i].examScores.exams[j]);

        }
    }
}


// Write the code for the function getExamPassers().
// The function will receive an array of students, the number of students, 
// and an integer from 0-3 which indicates which of the four major exams to check. 
// The function will iterate through the list of students to find their scores for 
// the specified exam. The function will store into an array of studIndex the idnumbers 
// and indices of the students who got a score
// that is at least 60% of the total score. Return the array of studIndex to the calling function. Let the member "index"
// of the array of studIndex contain a -1 to serve as a sentinel value.
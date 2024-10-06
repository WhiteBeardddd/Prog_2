#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char fName[32];
	char mi;
	char lName[16];
}fullName;

typedef struct{
	int score;			// Score of the student.
	int totalScore;		// Total score of the exam.
}exam;

typedef struct{
	exam exams[4];
	int numExams;
}grades;

typedef struct{
	fullName name;
	char idNum[9];
	char course[5];
	char gender;
	grades examScores;
}student;

typedef struct{
	char idNum[9];
	int index;
}studIndex;

studIndex* getExamPassers(student* students, int numStudents, int examNum) {
	// Allocate memory for the passers list
	studIndex* passers = (studIndex*)malloc((numStudents + 1) * sizeof(studIndex)); // +1 for sentinel
	int count = 0;

	// Iterate through students and check scores for the specified exam
	for (int i = 0; i < numStudents; i++) {
		int score = students[i].examScores.exams[examNum].score;
		int total = students[i].examScores.exams[examNum].totalScore;
		// If score is at least 60% of the total score
		if (score >= total * 0.6) {
			// Copy the student's ID and index to passers
			strcpy(passers[count].idNum, students[i].idNum);
			passers[count].index = i;
			count++;
		}
	}
	// Set sentinel value
	passers[count].index = -1;
	return passers;
}

void printPassers(studIndex* passers) {
	int i = 0;
	while (passers[i].index != -1) {
		printf("Student ID: %s, Index: %d\n", passers[i].idNum, passers[i].index);
		i++;
	}
}

int main(void) {
	student students[10] = {
	    {{"Alice", 'B', "Johnson"}, "22101234", "BSCS", 'F', {{{85, 100}, {75, 100}, {60, 100}, {90, 100}}, 4 }},
	    {{"Bob", 'C', "Smith"}, "20102345", "BSIT", 'M', {{{45, 100}, {70, 100}, {80, 100}, {65, 100}}, 4 }},
	    {{"Charlie", 'D', "Brown"}, "20103456", "BSIS", 'M', {{{78, 100}, {60, 100}, {85, 100}, {55, 100}}, 4 }},
	    {{"Diana", 'E', "Clark"}, "19104567", "BSCS", 'F', {{{60, 100}, {62, 100}, {90, 100}, {50, 100}}, 4 }},
	    {{"Ethan", 'F', "Lewis"}, "18105678", "BSIT", 'M', {{{70, 100}, {80, 100}, {90, 100}, {30, 100}}, 4 }},
	    {{"Fiona", 'G', "Martinez"}, "22106789", "BSIS", 'F', {{{85, 100}, {88, 100}, {90, 100}, {40, 100}}, 4 }},
	    {{"George", 'H', "Wilson"}, "21107890", "BSCS", 'M', {{{67, 100}, {75, 100}, {80, 100}, {90, 100}}, 4 }},
	    {{"Hannah", 'I', "Moore"}, "20108901", "BSIT", 'F', {{{55, 100}, {60, 100}, {85, 100}, {95, 100}}, 4 }},
	    {{"Ian", 'J', "Taylor"}, "19109012", "BSIS", 'M', {{{30, 100}, {40, 100}, {60, 100}, {70, 100}}, 4 }},
	    {{"Julia", 'K', "Anderson"}, "18101234", "BSCS", 'F', {{{90, 100}, {85, 100}, {70, 100}, {40, 100}}, 4 }}
	};
	int numStuds = sizeof(students) / sizeof(student);


	// Find and print passers for each exam
	for (int exam = 0; exam < 4; exam++) {
		printf("Passers for Exam %d:\n", exam + 1);
		studIndex* passers = getExamPassers(students, numStuds, exam);
		printPassers(passers);
		free(passers); // Free the allocated memory
		printf("\n");
	}

	return 0;
}

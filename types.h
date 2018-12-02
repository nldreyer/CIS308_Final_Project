#ifndef types_h
#define types_h

typedef enum { F, D, C, B, A } grade;

typedef struct Teacher {
    char classes[1][50];
    struct Course * course;
} Teacher;

typedef struct Student {
    float cum_gpa;
    struct Semester * semesterOne;
    struct Semester * semesterTwo;
    struct Semester * semesterThree;
    struct Semester * semesterFour;
    struct Semester * semesterFive;
    struct Semester * semesterSix;
    struct Semester * semesterSeven;
    struct Semester * semesterEight;
} Student;

typedef struct Semester {
    int enrolled;
    char classes[1][50];
    float gpa;
    
} Semester;

typedef struct Course {
    char name[50];
    char students[1][30];
} Course;

typedef struct LinkedList
{
	enum{Integer, Character, Float} type;
	union{
	int i;
	char c;
	float f;
	}value;
	struct LinkedList * next;
}LinkedList;
#endif 

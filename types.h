#ifndef types_h
#define types_h

typedef enum { F, D, C, B, A } grade;

typedef struct Teacher {
    char * classes[1];
    struct Course * course;
} Teacher;

typedef struct Student {
    float cum_gpa;
    struct Semester * semester;
} Student;

typedef struct Semester {
    int enrolled;
    char * classes[1];
    float gpa;
    struct Semester * next;
} Semester;

typedef struct Course {
    char name[50];
    char * students[1];
} Course;

#endif 

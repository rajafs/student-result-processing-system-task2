#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

#define SUBJECTS 5

struct Student {
    char id[20];
    char name[50];
    int marks[SUBJECTS];
    int total;
    float percentage;
    float cgpa;
    char grade[3];
};

int readStudent(FILE *fin, struct Student *s);
void printStudent(FILE *fout, struct Student *s);

#endif

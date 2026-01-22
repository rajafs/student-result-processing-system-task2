#include <string.h>
#include "result.h"

void computeResult(struct Student *s) {
    s->total = 0;

    for (int i = 0; i < SUBJECTS; i++)
        s->total += s->marks[i];

    s->percentage = s->total / 5.0;
    s->cgpa = s->percentage / 10.0;

    assignGrade(s->percentage, s->grade);
}

void assignGrade(float p, char grade[]) {
    if (p >= 90) strcpy(grade, "O");
    else if (p >= 85) strcpy(grade, "A+");
    else if (p >= 75) strcpy(grade, "A");
    else if (p >= 65) strcpy(grade, "B+");
    else if (p >= 60) strcpy(grade, "B");
    else if (p >= 55) strcpy(grade, "C");
    else if (p >= 50) strcpy(grade, "P");
    else strcpy(grade, "F");
}

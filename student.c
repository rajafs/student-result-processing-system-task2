#include <stdio.h>
#include <string.h>
#include "student.h"
#include "validation.h"

int readStudent(FILE *fin, struct Student *s) {
    int i;

    if (fscanf(fin, "%s ", s->id) != 1)
        return 0;

    fgets(s->name, sizeof(s->name), fin);
    s->name[strcspn(s->name, "\n")] = '\0';

    if (!validID(s->id) || !validName(s->name))
        return 0;

    for (i = 0; i < SUBJECTS; i++) {
        if (fscanf(fin, "%d", &s->marks[i]) != 1)
            return 0;
    }

    if (!validMarks(s->marks, SUBJECTS))
        return 0;

    return 1;
}

void printStudent(FILE *fout, struct Student *s) {
    fprintf(fout, "| %-9s | %-24s | %-5d | %-4.2f | %-5s |\n",
            s->id, s->name, s->total, s->cgpa, s->grade);
}

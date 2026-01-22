// #include <stdio.h>
// #include <stdlib.h>
// #include "student.h"
// #include "result.h"

// int main() {
//     FILE *fin, *fout;
//     struct Student *s;
//     int i, n;
//     float classAvg = 0.0, high, low;

//     fin = fopen("input.txt", "r");
//     fout = fopen("output.txt", "w");

//     if (!fin || !fout) {
//         printf("Error: Cannot open file\n");
//         return 1;
//     }

//     /* Read number of students */
//     fscanf(fin, "%d\n", &n);

//     /* Dynamic allocation for n students */
//     s = (struct Student *)malloc(n * sizeof(struct Student));
//     if (!s) {
//         printf("Memory allocation failed\n");
//         return 1;
//     }

//     for (i = 0; i < n; i++) {
//         if (!readStudent(fin, &s[i])) {
//             printf("Invalid input for student %d\n", i + 1);
//             return 1;
//         }
//         computeResult(&s[i]);
//         classAvg += s[i].cgpa;
//     }

//     classAvg /= n;
//     high = low = s[0].cgpa;

//     for (i = 1; i < n; i++) {
//         if (s[i].cgpa > high) high = s[i].cgpa;
//         if (s[i].cgpa < low) low = s[i].cgpa;
//     }

//     fprintf(fout, "+---------------------------------------------------------------+\n");
//     fprintf(fout, "| ID        | Name                     | Total | CGPA | Grade |\n");
//     fprintf(fout, "+---------------------------------------------------------------+\n");

//     for (i = 0; i < n; i++)
//         printStudent(fout, &s[i]);

//     fprintf(fout, "+---------------------------------------------------------------+\n");
//     fprintf(fout, "Class Avg CGPA: %.2f\nHighest CGPA: %.2f\nLowest CGPA: %.2f\n",
//             classAvg, high, low);

//     free(s);
//     fclose(fin);
//     fclose(fout);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "result.h"

int main() {
    FILE *fin, *fout;
    struct Student *s;
    int i, n;

    float classAvg = 0.0, high, low;

    /* Grade counters according to YOUR grading system */
    int countO = 0, countAplus = 0, countA = 0;
    int countBplus = 0, countB = 0, countC = 0;
    int countP = 0, countF = 0;

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    if (!fin || !fout) {
        printf("Error: Cannot open file\n");
        return 1;
    }

    /* Read number of students */
    fscanf(fin, "%d\n", &n);

    /* Dynamic allocation */
    s = (struct Student *)malloc(n * sizeof(struct Student));
    if (!s) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        if (!readStudent(fin, &s[i])) {
            printf("Invalid input for student %d\n", i + 1);
            return 1;
        }

        computeResult(&s[i]);
        classAvg += s[i].cgpa;

        /* Grade counting using STRING comparison */
        if (strcmp(s[i].grade, "O") == 0) countO++;
        else if (strcmp(s[i].grade, "A+") == 0) countAplus++;
        else if (strcmp(s[i].grade, "A") == 0) countA++;
        else if (strcmp(s[i].grade, "B+") == 0) countBplus++;
        else if (strcmp(s[i].grade, "B") == 0) countB++;
        else if (strcmp(s[i].grade, "C") == 0) countC++;
        else if (strcmp(s[i].grade, "P") == 0) countP++;
        else if (strcmp(s[i].grade, "F") == 0) countF++;
    }

    classAvg /= n;
    high = low = s[0].cgpa;

    for (i = 1; i < n; i++) {
        if (s[i].cgpa > high) high = s[i].cgpa;
        if (s[i].cgpa < low) low = s[i].cgpa;
    }
    fprintf(fout, "========== STUDENT RESULT PROCESSING SYSTEM ==========\n");
    fprintf(fout, "+---------------------------------------------------------------+\n");
    fprintf(fout, "| ID        | Name                     | Total | CGPA | Grade |\n");
    fprintf(fout, "+---------------------------------------------------------------+\n");

    for (i = 0; i < n; i++)
        printStudent(fout, &s[i]);

    fprintf(fout, "+---------------------------------------------------------------+\n");
    fprintf(fout,
            "Class Avg CGPA: %.2f\n"
            "Highest CGPA: %.2f\n"
            "Lowest CGPA: %.2f\n",
            classAvg, high, low);

    /* Grade summary */
    fprintf(fout, "\nGrade Summary:\n");
    fprintf(fout, "O  : %d\n", countO);
    fprintf(fout, "A+ : %d\n", countAplus);
    fprintf(fout, "A  : %d\n", countA);
    fprintf(fout, "B+ : %d\n", countBplus);
    fprintf(fout, "B  : %d\n", countB);
    fprintf(fout, "C  : %d\n", countC);
    fprintf(fout, "P  : %d\n", countP);
    fprintf(fout, "F  : %d\n", countF);

    free(s);
    fclose(fin);
    fclose(fout);
    printf("Successfuly data store in (output.txt)");
    return 0;
}

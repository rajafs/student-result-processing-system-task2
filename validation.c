#include <ctype.h>
#include "validation.h"

int validName(char name[]) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ')
            return 0;
    }
    return 1;
}

int validID(char id[]) {
    if (id[0] == '\0')
        return 0;

    for (int i = 0; id[i] != '\0'; i++) {
        if (!isalnum(id[i]))
            return 0;
    }
    return 1;
}

int validMarks(int marks[], int size) {
    for (int i = 0; i < size; i++) {
        if (marks[i] < 0 || marks[i] > 100)
            return 0;
    }
    return 1;
}

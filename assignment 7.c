#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    int marks[3];
    int total;
    float percentage;
};

/* Input buffer me bacha hua newline/extra characters saaf karta hai */
void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Valid integer lene ke liye (min se max ke beech) */
int readInt(const char *prompt, int min, int max) {
    int val;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &val) == 1 && val >= min && val <= max) {
            clearBuffer();
            return val;
        }
        printf("Invalid input! %d se %d ke beech number daalo.\n", min, max);
        clearBuffer();
    }
}

int main() {
    struct Student s[MAX];
    int n, i, j;
    char prompt[40];

    n = readInt("Enter the number of students: ", 1, MAX);

    for (i = 0; i < n; i++) {
        printf("\n--- Student %d ---\n", i + 1);

        /* Roll number - alag line */
        s[i].roll = readInt("Enter roll number: ", 1, 999999);

        /* Naam - alag line (space allowed) */
        printf("Enter name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';

        /* Marks - har subject alag line */
        s[i].total = 0;
        for (j = 0; j < 3; j++) {
            sprintf(prompt, "Enter marks of subject %d: ", j + 1);
            s[i].marks[j] = readInt(prompt, 0, 100);
            s[i].total += s[i].marks[j];
        }
        s[i].percentage = s[i].total / 3.0;
    }

    /* Tabular output */
    printf("\n");
    printf("+---------+----------------------+------------+------------+------------+--------+------------+\n");
    printf("| %-7s | %-20s | %-10s | %-10s | %-10s | %-6s | %-10s |\n",
           "Roll No", "Name", "Subject: 1", "Subject: 2", "Subject: 3", "Total", "Percentage");
    printf("+---------+----------------------+------------+------------+------------+--------+------------+\n");

    for (i = 0; i < n; i++) {
        printf("| %-7d | %-20s | %-10d | %-10d | %-10d | %-6d | %-10.2f |\n",
               s[i].roll, s[i].name,
               s[i].marks[0], s[i].marks[1], s[i].marks[2],
               s[i].total, s[i].percentage);
    }

    printf("+---------+----------------------+------------+------------+------------+--------+------------+\n");

    return 0;
}

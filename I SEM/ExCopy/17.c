/*PROGRAM CODE -->Write a C program to input Name, roll no. and percentage of n students. Calculate average percentages of class and print the details of all students having percentage greater than or equal to average percentage

  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int rollNo;
    float percentage;
};

void printStudentsAboveAverage(struct Student* students, int n);

int main() {
    int n;
    float totalPercentage = 0.0, averagePercentage;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    // Input student details
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter name: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNo);
        printf("Enter percentage: ");
        scanf("%f", &students[i].percentage);

        totalPercentage += students[i].percentage;
    }

    averagePercentage = totalPercentage / n;

    printf("\n--- Students with Percentage >= Average ---\n");
    printStudentsAboveAverage(students, n);

    free(students);

    return 0;
}

void printStudentsAboveAverage(struct Student* students, int n) {
    for (int i = 0; i < n; i++) {
        if (students[i].percentage >= averagePercentage) {
            printf("\nName: %s\n", students[i].name);
            printf("Roll No: %d\n", students[i].rollNo);
            printf("Percentage: %.2f\n", students[i].percentage);
        }
    }
}

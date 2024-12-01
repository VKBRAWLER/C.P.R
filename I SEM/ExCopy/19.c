/*PROGRAM CODE --> a C program to accept records of employees.Calculate total salary as-total salary=basic+hra+dada=10% of basic     hra=5% of basic salaryDisplay age, total salary of employee in descending order on the basis of total salary. Create separate function for input & display.

  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/
#include <stdio.h>
#include <string.h>

struct emp {
    char name[20];
    int age;
    int basic;
};

void inputEmployee(struct emp* e);
void displayEmployees(struct emp* employees, int n);
void calculateTotalSalary(struct emp* employees, int n);
void sortEmployees(struct emp* employees, int n);

int main() {
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct emp employees[n];

    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        inputEmployee(&employees[i]);
    }

    calculateTotalSalary(employees, n);
    sortEmployees(employees, n);
    displayEmployees(employees, n);

    return 0;
}

void inputEmployee(struct emp* e) {
    printf("Enter name: ");
    scanf(" %[^\n]s", e->name);
    printf("Enter age: ");
    scanf("%d", &(e->age));
    printf("Enter basic salary: ");
    scanf("%d", &(e->basic));
}

void calculateTotalSalary(struct emp* employees, int n) {
    for (int i = 0; i < n; i++) {
        float da = 0.10 * employees[i].basic;
        float hra = 0.05 * employees[i].basic;
        employees[i].basic += da + hra;
    }
}

void sortEmployees(struct emp* employees, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (employees[j].basic < employees[j + 1].basic) {
                struct emp temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

void displayEmployees(struct emp* employees, int n) {
    printf("\n--- Employee Details ---\n");
    printf("Age\tTotal Salary\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", employees[i].age, employees[i].basic);
    }
}

/*PROGRAM CODE --> Define a structure data type called time_struct containing three members integer hours, integer minutes, and integer seconds. Draw a flowchart and write a C program that would assign values to the individual members and display the time in the following form: 16:40:51. Create functions insert() and display() for input and Output.
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/
#include <stdio.h>

struct time_struct {
    int hours;
    int minutes;
    int seconds;
};

void insert(struct time_struct* t);
void display(const struct time_struct* t);

int main() {
    struct time_struct time;

    insert(&time);
    display(&time);

    return 0;
}

void insert(struct time_struct* t) {
    printf("Enter hours: ");
    scanf("%d", &(t->hours));
    printf("Enter minutes: ");
    scanf("%d", &(t->minutes));
    printf("Enter seconds: ");
    scanf("%d", &(t->seconds));
}

void display(const struct time_struct* t) {
    printf("Time: %02d:%02d:%02d\n", t->hours, t->minutes, t->seconds);
}

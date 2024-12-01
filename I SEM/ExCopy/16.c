

/*PROGRAM CODE --> C program to enter name, roll no., marks in 4 subjects of n students then calculate percentage for each student and print name and roll no. of student with highest percentage.
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/
#include <stdio.h>
struct student
{
    char name[20];
    int roll_no;
    int marks[4];
    float percentage;
};
void calpercentage(struct student s1)
{
    int tmarks = 0;
    for (int i = 0; i < 4; i++)
    {
        tmarks = tmarks + s1.marks[i];
    }
    s1.percentage = (float)tmarks / 4;
}
int main()
{
    int n;
    printf("enter the value for how many student data you eant to enter :");
    scanf("%d", &n);
    struct student s1[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter the name of student %d", i + 1);
        scanf("%s", &s1[i].name);
        printf("enter the roll number of student %d:", i + 1);
        scanf("%d", s1[i].roll_no);
        for (int j = 0; j < 4; j++)
        {
            printf("enter the marks  student %d of subject %d ", i + 1, j + 1);
            scanf("%d", s1[i].marks[j]);
        }
        printf("The percentage of student %d is", i + 1);
        calpercentage(s1[i]);
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (s1[i].percentage > s1[maxIndex].percentage)
        {
            maxIndex = i;
        }
    }

    printf("\nStudent with highest percentage:\n");
    printf("Name: %s\n", s1[maxIndex].name);
    printf("Roll No: %d\n", s1[maxIndex].roll_no);
    printf("Percentage: %.2f\n", s1[maxIndex].percentage);

    return 0;
}

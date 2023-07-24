/*PROGRAM CODE --> C program to store integers to a file then read all integers from files and store all even numbers to even.dat file and odd numbers to odd.dat file.
 1 Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE*/
#include <stdio.h>
int main()
{
    FILE *fp1, *fp2, *fp3;
    int num;
    fp1 = fopen("integer.dat", "w");
    if (fp1 == NULL)
    {
        printf("File not created");
    }
    printf("enter the integer :");
    while (num != NULL)
    {
        scanf("%d", &num);
        putw(num, fp1);
    }
    fclose(fp1);
    fp1 = fopen("integer.dat", "r");
    fp2 = fopen("even.dat", "w");
    fp3 = fopen("odd.dat", "w");
    if (fp1 == NULL || fp2 == NULL || fp3 == NULL)
    {
        printf("file not copied....");
        return 0;
    }
    while ((num = getw(fp1)) != NULL)
    {
        if (num % 2 == 0)
        {
            putw(num, fp2);
        }
        else
        {
            putw(num, fp3);
        }
    }
    printf("file copied....");
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}
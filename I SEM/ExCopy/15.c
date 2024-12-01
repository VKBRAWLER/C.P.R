

/*PROGRAM CODE --> C program to concatenate two strings using pointer and function.
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/
#include <stdio.h>
#include <stdio.h>
void myconcat(char *, char *);
int main()
{
    char s1[100], s2[100];
    printf("enter the string s1 :");
    gets(s1);
    printf("enter the string s2 :");
    gets(s2);
    myconcat(s1, s2);
    printf("After the concatenation string is :");
    puts(s1);
}
void myconcat(char *s1, char *s2)
{
    int i = 0, l1, l2;
    l1 = strlen(s1);
    l2 = strlen(s2);
    while (*(s1 + i) != '\0')
    {
        *(s1 + i + l1) = *(s2 + i);
        i++;
    }
    *(s1 + l1 + l2) = '\0';
}

/*
OUTPUT:
enter the string s1 :Graphic
enter the string s2 : Era
After the concatenation string is :Graphic Era
*/
/*PROGRAM CODE --> C program to copy a string using pointer and function.
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/
#include <stdio.h>
void mystrcpy(char *, char *);
int main()
{
    char s1[100], s2[100];
    printf("Enter the string s1 :");
    gets(s1);
    mystrcpy(s1, s2);
    printf("The string copied in s2 is :");
    puts(s2);
    return 0;
}
void mystrcpy(char *s1, char *s2)
{
    int i = 0;
    while (*(s1 + i) != '\0')
    {
        *(s2 + i) = *(s1 + i);
        i++;
    }
    *(s2 + i) = '\0';
}

/*OUTPUT:-->
 Enter the string s1 :Hello
 The string copied in s2 is :Hello
*/
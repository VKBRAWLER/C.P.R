/*PROGRAM CODE --> C program to reverse a string using function.
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/

#include <stdio.h>
void myreverse(char[]);
int main()
{
    char str[100];
    printf("enter the String :");
    gets(str);
    myreverse(str);
    printf("The entered string after reversing is :");
    puts(str);
    return 0;
}

void myreverse(char str[100])
{
    int i = 0, j, length = 0;
    char temp;
    while (str[i] != '\0')
    {
        length = length + 1;
        i++;
    }
    for (i = 0, j = length - 1; i <= j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

/*
OUTPUT:
enter the String :Graphic era
The entered string after reversing is :are cihparG
*/
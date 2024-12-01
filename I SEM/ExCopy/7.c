/*PROGRAM CODE --> C program to toggle the case of the given string.
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/
#include <stdio.h>
int main()
{
    char str[100];
    int i = 0;
    printf("enter the String :");
    gets(str);
    printf("The entered string before we toggle the case is :");
    puts(str);
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        i++;
    }
    printf("The entered string after we toggle the case is :");
    puts(str);
}

/*OUTPUT:-->
 enter the String :hELLO sIR
The entered string before we toggle the case is :hELLO sIR
The entered string after we toggle the case is :Hello Sir
*/
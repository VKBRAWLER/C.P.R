/*PROGRAM CODE --> C program to count the number of vowels and consonant in a string entered by user.
   Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/

#include <stdio.h>
#include <string.h>
int main()
{
    int v = 0, c = 0;
    char string[100];
    printf("enter the string :");
    gets(string);
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')
        {
            v++;
        }
        else if (string[i] >= 'a' && string[i] <= 'z' || string[i] >= 'A' || string[i] <= 'Z')
        {
            c++;
        }
    }
    printf("The total number of vowels in a string is %d\n", v);
    printf("The total number of consonant in a string is %d\n", c);
    return 0;
}

/*OUTPUT:-->
 enter the string :Hello
 The total number of vowels in a string is 2
 The total number of consonant in a string is 3
*/
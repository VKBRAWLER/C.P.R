/*PROGRAM CODE --> C program to check characters of a string whether it is uppercase, lowercase, digit or special character.
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/

#include <stdio.h>
int main()
{
  char ch[100];
  printf("enter the String :");
  gets(ch);
  for (int i = 0; ch[i] != '\0'; i++)
  {
    if (ch[i] >= 'a' && ch[i] <= 'z')
    {
      printf("The entered character %c is in lower case", ch[i]);
      printf("\n");
    }
    else if (ch[i] >= 'A' && ch[i] <= 'Z')
    {
      printf("The entered character %c is in Upper case", ch[i]);
      printf("\n");
    }
    else if (ch[i] >= '0' && ch[i] <= '9')
    {
      printf("The entered character %c is a Digit", ch[i]);
      printf("\n");
    }
    else if (ch[i] == ' ')
    {
      continue;
    }
    else
    {
      printf("The entered character %c is a Special character");
      printf("\n");
    }
  }
  return 0;
}

/*OUTPUT:-->
 enter the String :Hello 91
The entered character H is in Upper case
The entered character e is in lower case
The entered character l is in lower case
The entered character l is in lower case
The entered character o is in lower case
The entered character 9 is a Digit
The entered character 1 is a Digit
*/
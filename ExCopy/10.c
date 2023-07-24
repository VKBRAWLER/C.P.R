/*PROGRAM CODE --> C program to compare two strings using function.
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/

#include <stdio.h>
int mycompare(char[], char[]);
int main()
{
  char s1[100], s2[100];
  int c;
  printf("Enter the string s1 :");
  gets(s1);
  printf("Enter the string s2 :");
  gets(s2);
  c = mycompare(s1, s2);
  if (c == 0)
  {
    printf("Both the strings are equal");
  }
  else
  {
    printf("Both the strings are not equal");
  }
  return 0;
}

int mycompare(char s1[100], char s2[100])
{
  int i = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
  {
    if (s1[i] > s2[i])
    {
      return 1;
    }
    else if (s1[i] < s2[i])
    {
      return -1;
    }
    i++;
  }
  return 0;
}

/*
OUTPUT:
Enter first string:graphic
Enter second string:graphic
Strings are equal
*/
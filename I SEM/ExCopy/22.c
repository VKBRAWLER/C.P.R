/*PROGRAM CODE --> C program to write characters to a file then read all characters from file and store all vowels, consonants, digits and special characters to 4 separate files.
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/
#include <stdio.h>
int main()
{
  FILE *fp1, *fp2, *fp3, *fp4, *fp5;
  char ch;
  fp1 = fopen("MASTER.txt", "w");
  if (fp1 == NULL)
  {
    printf("file creation error");
  }
  while ((ch = getc(stdin)) != EOF)
  {
    fprintf(fp1, "%c", ch);
  }
  fclose(fp1);
  fp1 = fopen("MASTER.txt", "r");
  fp2 = fopen("vowel.txt", "w");
  fp3 = fopen("consonants.txt", "w");
  fp4 = fopen("digits.txt", "w");
  fp5 = fopen("special.txt", "w");
  if (fp1 == NULL || fp2 == NULL || fp3 == NULL || fp4 == NULL || fp5 == NULL)
  {
    printf("Content not copied to given files...");
    return 0;
  }
  while ((ch = getc(fp1)) != EOF)
  {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
      fprintf(fp2, "%c", ch);
    }
    else if (ch >= 'a' && ch <= 'z' || ch >= 'A' || ch <= 'Z')
    {
      fprintf(fp3, "%c", ch);
    }
    else if (ch >= '0' && ch <= '9')
    {
      fprintf(fp4, "%c", ch);
    }
    else
    {
      fprintf(fp5, "%c", ch);
    }
  }
  printf("File copied to destinated files..");
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
  fclose(fp5);
  return 0;
}

/*OUTPUT :-->
 Hello
 ^Z
 File copied to destinated files..s
*/
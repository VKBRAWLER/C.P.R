

/*PROGRAM CODE --> C program to write alphabets to a file then read all alphabets from file and store in another file by converting all alphabets to UPPERCASE.
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/
#include <stdio.h>
int main()
{
    FILE *fp1, *fp2;
    char ch;
    fp1 = fopen("alphabet.txt", "w");
    if (fp1 == NULL)
    {
        printf("file creation error ");
    }
    printf("enter the characters :");
    while ((ch = getchar()) != EOF)
    {
        putc(ch, fp1);
    }
    fclose(fp1);
    fp1 = fopen("alphabet.txt", "r");
    fp2 = fopen("upper_alpha.txt", "w");
    if (fp1 == NULL || fp2 == NULL)
    {
        printf("file not copied");
    }
    while ((ch = getc(fp1)) != EOF)
    {
        ch = toupper(ch);
        putc(ch, fp2);
    }
    printf("File copied...");
    fclose(fp1);
    fclose(fp2);
    return 0;
}

/*OUTPUT :-->
  enter the characters :Hello
  ^Z
  File copied...
*/
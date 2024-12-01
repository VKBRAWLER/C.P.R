/*PROGRAM CODE--> To check whether the inputted number is armstrong or not



  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE*/
#include <stdio.h>
int armcheck(int *);
int main()
{
    int n, check, num;
    printf("enter the number you want to check armstrong condition for :");
    scanf("%d", &n);
    num = n;
    check = armcheck(&n);
    if (check == num)
    {
        printf("The number %d is an armstrong number", num);
    }
    else
    {
        printf("The number %d is not an armstrong number", num);
    }
    return 0;
}

int armcheck(int *n)
{
    int sum = 0, rem;
    while ((*n) != 0)
    {
        rem = (*n) % 10;
        sum = sum + rem * rem * rem;
        *n = (*n) / 10;
    }
    return sum;
}
/*enter the number you want to check armstrong condition for :153
The number 153 is an armstrong number*/


/*PROGRAM CODE --> C program to sort the numbers in an array using pointer and function.
 
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/
#include <stdio.h>
void sort(int *, int);
int main()
{
    int arr[100], n;
    printf("enter the range of array :");
    scanf("%d", &n);
    printf("enter the elements of array :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    printf("The elements of array after sorting is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
void sort(int *a, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (*(a + j) > *(a + j + 1))
            {
                temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
            }
        }
    }
}

/*OUTPUT :-->
  enter the range of array :5
  enter the elements of array :1
  32
  23
  21
  5
  The elements of array after sorting is :
  1     5       21      23      32
*/
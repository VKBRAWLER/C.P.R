

/*PROGRAM CODE --> C program to search an element in an array using pointer and function.
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/

#include <stdio.h>
void search(int *, int, int);
int main()
{
    int arr[100], n, key;
    printf("enter the range of array :");
    scanf("%d", &n);

    printf("enter the element of array :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the key the number you want to find :");
    scanf("%d", &key);
    search(arr, n, key);
}

void search(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (*(arr + i) == key)
        {
            printf("element found at index %d", i);
            // return 0;
            break;
        }
        else
        {
            continue;
        }
    }
}

/*OUTPUT :-->
  enter the range of array :5
  enter the elements of array :1
  2
  3
  4
  5
  enter the key the number you want to find :3
  element found at index 2
*/

/*PROGRAM CODE--> C program to print average of elements of array using pointer and function.
  
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
*/

#include <stdio.h>
float checkavg(int *, int);
int main()
{
  int arr[100], n;
  float average;
  printf("enter the range of array :");
  scanf("%d", &n);
  printf("enter the elements of array :\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  average = checkavg(arr, n);
  printf("average of the elements of array is %f", average);
  return 0;
}
float checkavg(int *a, int n)
{
  int sum = 0;
  float avg;
  for (int i = 0; i < n; i++)
  {
    sum = sum + *(a + i);
  }
  avg = (float)sum / n;
  return avg;
}

/*OUTPUT :-->
  enter the range of array :5
  enter the elements of array :1
  2
  3
  4
  5
  average of the elements of array is 3.0000
*/
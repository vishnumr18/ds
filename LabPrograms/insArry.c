#include <stdio.h>
#include <string.h>
int a[20], n = 0, i, ele, pos;

void insert();
void delete();
void display();

void insert()
{
  printf("Enter the position:\t\n");
  scanf("%d", &pos);
  printf("Enter the element:\t\n");
  scanf("%d", &ele);
  for (i = n; i >= pos; i--)
  {
    a[i] = a[i - 1];
  }
  a[pos - 1] = ele;
  n = n + 1;
  return;
}

void delete()
{
  printf("Enter the position:\t\n");
  scanf("%d", &pos);
  ele = a[pos - 1];
  for (i = pos - 1; i < n - 1; i++)
    a[i] = a[i + 1];
  n = n - 1;
  printf("The deleted element:%d \n", ele);
  return;
}

void display()
{
  printf("The elements of the array are:\n");
  for (i = 0; i < n; i++)
  {
    printf("%d\t", a[i]);
  }
  return;
}

int main()
{
  int ch;
  printf("Enter the no of elements:\t\n");
  scanf("%d", &n);
  printf("Enter the elements:\t");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  while (1)
  {
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter Your choice:\t");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      insert();
      break;
    case 2:
      delete ();
      break;
    case 3:
      display();
      break;
    default:
      exit(0);
    }
  }
}
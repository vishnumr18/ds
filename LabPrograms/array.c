#include <stdio.h>
#include <stdlib.h>

int create();
int display();
int a[10], n;

int create()
{
  int i;
  printf("Enter the No. elements:\t");
  scanf("%d", &n);
  printf("Enter the Elements:\t");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  return;
}

int display()
{
  int i;
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
  while (1)
  {
    printf("\n1.Creat\n2.Display\n3.Exit\nEnter your choice: \t");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      create();
      break;
    case 2:
      display();
      break;
    case 3:
      exit(0);
      break;
    default:
      exit(0);
    }
  }
  return 0;
}
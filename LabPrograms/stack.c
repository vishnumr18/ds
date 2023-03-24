#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int push();
int pop();
int display();

int top = -1;
int s[MAX];

int main()
{
  int ch;
  while (1)
  {
    printf("\n1.Push\n2.Pop\n3.display\nEnter choice:\t");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    default:
      exit(0);
    }
  }
}

int push()
{
  int itm;
  if (top == MAX - 1)
    printf("overflow\n");
  else
  {
    printf("Enter itema:");
    scanf("%d", &itm);
    top++;
    s[top] = itm;
  }
}

int pop()
{
  if (top == -1)
    printf("underflow\n");
  else
  {
    printf("The deleted element is %d", s[top]);
    top--;
  }
}

int display()
{
  int i;
  if (top == -1)
    printf("Undeerflow\n");
  else
  {
    printf("Elements are:\t\n");
    for (i = top; i >= 0; i--)
      printf("%d\t", s[i]);
  }
}
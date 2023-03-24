#include <stdio.h>
int tower(int, char, char, char);
int main()
{
  int n;
  printf("Enter the No. of disc:\t");
  scanf("%d", &n);
  tower(n, 'a', 'b', 'c');
}

int tower(int n, char src, char intre, char des)
{
  if (n == 1)
  {
    printf("Move the disc %c to %c\n", src, des);
  }
  else
  {
    tower(n - 1, src, des, intre);
    printf("Move the disc %d form %c to %c\n", n, src, des);
    tower(n - 1, intre, src, des);
  }
  return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

double comt(char sym, double op1, double op2)
{
  switch (sym)
  {
  case '+':
    return op1 + op2;
  case '-':
    return op1 - op2;
  case '*':
    return op1 * op2;
  case '/':
    return op1 / op2;
  case '^':
    return pow(op1, op2);
  default:
    return 0;
  }
}
int main()
{
  double s[20], op1, op2, res;
  int top = -1;
  int i;
  char postfix[20], sym;
  printf("\nEnter the expression: ");
  gets(postfix);
  for (i = 0; i, strlen(postfix); i++)
  {
    sym = postfix[i];
    if (isdigit(sym))
    {
      s[++top];
      sym = '\0';
    }
    else
    {
      op2 = s[top--];
      op1 = s[top--];
      res = comt(sym, op1, op2);
      s[++top] = res;
    }
    res = s[top--];
    printf("\nThe result is result %f\n", res);
  }
}
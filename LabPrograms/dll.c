#include <stdio.h>
#include <stdlib.h>

struct node
{
  int info;
  struct node *llink;
  struct node *rlink;
};

typedef struct node *NODE;
NODE first = NULL;
int count = 0;

NODE insertFront(NODE first)
{
  NODE temp;
  int itm;
  temp = (NODE)malloc(sizeof(struct node));
  printf("enter the element: \t");
  scanf("%d", &itm);
  temp->info = itm;
  temp->rlink = temp->llink = NULL;
  if (first == NULL)
  {
    return temp;
  }
  first->llink = temp;
  temp->rlink = first;
  return temp;
}

NODE deleteRear(NODE first)
{
  NODE cur, prev;
  if (first == NULL)
  {
    printf("the node empty\n");
    return NULL;
  }
  if (first->rlink == NULL)
  {
    printf("the deleted elemet= %d", first->info);
    return NULL;
  }
  cur = first;
  prev = NULL;
  while (cur->rlink != NULL)
  {
    prev = cur;
    cur = cur->rlink;
    count++;
  }
  printf("The deleted element is %d", cur->info);
  prev->rlink = NULL;
  free(cur);
  return first;
}

void display(NODE first)
{
  NODE cur;
  if (first == NULL)
  {
    printf("the list empty\n");
    return first;
  }
  cur = first;
  printf("THe elements are:\n");
  while (cur != NULL)
  {
    printf("%d\t", cur->info);
    cur = cur->rlink;
  }
  printf("\n");
}

NODE insertRear(NODE first)
{
  NODE temp, cur;
  int itm;
  printf("Enter the element:\t");
  scanf("%d", &itm);
  temp = (NODE)malloc(sizeof(struct node));
  temp->info = itm;
  temp->llink = temp->rlink = NULL;
  if (first == NULL)
  {
    return temp;
  }
  cur = first;
  while (cur->rlink != NULL)
  {
    count++;
    cur = cur->rlink;
  }
  cur->rlink = temp;
  temp->llink = cur;
  return first;
}

int main()
{
  int ch;
  while (1)
  {
    printf("\n1.queue\n2.stack\n3.count\n4.exit\nEnter choice:\t");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("\n--queue--\n");
      int cho;
      while (1)
      {
        printf("\n1.insert front\n2.delete rear\n3.display\n4.exit\n");
        scanf("%d", &cho);
        switch (cho)
        {
        case 1:
          first = insertFront(first);
          break;
        case 2:
          first = deleteRear(first);
          break;
        case 3:
          display(first);
          break;
        default:
          exit(0);
        }
      }

      break;
    case 2:
      printf("\n--Stacks--\n");
      int c;
      while (1)
      {
        printf("\n1.insert rear\n2.delete rear\n3.display\n4.exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
          first = insertRear(first);
          break;
        case 2:
          first = deleteRear(first);
          break;
        case 3:
          display(first);
          break;
        default:
          exit(0);
        }
      }
      break;

    case 3:
      printf("THe number of nodes are %d", count);
      break;
    default:
      exit(0);
    }
  }
}
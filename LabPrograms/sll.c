#include <stdio.h>
#include <stdlib.h>

struct node
{
  int info;
  struct node *link;
};

typedef struct node *NODE;
NODE first1 = NULL, first2 = NULL;

NODE getNode()
{
  NODE x;
  x = (NODE)malloc(sizeof(struct node));
  if (x == NULL)
  {
    printf("Out of memory\n");
    exit(0);
  }
  return x;
}

NODE insertFront(int key, NODE first)
{
  NODE temp;
  temp = getNode();
  temp->info = key;
  temp->link = first;
  return temp;
}

NODE deleteFront(NODE first)
{
  NODE temp;
  if (first == NULL)
  {
    printf("List is empty\n");
    return NULL;
  }
  temp = first;
  temp = temp->link;
  printf("The deleted element is %d\n", first->info);
  free(first);
  return temp;
}

void display(NODE first)
{
  NODE cur;
  if (first == NULL)
  {
    printf("The node is empty\n");
    return;
  }
  printf("The content of list are:\n");
  cur = first;
  while (cur != NULL)
  {
    printf("%d\t", cur->info);
    cur = cur->link;
  }
  printf("\n");
}

void search(NODE first)
{
  NODE temp;
  int itm, i = 0;
  temp = first;
  if (temp == NULL)
  {
    printf("list is empty\n");
    return;
  }
  else
  {
    printf("Enter the key elemt:\t");
    scanf("%d", &itm);
    while (temp != NULL)
    {
      if (temp->info == itm)
        printf("Element found\n");
      else
        printf("ELement not found\n");
      i++;
      temp = temp->link;
    }
  }
}

NODE concat(NODE first1, NODE first2)
{
  int one, two;
  printf("Enter the number of elements in first1 list:\t");
  scanf("%d", &one);
  printf("enter %d elements:\t", one);
  for (int i = 0; i < one; i++)
  {
    NODE temp = getNode();
    scanf("%d", &temp->info);
    first1 = insertFront(temp->info, first1);
  }

  printf("Enter the number of elements in first2 list:\t");
  scanf("%d", &two);
  printf("enter %d elements:\t\n", two);
  for (int i = 0; i < two; i++)
  {
    NODE temp = getNode();
    scanf("%d", &temp->info);
    first2 = insertFront(temp->info, first2);
  }

  printf("list1\n");
  display(first1);
  printf("list2\n");
  display(first2);
  NODE cur = first1;
  while (cur->link != NULL)
    cur = cur->link;
  cur->link = first2;
  printf("The concatinated list is:\n");
  cur = first1;
  while (cur != NULL)
  {
    printf("%d ", cur->info);
    cur = cur->link;
  }
}

int main()
{
  NODE first = NULL;
  int ch, itm;
  while (1)
  {
    printf("\n1.insert front\n2.delete front\n3.display\n4.lineat seatrch \n5.concatinate\n6.exit\nEnter yhour choice\t");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("enter itm:\t");
      scanf("%d", &itm);
      first = insertFront(itm, first);
      break;
    case 2:
      first = deleteFront(first);
      break;
    case 3:
      display(first);
      break;
    case 4:
      search(first);
      break;
    case 5:
      concat(first1, first2);
      break;
    default:
      exit(0);
    }
  }
}
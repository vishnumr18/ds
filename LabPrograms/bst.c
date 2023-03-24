#include <stdio.h>
#include <stdlib.h>

struct node
{
  int info;
  struct node *llink;
  struct node *rlink;
};

typedef struct node *NODE;
NODE troot;

void inorder(NODE troot)
{
  if (troot != NULL)
  {
    inorder(troot->llink);
    printf("%d ", troot->info);
    inorder(troot->rlink);
  }
}

void preorder(NODE troot)
{
  if (troot != NULL)
  {
    printf("%d ", troot->info);
    preorder(troot->llink);
    preorder(troot->rlink);
  }
}

void postorder(NODE troot)
{
  if (troot != NULL)
  {
    postorder(troot->llink);
    postorder(troot->rlink);
    printf("%d ", troot->info);
  }
}

void insert(int itm)
{
  NODE temp, cur, prev;
  temp = (NODE)malloc(sizeof(struct node));
  temp->llink = temp->rlink = NULL;
  temp->info = itm;
  if (troot == NULL)
  {
    troot = temp;
    return;
  }
  else
  {
    prev = NULL;
    cur = troot;
    while (cur != NULL)
    {
      prev = cur;
      if (itm <= cur->info)
        cur = cur->llink;
      else
        cur = cur->rlink;
    }
    if (itm <= prev->info)
      prev->llink = temp;
    else
      prev->rlink = temp;
  }
}

void create()
{
  int i, n, itm;
  printf("Enter the no of elements:\n");
  scanf("%d", &n);
  printf("Enter %d elements:\n", n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &itm);
    insert(itm);
  }
}

int main()
{
  int ch;
  while (1)
  {
    printf("\n1.create\n2.inorder\n3.preorder\n4.postprder\nEnter your choice\t");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      create();
      break;
    case 2:
      inorder(troot);
      break;
    case 3:
      preorder(troot);
      break;
    case 4:
      postorder(troot);
      break;
    default:
      exit(0);
    }
  }
}
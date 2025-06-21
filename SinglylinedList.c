// implemenation of a singly linked list operation using c

#include <stdio.h>
#include <stdlib.h> //use for malloc function

struct node
{
  int data;
  struct node *next; // it is a pointer to a node and nothing is nothing but struct itself
};
struct node *first = NULL, *last = NULL;

void insert_at_begining(int element);
void insertion_at_end(int element);
void insert_at_pos(int index, int element);
void display()
{
  struct node *temp;
  temp = first;
  if (temp == NULL) // checks if the first list is empty
  {
    printf("The list is empty");
  }

  else
    while (temp != NULL) // iterates trough all the nodes
    {
      printf("%d>>", temp->data);
      temp = temp->next; // temp goes to the next list as it is a pointer and it can access from any location
    }
  printf("NULL\n");
}

int main()
{
  insert_at_begining(10);
  display();
  insert_at_begining(13);
  display();
  insertion_at_end(11);
  display();
  insert_at_pos(2, 500);
  display();
}

void insert_at_begining(int element)
{
  struct node *NewNode;
  NewNode = (struct node *)malloc(sizeof(struct node));
  NewNode->data = element;
  NewNode->next = NULL;
  if (first == NULL)
  {
    first = last = NewNode; // assign the address of the NewNode mean now both of them point to the same struc
  }

  else // node is already there
  {
    NewNode->next = first; // so newnode should point the previous first node;
    first = NewNode;       // update the first to the NewNode now
    printf("%d was inserted at the begining\n", NewNode->data);
  }
}
void insertion_at_end(int element)
{
  struct node *NewNode;
  NewNode = (struct node *)malloc(sizeof(struct node));
  NewNode->data = element;
  NewNode->next = NULL;
  if (first == NULL)
  {
    first = last = NewNode;
  }

  else
  {
    last->next = NewNode;
    last = NewNode;
    printf("%d was inserted at the end\n", NewNode->data);
  }
}

void insert_at_pos(int index, int element)
{
  struct node *NewNode;
  NewNode = (struct node *)malloc(sizeof(struct node));
  NewNode->data = element;
  NewNode->next = NULL;
  if (index < 0)
  {
    printf("Invalid Index");
  }
  else if (index == 1)
  {
    insert_at_begining(element);
  }

  else
  {
    struct node *temp;
    temp = first;
    for (int i = 1; i < (index - 1); i++)
    {
      temp = temp->next;
    }
    if (temp == last)
    {
      insertion_at_end(element);
    }
    else
    {
      NewNode->next = temp->next;
      temp->next = NewNode;
      printf("%d was inserted\n", NewNode->data);
    }
  }
}
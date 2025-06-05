#include <stdio.h>

#include <string.h>

#define Max 5

struct stack
{
  int top;
  int data[Max];
};

int isFull(struct stack *s)
{
  return (s->top == Max - 1 ? 1 : 0);
}

int isEmpty(struct stack *s)
{
  return (s->top == -1 ? 1 : 0);
}

void Push(struct stack *s, int element)
{
  s->top++;
  s->data[s->top] = element;
}

int Pop(struct stack *s)
{
  int pop = s->data[s->top];
  s->top--;
  return pop;
}

int Peek(struct stack *s, int index)
{
  return s->data[index]; //(*s).data
}

char pushOperator(struct stack *s, char opr)
{
  s->top++;
 return s->data[s->top]= opr;

}
int main()
{
  int choice, element, n, index;
  char opr;
  struct stack s;
  s.top = -1;

  do
  {
    printf("1:Push \n2:Pop \n3:Peek \n4:Exit\n5:Operator\n");
    printf(">>");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:

      if (isFull(&s))
      {
        printf("stack overflow \n");
      }

      else
      {
        printf(">>enter the element::");

        scanf("%d", &element);
        Push(&s, element);
        printf(">>element pushed \n\n");
      }
      break;

    case 2:
      if (isEmpty(&s))
      {
        printf(">>stack underflow:\n");
      }
      else
      {
        printf(">>the poped element is %d", Pop(&s));

        printf("\n\n");
      }
      break;

    case 3:
    {
      if (isEmpty(&s))
      {
        printf(">>no element in the stack:\n");
      }
      else

      {
        n = s.top + 1;
        printf("enter the index which you want to pick::");
        scanf("%d", &index);

        if (index > 0 && index <= n)
        {

          printf(">>the elemennt is %d", Peek(&s, (index - 1)));

          printf("\n\n");
        }
        else
        {
          printf("give the correct index \n");
        }
      }
      break;
    }
    case 4:
      printf(">>Successfull exited\n");
      break;

case 5:
printf("enter the Operator:\n");
scanf("%c",&opr);
printf("%c",opr);

break;


    default:
      printf(">>Incorrect Option\n");
    }

     

  } while (choice != 4);
}
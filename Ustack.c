#include <stdio.h>
#include <stdlib.h>
#define max 5
struct stack
{
    int arr[max];
    int top;
};
int isfull(struct stack *s)
{
    return (s->top==max-1);
}
int isempty(struct stack *s)
{
    return (s->top==-1);
}
void push(struct stack *s,int value)
{
    if(isfull(s))
    {
        printf("stack is full\n");
    }
    else
    {
        s->arr[++(s->top)]=value;
        printf("value %d is pushed \n",value);
    }
}
void pop (struct stack *s)
{
    if(isempty(s))
    {
        printf("stack is empty\n");
    }
    else
    {
        s->arr[(s->top)--];
        printf("popped value is %d\n",s->arr[(s->top)]);
    }
}
void peek (struct stack *s)
{
    if(isempty(s))
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("value peeked is %d\n",s->arr[s->top]);
    }
}
int size(struct stack *s)
{
    return s->top;
}
void clear (struct stack *s)
{
    s->top=-1;
    printf("stack is cleared\n");
}
void display(struct stack *s)
{   if(isempty(s))
   {
      printf("stack is empty cannot diaplay\n");
   }
   else
    {for(int i=0;i<s->top;i++)
    {
        printf("value at %d is %d \n",i+1,s->arr[i]);
    }}
}
int main()
{
    struct stack s;
    s.top=-1;
    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    pop(&s);
    peek(&s);
    display(&s);
    printf("%d",size(&s));
    display(&s);
    clear(&s);
    display(&s);
    return 0;
}









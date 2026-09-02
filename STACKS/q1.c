#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct{
    int top;
    int val[MAX];
}stack;

stack createstack()
{
    stack s;
    s.top=0;
    return s;
}

int isempty(stack s)
{
    if(s.top==0)return 1;
    else return 0;
}

int isfull(stack s)
{
    if(s.top==MAX)return 1;
    else return 0;
}

void push(stack *s,int x)
{
    if(isfull(*s)){return;}

    s->top+=1;
    s->val[s->top]=x;
}

void pop(stack *s,int *x)
{
    if(isempty(*s)){return;}

    *x=s->val[s->top];
    s->top-=1;
}

void display(stack s)
{
    int x;
    while(!isempty(s))
    {
       pop(&s,&x);
       printf("%5d",x);
    }
    printf("\n");
}

int main()
{
    int n;
    int x;
    stack s1;
    stack s2;

    s1=createstack();
    s2=createstack();
    
    printf("eneter n: ");
    scanf("%d",&n);

    while(n)
    {
        x=rand()%100;
        if(x%2==0)
          {
            push(&s2,x);
          }
        else
          {
            push(&s1,x);
          }
          n--;
    }

    printf("\nodd stack\n");
    display(s1);

    printf("\neven stack\n");
    display(s2);

    return 0;
}



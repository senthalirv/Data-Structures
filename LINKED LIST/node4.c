#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *top=NULL;

NODE *create(int x)
{
    NODE *n=(NODE *)malloc(sizeof(NODE));

    n->data=x;
    n->next=NULL;

    return n;
}

void push(int x)
{
    NODE *n=create(x);

    n->next=top;
    top=n;
}

int pop()
{
    if (top==NULL)
        return 0;

    NODE *t=top;
    int x=t->data;

    top=top->next;
    free(t);

    return x;
}

int eva(char e[])
{
    int i=0;

    while (e[i]!='\0')
    {
        if (e[i]>='0' && e[i]<='9')
        {
            push(e[i]-'0');
        }
        else
        {
            int b=pop();
            int a=pop();
            int r;

            switch (e[i])
            {
                case '+':
                    r=a+b;
                    break;

                case '-':
                    r=a-b;
                    break;

                case '*':
                    r=a*b;
                    break;

                case '/':
                    r=a/b;
                    break;

                case '%':
                    r=a%b;
                    break;

                default:
                    printf("Invalid operator\n");
                    exit(1);
            }

            push(r);
        }

        i++;
    }

    return pop();
}

int main()
{
    char pf[100];

    printf("Enter postfix expression: ");
    scanf("%s", pf);

    printf("Result : %d\n", eva(pf));

    return 0;
}

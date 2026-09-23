#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *create(int data)
{
    NODE *t = (NODE *)malloc(sizeof(NODE));
    t->data = data;
    t->next = NULL;
    return t;
}

NODE *insertcircle(NODE *current, int data)
{
    NODE *t=create(data);

    if(current==NULL)
    {
        t->next=t;
        return t;
    }

    t->next=current->next;
    current->next=t;

    return t;
}

void dispc(NODE *c)
{
    if (c==NULL)
    {
        printf("\nEmpty List\n");
        return;
    }

    NODE *temp=c->next;

    do
    {
        printf("%5d", temp->data);
        temp=temp->next;
    }while (temp!=c->next);

    printf("\n");
}

void search(NODE *l, int key)
{
    if (l==NULL)
    {
        printf("Empty List\n");
        return;
    }

    NODE *p=l;
    NODE *c=l->next;

    do
    {
        if (c->data==key)
        {
            printf("Element %d found\n", key);
            printf("Predecessor : %d\n", p->data);
            printf("Successor   : %d\n", c->next->data);
            return;
        }

        p=c;
        c=c->next;

    }while(c!=l->next);

    printf("Element %d not found\n", key);
}
int count(NODE *l)
{
    if(l==NULL)
    {
        return 0;
    }

    int c=0;
    NODE *t=l->next;

    do
    {
        c++;
        t=t->next;

    } while(t!=l->next);

    return c;
}
void reverse(NODE **l)
{
    if(*l==NULL)
    {
        printf("List is empty\n");
        return;
    }

    NODE *tail=*l;
    NODE *head=tail->next;

    NODE *prev=tail;
    NODE *cur=head;
    NODE *next;

    do
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;

    }while(cur!=head);

    *l=head;

    printf("List has been reversed\n");
}
int main()
{
    NODE *ll=NULL;
    int n, v;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int i=1;i<=n;i++)
    {
        printf("Enter value %d: ", i);
        scanf("%d", &v);

        ll=insertcircle(ll, v);
    }

    printf("\nCircular Linked List:\n");
    dispc(ll);

    int s;
    printf("Enter search element: ");
    scanf("%d",&s);
    search(ll,s);

    int c=count(ll);
    printf("%d\n",c);

    reverse(&ll);
    dispc(ll);

    return 0;
}

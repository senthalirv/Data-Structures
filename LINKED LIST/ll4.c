#include<stdio.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *create(int data)
{
    NODE *temp=(NODE*) malloc(sizeof(NODE));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void display(NODE *l)
{
    while(l)
    {
        printf("%5d",l->data);
        l=l->next;
    }
}

NODE *inserth(NODE *l,int data)
{
    NODE *temp = create(data);
    temp->next=l;
    return temp;
}

int count(NODE *l)
{
    int cc=0;
    while(l)
    {
        cc=cc+1;
        l=l->next;
    }
    return cc;
}

int countr(NODE *l)
{
    if(!l)
        return 0;
    return 1+countr(l->next);
}

int pos(NODE *l,int data)
{

    int pos=1;
    while(l)
    {

        if(l->data==data) return pos;
        l=l->next;pos=pos+1;
    }
}

int posr(NODE *l,int data, int cpos)
{
    if(!l) return -1;
    if(l->data==data) return cpos;
    return posr(l->next,data,cpos+1);
}

int sum(NODE *l)
{
    if(!l) return 0;
    return (l->data+sum(l->next));
}

void printr(NODE *l)
{
    if(l)
    {
        printr(l->next);
        printf("%5d",l->data);
    }

}

NODE* insertt(NODE *l,int data)
{

    if(!l) return create(data);
    NODE*t=l;
    while(t->next){t=t->next;}
    t->next=create(data);
    return l;
}

void creates(NODE **l)
{
    *l=NULL;
}

NODE* copyr(NODE* l)
{
    if(!l) return l;

    NODE* t=create(l->data);
    t->next = copyr(l->next);
    return t;
}

NODE* connect(NODE* l1,NODE* l2)
{
    if(!l1) return copyr(l2);
    NODE *t3=copyr(l1);
    NODE *c=t3;

    while(c->next!=NULL)
    {
        c=c->next;
    }

    c->next=copyr(l2);
    return t3;
}
int main()
{
    NODE *l2=NULL;
    NODE *l1=NULL;
    //NODE *l2;

    //l2=create(700);
    //l2=insertt(l2,800);
    //l2=insertt(l2,900);
    //l2->next=create(500);
    printf("Enter size of node 1: ");
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter element %d: ",i+1);
        int a;scanf("%d",&a);

        l1=insertt(l1,a);
    }


    printf("Enter size of node 2: ");
    int z;scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        printf("\nEnter element %d: ",i+1);
        int a;scanf("%d",&a);

        l2=insertt(l2,a);
    }

    printf("\nList 1: ");display(l1);
    printf("\nList 2: ");display(l2);

    NODE *l3=connect(l1,l2);
    printf("\nList 3: ");display(l3);


}

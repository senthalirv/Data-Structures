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
void same(NODE *l1,int s1, NODE *l2,int s2)
{
    /*if(s1!=s2)
    {
        printf("\nNot same");return;
    }*/

    int a=1;
    NODE *t1=l1; NODE *t2=l2;

    while(t1->next!=NULL&&t2->next!=NULL)
    {
        if(t1->data == t2->data)
        {
            t1=t1->next;
            t2=t2->next;
        }
        else
        {
            a=0;
            break;
        }
    }

    if(a&&t1==NULL&&t2==NULL)
        printf("\nSame");
    else
        printf("\nNot same");
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

    same(l1,n,l2,z);
    //creates(l2);

    //int c=countr(l2);
    //printf("%d",c);

    //printr(l2);
    //int s=findSum(l2);
    //printf("%5d",s);
    //printf("Hi");
    //display(l2);
    //l2=insertTail(l2,700);

    //int pos=findPosRec(l2,500,1);
    //printf("%d",pos);
    //printf("%d",pos);
    //display(l1);
    //display(l2);
    //display(l2);
}

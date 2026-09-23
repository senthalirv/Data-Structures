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
int main()
{
    //NODE *l1=NULL;
    NODE *l2=create(100);
    //NODE *l2;

    l2->next=create(500);
    display(l2);

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

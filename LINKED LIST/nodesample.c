#include<stdio.h>
#include<malloc.h>
typedef struct node{int data;struct node *next;}NODE;
typedef enum{False,True}Bool;
NODE *create(int data)
{
    NODE *t=(NODE*)malloc(sizeof(NODE));
    t->data=data;t->next=NULL;return t;
}
void disp(NODE *l)
{
    if(l)
    {
        printf("%5d",l->data);
        disp(l->next);
    }
}
NODE *dpos(NODE *l,int pos)
{

    if(!l) return l;
    if(pos==1) return l->next;
    int cP=1; NODE *t=l;
    while(cP<pos-1 && t->next)
    {
        t=t->next;cP++;
    }
    if(t->next){
        t->next=(t->next)->next;
    }
    return l;
}
NODE* insertt(NODE *l,int data)
{

    if(!l) return create(data);
    NODE*t=l;
    while(t->next){t=t->next;}
    t->next=create(data);
    return l;
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

void creates(NODE **l)
{
    *l=NULL;
}

Bool order(NODE *l)
{
    if (!l) {
        printf("\nEmpty");
        return False;
    }

    int a=1;
    NODE *t=l;

    while(t->next!=NULL)
    {
        if(t->data < t->next->data)
        {
            t=t->next;
        }
        else
        {
            a=0;
            break;
        }
    }

    if(a)
        return True;
    else
        return False;
}
NODE *insertcircle(NODE *l,int data)
{
    if(!l)
    {
        NODE *t=create(data,NULL);
        t->next=t;
        return t;}
        NODE *t=create(data,t->next);
        l->next=t;
        return l;
}
//NODE dispc
int main()
{
    /*NODE *l1=create(100);
    l1=insertt(l1,200);
    disp(l1);
    dpos(l1,2);
    disp(l1);*/
}

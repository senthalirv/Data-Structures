#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE *create(int data)
{
    NODE *t=(NODE*)malloc(sizeof(NODE));
    t->data=data;
    t->next=NULL;
    return t;
}
void display(NODE *l)
{
    while(l)
    {
        printf("%d",l->data);
        l=l->next;
    }
}
int countr(NODE *l)
{
    if(!l)
        return 0;
    return 1+countr(l->next);
}
int intconv(NODE *l)
{
    int c=countr(l);
    NODE *t=l;
    int sum=0;
    for(int i=(c-1);i>=0;i--)
    {
        sum+=(t->data)*(pow(100,i));
        t=t->next;
    }
    return sum;
}
int findsum(NODE *l)
{

    if(!l) return 0; static int c=1;
    if(!l->next)return l->data;
    return findsum(l->next)+l->data*(c*=100);
}
NODE* insertt(NODE *l,int data)
{

    if(!l) return create(data);
    NODE*t=l;
    while(t->next){t=t->next;}
    t->next=create(data);
    return l;
}
int main()
{
    NODE *l1=NULL;
    printf("Enter size of node 1: ");
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter element %d: ",i+1);
        int a;scanf("%d",&a);

        l1=insertt(l1,a);
    }


    printf("The number represented: \n");
    int i=intconv(l1);
    //int i=findsum(l1);
    printf("%d",i);
}

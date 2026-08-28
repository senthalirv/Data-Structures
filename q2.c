#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node {int data; struct node *left,*right;}BT;

BT* makenode(int data)
{
    BT *t=(BT*)malloc(sizeof(BT));
    t->data=data;t->left=NULL;t->right=NULL;
    return t;
}

BT* insert(BT *t,int data)
{
    if(t==NULL)return makenode(data);

    if(data<t->data)
        t->left=insert(t->left,data);
    else
        t->right=insert(t->right,data);

    return t;
}

void kth(BT *t,int k,int *c,int *res)
{
    if(!t)return;

    kth(t->left,k,c,res);

    (*c)++;
    if(*c==k)
    {
        *res=t->data;
        return;
    }

    kth(t->right,k,c,res);
}

void inOr(BT *t)
{
    if(t)
    {
        inOr(t->left);
        printf("%5d",t->data);
        inOr(t->right);

    }
}

int main()
{
    BT *t=NULL;

    for(int i=0;i<6;i++)
    {
        t=insert(t,rand()%10);
    }

    int k,c=0,res=0;

    printf("BST:");
    inOr(t);

    printf("\nEnter k: ");
    scanf("%d",&k);
    kth(t,k,&c,&res);

    printf("\n%dth smallest element: %d",k,res);

    return 0;
}

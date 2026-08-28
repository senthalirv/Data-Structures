#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node {int data; struct node *left, *right;}BT;
BT* makenode(int data)
{
    BT *t=(BT *)malloc(sizeof(BT));
    t->data=data;t->left=NULL;t->right=NULL;
    return t;
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
BT *insert(BT *t, int data)
{
    if(t==NULL)return makenode(data);

    int h=height(t);
    if (h==1)
    {
        if(t->left==NULL)
            t->left=makenode(data);
        else
            t->right=makenode(data);
        return t;
    }

    if((height(t->left))<(h-1))
        t->left=insert(t->left,data);
    else
        t->right=insert(t->right,data);
    return t;
}
int height(BT *t)
{

    if(!t)return 0;
    int l=height(t->left);
    int r=height(t->right);
    return l>r?l+1:r+1;
}
int count(BT *t)
{
    if(!t)return 0;
    return 1+count(t->left)+count(t->right);
}
int isComp(BT* t, int i, int tn) {
    if (t==NULL)
        return 1;

    if (i>=tn)
        return 0;

    return (isComp(t->left, 2*i+1, tn)&&isComp(t->right, 2*i+2, tn));
}
int ismh(BT* t) {
    if (t==NULL)
        return 1;

    if (t->left!= NULL && t->data>(t->left->data))
        return 0;

    if (t->right!=NULL&& t->data>t->right->data)
        return 0;

    return ismh(t->left)&&ismh(t->right);
}
int main()
{
    BT *t=NULL;
    for(int i=0;i<4;i++)
    {
        t=insert(t,rand()%10);
    }

    inOr(t);
    printf("\n%d",isComp(t,0,count(t)));
    printf("\n%d",ismh(t));
}

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
    int data; struct node *left, *right;
}BT;

BT* create(int data)
{
    BT *t=(BT *)malloc(sizeof(BT));
    t->data=data;
    t->left=NULL;t->right=NULL;
    return t;
}

void inOr(BT *t)
{
    if(t)
    {
        inOr(t->left); printf("%5d",t->data);
        inOr(t->right);
    }
}

void preOr(BT *t)
{
    if(t)
    {
        printf("%5d",t->data);
        preOr(t->left);
        preOr(t->right);
    }
}

void postOr(BT *t)
{
    if(t)
    {
        postOr(t->left);
        postOr(t->right); printf("%5d",t->data);
    }
}

BT *insert(BT *t, int data)
{
    if(!t) return create(data);
    if(t->data>data)
    {
        t->left=insert(t->left,data);
    }
    if(t->data<data)
    {
        t->right=insert(t->right,data);
    }
    return t;
}
int height(BT *t)
{
    if(!t) return 0;
    int l=height(t->left);
    int r=height(t->right);

    return l>r?l+1:r+1;
}

int count(BT *t)
{
    if(!t) return 0;
    return 1+count(t->left)+count(t->right);
}

int search(BT *t,int data)
{

    if(!t) return 0;
    if(t->data==data) return 1;
    if(t->data>data) return search(t->left,data);
    if(t->data<data)return search(t->right,data);
}

int min(BT *t)
{
    if(t->right==NULL) return t->data;
    return min(t->right);
}
int max(BT *t)
{
    if(t->left==NULL) return t->data;
    return max(t->left);
}

BT *del(BT *t,int data)
{
    if(!t)return NULL;
    if(t->data==data)
    {
        if(!t->right && !t->left) return NULL;//t->left;
        if(!t->left) return t->right;
        if(!t->right) return t->left;

        t->data=min(t->right);
        t->right=del(t->right,t->data);
        return t;
    }
    if(t->data>data) t->left=del(t->left,data);
    else
        t->right=del(t->right,data);
    return t;

}

int main()
{
    BT *t=NULL;/* t=create(50);
    t->left=create(20); t->right=create(70);*/

   for(int i=0;i<5;i++)
   {
        t=insert(t,rand()%10);
   }
   printf("\nBinary Tree: ");
    inOr(t);
    printf("\n\n");

    t=del(t,7);
    printf("\nBinary Tree(After Deletion): \n");
    inOr(t);
    printf("\n\nPreOrder: \n");
    preOr(t);
    printf("\n\nPostOrder: \n");
    postOr(t);
}

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node {int data;struct node *left,*right;int ht;}AVL;

int height(AVL *t)
{
    if(!t)return 0;
    return t->ht;
}

int max(int a,int b)
{
    return a>b?a:b;
}

AVL* makenode(int data)
{
    AVL *t=(AVL *)malloc(sizeof(AVL));
    t->data=data;t->left=NULL;t->right=NULL;t->ht=1;
    return t;
}

int bal(AVL *t)
{
    if(!t)return 0;
    return height(t->left)-height(t->right);
}

AVL* rrot(AVL *t)
{
    AVL *p=t->left;
    AVL *q=p->right;

    p->right=t;
    t->left=q;

    t->ht=1+max(height(t->left),height(t->right));
    p->ht=1+max(height(p->left),height(p->right));

    return p;
}

AVL* lrot(AVL *t)
{
    AVL *p=t->right;
    AVL *q=p->left;

    p->left=t;
    t->right=q;

    t->ht=1+max(height(t->left),height(t->right));
    p->ht=1+max(height(p->left),height(p->right));

    return p;
}

AVL* insert(AVL *t,int data)
{
    if(t==NULL)return makenode(data);

    if(data<t->data)
        t->left=insert(t->left,data);
    else if(data>t->data)
        t->right=insert(t->right,data);
    else
        return t;

    t->ht=1+max(height(t->left),height(t->right));

    int b=bal(t);

    if(b>1&&data<t->left->data)
        return rrot(t);

    if(b<-1&&data>t->right->data)
        return lrot(t);

    if(b>1&&data>t->left->data)
    {
        t->left=lrot(t->left);
        return rrot(t);
    }

    if(b<-1&&data<t->right->data)
    {
        t->right=rrot(t->right);
        return lrot(t);
    }

    return t;
}

AVL* minnode(AVL *t)
{
    while(t&&t->left)
        t=t->left;
    return t;
}

AVL* delete(AVL *t,int data)
{
    if(!t)return t;

    if(data<t->data)
        t->left=delete(t->left,data);
    else if(data>t->data)
        t->right=delete(t->right,data);
    else
    {
        if(t->left==NULL||t->right==NULL)
        {
            AVL *p=t->left?t->left:t->right;
            free(t);
            return p;
        }

        AVL *p=minnode(t->right);
        t->data=p->data;
        t->right=delete(t->right,p->data);
    }

    t->ht=1+max(height(t->left),height(t->right));

    int b=bal(t);

    if(b>1&&bal(t->left)>=0)
        return rrot(t);

    if(b>1&&bal(t->left)<0)
    {
        t->left=lrot(t->left);
        return rrot(t);
    }

    if(b<-1&&bal(t->right)<=0)
        return lrot(t);

    if(b<-1&&bal(t->right)>0)
    {
        t->right=rrot(t->right);
        return lrot(t);
    }

    return t;
}

void inOr(AVL *t)
{
    if(t)
    {
        inOr(t->left);
        printf("%5d",t->data);
        inOr(t->right);/*primtf("%d",t->data); */
    }
}
void pl(AVL *t,int lev)
{
    if(t==NULL)
        return;

    if(lev==0)
    {
        printf("%d ",t->data);
        return;}

    pl(t->left,lev-1);
    pl(t->right,lev-1);
}

void levOr(AVL *t)
{
    int i;

    for(i=0;i<height(t);i++)
    {
        printf("\nLevel %d: ", i);
        pl(t,i);
    }

    printf("\n");
}

int main()
{
    AVL *t=NULL;

    t=insert(t,10);levOr(t);
    t=insert(t,20);levOr(t);
    t=insert(t,30);levOr(t);
    t=insert(t,40);levOr(t);



    printf("AVL");
    delete(t,20);

    inOr(t);
    return 0;
}

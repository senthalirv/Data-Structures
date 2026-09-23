
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data; struct node *left, *right, *head;
}JA;

JA* create(int data)
{
    JA *t=malloc(sizeof(JA));
    t->data=data;
    t->left=NULL;t->right=NULL;t->head=NULL;
    return t;
}

void inOr(JA *t)
{
    if(t==NULL) return;
    printf("%5d",t->data);
    inOr(t->right);

}

JA *insert(JA *t, int data)
{
    if(t==NULL) return create(data);
    t->right=insert(t->right,data);
    return t;
}

int main()
{
    JA *t=NULL;

   for(int i=0;i<5;i++)
   {
        t=insert(t,rand()%10);
   }

   printf("%d ",t->right);
   inOr(t);


}

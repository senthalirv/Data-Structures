#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct node
{
    char data[100];
    struct node *left, *right;
}BT;

BT* create(char data[])
{
    BT *t=(BT *)malloc(sizeof(BT));

    strcpy(t->data, data);

    t->left=NULL;t->right=NULL;

    return t;
}

void inOr(BT *t)
{
    if(t)
    {
        inOr(t->left);
        printf("%s\t", t->data);
        inOr(t->right);
    }
}

void preOr(BT *t)
{
    if(t)
    {
        printf("%s\t", t->data);
        preOr(t->left);
        preOr(t->right);
    }
}

void postOr(BT *t)
{
    if(t)
    {

        postOr(t->left);
        postOr(t->right);
        printf("%s\t", t->data);
    }
}

BT *insert(BT *t, char data[])
{
    if(!t)
        return create(data);

    if(strcmp(data, t->data)<0)
    {
        t->left=insert(t->left, data);
    }
    else if(strcmp(data, t->data)>0)
    {
        t->right=insert(t->right, data);
    }

    return t;
}

char min(BT *t)
{
    if(t->left==NULL) return t->data;
    return min(t->left);
}
char max(BT *t)
{
    if(t->right==NULL) return t->data;
    return max(t->right);
}

BT *del(BT *t,int data)
{
    if(!t)return NULL;
    if(strcmp(t->data,data)==0)
    {
        if(!t->right && !t->left) {free(t);return NULL;}//t->left;
        if(!t->left)
        {
            BT *temp=t->right;
            free(t);
            return temp;
        }
        if(!t->right)
        {
            BT *temp=t->left;
            free(t);
            return temp;
        }

        BT *temp=t->right;

        while(temp->left)
        {
                temp=temp->left;
        }

        strcpy(t->data,temp->data);

        t->right=del(t->right,temp->data);

        return t;
    }
    if(strcmp(data, t->data)<0)
        t->left=del(t->left,data);
    else
        t->right=del(t->right,data);
    return t;
}
void cpar(BT *t, int *z, int *o, int *tw)
{
    if(!t)
        return;

    if(!t->left&&!t->right)
        (*z)++;

    else if(!t->left||!t->right)
        (*o)++;

    else
        (*tw)++;

    cpar(t->left, z, o, tw);
    cpar(t->right, z, o, tw);
}
int main()
{
    BT *t=NULL;

    printf("Enter n: ");
    int n;
    scanf("%d",&n);

    char s[100];

    for(int i=0;i<n;i++)
    {
        printf("Enter String(%d): ", (i+1));
        scanf("%s",s);

        t=insert(t,s);
    }

    printf("\nInorder: ");
    inOr(t);

    int z=0,o=0,tw=0;
    cpar(t,&z,&o,&tw);
    printf("Zero: %5d\nOne: %5d\nTwo: %5d",z,o,tw);

    return 0;
}

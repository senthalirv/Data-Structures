#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char data;
    char sta;
    struct node *left,*right;
}BT;

BT *create(char data)
{
    BT *t=(BT *)malloc(sizeof(BT));

    t->data=data;
    t->sta='D';
    t->left=NULL;t->right=NULL;

    return t;
}

BT *insert(BT *t,char data)
{
    if(!t)
        return create(data);

    if(data<t->data)
        t->left=insert(t->left,data);
    else if(data>t->data)
        t->right=insert(t->right,data);

    return t;
}

BT *search(BT *t,char data)
{
    if(!t) return NULL;

    if(t->data==data) return t;
    if(data<t->data) return search(t->left,data);
    else return search(t->right,data);
}

int val(BT *t,char s[])
{
    int i=0;
    char op,data;
    BT *p;

    while(s[i]!='\0')
    {
        op=s[i];
        data=s[i+1];

        p=search(t,data);

        if(op=='D')
        {
            if(p)
            {
                if(p->sta=='D')return 0;


                p->sta='D';
            }
            else
                t=insert(t,data);
        }

        else if(op=='U')
        {
            if(!p||p->sta!='D')return 0;

        }

        else if(op=='K')
        {
            if(!p||p->sta!='D')return 0;

            p->sta='K';
        }

        else
        {
            return 0;
        }

        i=i+2;
    }

    return 1;
}

int main()
{
    BT *t=NULL;
    char s[100];

    printf("Enter string: ");
    scanf("%s",s);

    if(val(t,s))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}

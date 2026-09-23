#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


typedef struct
{
    int cc,cred;
    char grade;
}course;

typedef struct{

    course c[10];
}sem;

typedef struct node{
    int reg;
    sem s[8];
    struct node *next;

}NODE;

NODE *ADMIT(int data)
{
    NODE *temp=(NODE*) malloc(sizeof(NODE);

    temp->reg=data;
    temp->next=NULL;
    return temp;
}

void ENROLL(NODE *cl)
{
    int ch;
    printf("Enter semester: ");
    scanf("%d",&ch);


        for(int j=0;j<10;j++)
        {
            printf("Enter code and credits for course[%d]: ",i+1);
            scanf("%d %d",cl->s[ch].c[j].cc, cl->s[ch].c[j].cred);
            cl->s[ch].c[j].grade='N';

        }

}

NODE* DEL(int reg,int code, NODE *l)
{
    while(l!=NULL)
    {
        if(l->reg==reg)
        {
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(l->s[i].c[j].cc==code)
                    {
                        l->s[i].c[j]=NULL;break;
                    }
                }
            }
        }

        l=l->next;
    }

    return l;
}

void *UPDATE(NODE *l, int code, int reg)
{
    while(l!=NULL)
    {
        if(l->reg==reg)
        {
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(l->s[i].c[j].cc==code)
                    {
                        char g;
                        printf("Enter grade: ");
                        scanf("%c",g);
                        l->s[i].c[j].grade=g;;
                        break;
                    }
                }
            }
        }
    }
}

int TOTALCRED(NODE *l,int reg)
{
    int sum=0;
    while(l!=NULL)
    {
        if(l->reg==reg)
        {
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(l->s[i].c[j].grade!='F')
                        sum+=l->s[i].c[j].cred;
                }
            }
        }
    }

    return sum;
}

int main()
{

}





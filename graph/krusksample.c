#include<stdio.h>
#include<stdlib.h>

int cmp(const int a[],const int b[])
{
    return a[2]-b[2];
}

void make(int p[],int r[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}

int find(int p[],int x)
{
    if(p[x]==x)
        return x;
    p[x]=find(p,p[x]);
    return p[x];
}

void join(int a,int b,int p[],int r[])
{
    a=find(p,a);
    b=find(p,b);

    if(r[a]<r[b])
        p[a]=b;
    else if(r[a]>r[b])
        p[b]=a;
    else
    {
        p[b]=a;
        r[a]++;
    }
}

int kruskal(int n,int e[][3])
{
    int p[n],r[n],cost=0,i;
    qsort(e,n,sizeof(e[0]),cmp);
    make(p,r,n);

    for(i=0;i<n;i++)
    {
        int a=find(p,e[i][0]);
        int b=find(p,e[i][1]);

        if(a!=b)
        {
            join(a,b,p,r);
            cost+=e[i][2];
        }
    }
    return cost;
}

void insert(int e[][3],int *n,int u,int v,int w)
{
    e[*n][0]=u;
    e[*n][1]=v;
    e[*n][2]=w;
    (*n)++;
}

void del(int e[][3],int *n,int u,int v)
{
    int i,j;

    for(i=0;i<*n;i++)
    {
        if((e[i][0]==u && e[i][1]==v) ||
           (e[i][0]==v && e[i][1]==u))
        {
            for(j=i;j<*n-1;j++)
            {
                e[j][0]=e[j+1][0];
                e[j][1]=e[j+1][1];
                e[j][2]=e[j+1][2];
            }
            (*n)--;
            return;
        }
    }
}

int main()
{
    int e[10][3]={
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    int n=5;

    insert(e,&n,1,2,7);
    del(e,&n,0,3);

    printf("Minimum cost = %d",kruskal(n,e));

    return 0;
}

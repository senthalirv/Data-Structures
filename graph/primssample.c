#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define V 100
int n;

int min(int w[],bool vis[],int n)
{
    int m=INT_MAX,ind=-1,i;

    for(i=0;i<n;i++)
    {
        if(!vis[i] && w[i]<m)
        {
            m=w[i];
            ind=i;
        }
    }
    return ind;
}

void print(int p[],int g[V][V],int n)
{
    int i,c=0;

    printf("MST:\n");
    printf("Edge\tWeight\n");

    for(i=1;i<n;i++)
    {
        printf("%d-%d\t%d\n",p[i],i,g[i][p[i]]);
        c+=g[i][p[i]];
    }

    printf("Total cost: %d\n",c);
}

void prim(int g[V][V],int p[],int src,int n)
{
    int w[V],i,j,u;
    bool vis[V];

    for(i=0;i<V;i++)
    {
        w[i]=INT_MAX;
        vis[i]=false;
        p[i]=-1;
    }

    w[src]=0;
    p[src]=-1;

    for(i=0;i<n-1;i++)
    {
        u=min(w,vis,n);
        if(u==-1) break;
        vis[u]=true;

        for(j=0;j<n;j++)
        {
            if(g[u][j] && !vis[j] && g[u][j]<w[j])
            {
                p[j]=u;
                w[j]=g[u][j];
            }
        }
    }
}

void insert(int g[V][V],int u,int v,int w)
{
    g[u][v]=w;
    g[v][u]=w;
}

void del(int g[V][V],int u,int v)
{
    g[u][v]=0;
    g[v][u]=0;
}

void reach(int g[V][V],int sv,int k,int n)
{
    int queue[V],dist[V];
    bool vis[V];
    int f=0,r=0,i,j,u;

    for(i=0;i<n;i++)
    {
        dist[i]=-1;
        vis[i]=false;
    }

    queue[r++]=sv;
    vis[sv]=true;
    dist[sv]=0;

    while(f<r)
    {
        u=queue[f++];
        if(dist[u]<k)
        {
            for(j=0;j<n;j++)
            {
                if(g[u][j] && !vis[j])
                {
                    vis[j]=true;
                    dist[j]=dist[u]+1;
                    queue[r++]=j;
                }
            }
        }
    }

    printf("Vertices within distance %d from %d (BFS):\n",k,sv);
    for(i=0;i<n;i++)
    {
        if(i!=sv && dist[i]!=-1 && dist[i]<=k) printf("%d ",i);
    }
    printf("\n");
}
void DFS(int g[V][V],int u,bool vis[],int n)
{
    vis[u]=true;
    printf("%d ",u);
    for(int v=0;v<n;v++)
    {
        if(g[u][v] && !vis[v])
        {
            DFS(g,v,vis,n);
        }
    }
}

void BFS(int g[V][V],int src,int dist[])
{
    int queue[V];
    int f=0;int r=0;
    int vis[V]={0};

    queue[r++]=src;
    vis[src]=1;
    dist[src]=0;

    while(f<r)
    {
        int u=queue[f++];
        for(int v=0;v<n;v++)
        {
            if(g[V][V]==1&&!vis[v])
            {
                vis[v]=1;
                dist[v]=dist[u]+1;
                queue[r++]=v;
            }
        }
    }
}


int main()
{
    int g[V][V]={
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    int g2[V][V]={
        {0,4,0,0,0,0,0,8,0},
        {4,0,8,0,0,0,0,11,0},
        {0,8,0,7,0,4,0,0,2},
        {0,0,7,0,9,14,0,0,0},
        {0,0,0,9,0,10,0,0,0},
        {0,0,4,14,10,0,2,0,0},
        {0,0,0,0,0,2,0,1,6},
        {8,11,0,0,0,0,1,0,7},
        {0,0,2,0,0,0,6,7,0}
    };

    insert(g,0,2,4);
    del(g,1,3);

    int p1[V],p2[V];

    prim(g,p1,0,5);
    print(p1,g,5);

    prim(g2,p2,0,9);
    print(p2,g2,9);

    reach(g2,0,1,9);

    return 0;
}

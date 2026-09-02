#include<stdio.h>

typedef struct
{
    int coeff;
    int exp;
}term;

typedef struct
{
    term t[100];
    int nt;
}poly;

poly createpoly()
{
    poly p;
    p.nt=0;
    return p;
}

void printpoly(poly p)
{
    for(int i=0;i<p.nt;i++)
    {
        printf("%d x^%d ",p.t[i].coeff,p.t[i].exp);

        if(i!=p.nt-1){printf("+");}
    }
    printf("\n");
}

poly addpolynomial(poly p1,poly p2)
{
    poly p3=createpoly();
    int k=0;
    int i=0,j=0;

    while(i<p1.nt&&j<p2.nt)
    {
        if(p1.t[i].exp==p2.t[j].exp)
        {
           int sum=p1.t[i].coeff+p2.t[j].coeff;
           if(sum)
           {
            p3.t[k].coeff=sum;
            p3.t[k].exp=p1.t[i].exp;
            k++;
           }
           i++;
           j++;
        }

        else if(p1.t[i].exp>p2.t[j].exp)
        {
            p3.t[k].exp=p1.t[i].exp;
            p3.t[k].coeff=p1.t[i].coeff;
            k++;
            i++;
        }

        else if(p2.t[j].exp>p1.t[i].exp)
        {
            p3.t[k].exp=p2.t[j].exp;
            p3.t[k].coeff=p2.t[j].coeff;
            j++;
            k++;
        }
    }

    while(i<p1.nt)
    {
        p3.t[k].coeff=p1.t[i].coeff;
        p3.t[k].exp=p1.t[i].exp;
        i++;
        k++;
    }

    while(j<p2.nt)
    {  
        p3.t[k].coeff=p2.t[j].coeff;
        p3.t[k].exp=p2.t[j].exp;
        j++;
        k++;
    }

    p3.nt=k;

    return p3;

    
}

poly attachterm(poly p,term r)
{
    for(int i=0;i<p.nt;i++)
    {
        if(p.t[i].exp==r.exp)
        {
           p.t[i].coeff+=r.coeff;
           return p;
        }
    }

    int i=p.nt-1;

    while(i>=0&&p.t[i].exp<r.exp)
    {
        p.t[i+1]=p.t[i];
        i--;
    }

    p.t[i+1]=r;
    p.nt++;

    return p;
}

poly multiplypoly(poly p1,poly p2)
{
    poly p3=createpoly();

    for(int i=0;i<p1.nt;i++)
    {
        for(int j=0;j<p2.nt;j++)
        {
            int t=p1.t[i].coeff*p2.t[j].coeff;
            if(t)
            {
            term r;
            r.coeff=t;
            r.exp=p1.t[i].exp+p2.t[j].exp;
            
            p3=attachterm(p3,r);
            }
        }
    }
    
    return p3;
}

int main()
{
    poly p;
    

    term t1={2,12};
    term t2={7,2};
    term t3={3,7};
    term t4={2,6};

    p=createpoly();

    return 0;

}
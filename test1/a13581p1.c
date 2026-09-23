#include<stdio.h>
#include<stdlib.h>

void div(int a[],int n)
{
    int A11[n/2][n/2],A12[n/2][n/2],A21[n/2][n/2],A22[n/2][n/2];
    printf("\n\nMatrix 1: ");
    for(int i=0;i<n/2;i++)
    {
        for(int j=n/2;j<n;j++)
        {
            A11[i][j]=a[i][j];
        }
        //printf("\n");
    }

    printf("\n\nMatrix 2: ");
    for(int i=n/2;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            A12[i][j]=a[i][j];
        }
        //printf("\n");
    }

    printf("\n\nMatrix 3: ");
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            A21[i][j]=a[i][j];
        }
        //printf("\n");
    }

    printf("\n\nMatrix 4: ");
    for(int i=n/2;i<n;i++)
    {
        for(int j=n/2;j<n;j++)
        {
            A22[i][j]=a[i][j];
        }
        //printf("\n");
    }

    printf("\n\nMatrix 1: ");
    for(int i=0;i<n/2;i++)
    {
        for(int j=n/2;j<n;j++)
        {
            printf("%5d",A11[i][j]);
        }
        //printf("\n");
    }

    printf("\n\nMatrix 2: ");
    for(int i=n/2;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            printf("%5d",A12[i][j]);
        }
        //printf("\n");
    }

    printf("\n\nMatrix 3: ");
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            printf("%5d",A21[i][j]);
        }
        //printf("\n");
    }

    printf("\n\nMatrix 4: ");
    for(int i=n/2;i<n;i++)
    {
        for(int j=n/2;j<n;j++)
        {
            printf("%5d",A22[i][j]);
        }
        //printf("\n");
    }

    return;
}

int main()
{
    int n;
    printf("Enter size of the matrix: ");
    scanf("%d",&n);
    int a[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=rand()%100;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",a[i][j]);
        }
    }

    div(a,n);


}

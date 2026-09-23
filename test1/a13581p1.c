#include<stdio.h>
#include<stdlib.h>

void div(int n,int a[n][n])
{
    int A11[n/2][n/2],A12[n/2][n/2],A21[n/2][n/2],A22[n/2][n/2];

    printf("\n\nMatrix 1: ");
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            A11[i][j]=a[i][j];
        }
    }

    printf("\n\nMatrix 2: ");
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            A12[i][j]=a[i][j+n/2];
        }
    }

    printf("\n\nMatrix 3: ");
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            A21[i][j]=a[i+n/2][j];
        }
    }

    printf("\n\nMatrix 4: ");
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            A22[i][j]=a[i+n/2][j+n/2];
        }
    }

    printf("\n\nMatrix 1: ");
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            printf("%5d",A11[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMatrix 2: ");
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            printf("%5d",A12[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMatrix 3: ");
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            printf("%5d",A21[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMatrix 4: ");
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            printf("%5d",A22[i][j]);
        }
        printf("\n");
    }
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

    printf("\nOriginal Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }

    div(n,a);
}

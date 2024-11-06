#include<stdio.h>
#include<ctype.h>

int main()
{
    int n=3;
    int a[n][n];
    int b[n][n];
    int c[n][n];

    printf("Enter Mat 1\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter Mat 2\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }

    #pragma omp parallel for
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=0;
            for(int k=0;k<n;k++)
            {
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    printf("Res\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}
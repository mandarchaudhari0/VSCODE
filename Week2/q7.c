#include<stdio.h>
#include<ctype.h>
#include<omp.h>

int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }

    return fib(n-1)+fib(n-2);
}

int main()
{
    int n=4;
    int arr[]={10,13,5,6};

    #pragma omp parallel for num_threads(n)
    for(int i=0;i<n;i++)
    {
        int fibnum=fib(arr[i]);
        printf("Fib of %d is %d\n",arr[i],fibnum);
    }

}
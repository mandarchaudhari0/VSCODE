#include<stdio.h>
#include<math.h>
#include<omp.h>

int main()
{
    int n=8;
    int arr[8] = {1,2,3,4,5,6,7,8};

    int odd_sum=0, even_sum=0;

    #pragma omp parallel num_threads(2)
    {
        if(omp_get_thread_num()==0)
        {
            for(int i=0;i<n;i++)
            {
                if(arr[i]%2==0)
                {
                    even_sum+=arr[i];
                }
            }
            printf("Even Sum: %d\n",even_sum);
        }
        if(omp_get_thread_num()==1)
        {
            for(int i=0;i<n;i++)
            {
                if(arr[i]%2!=0)
                {
                    odd_sum+=arr[i];
                }
            }
            printf("Odd Sum: %d\n",odd_sum);
        }
    }
}
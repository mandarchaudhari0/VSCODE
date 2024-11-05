#include<stdio.h>
#include<omp.h>
#include<math.h>

int main()
{
    #pragma omp parallel num_threads(10)
    {
        int n = 10;

        #pragma omp for
        for(int i=0;i<n;i++)
        {
            int power = pow(i,omp_get_thread_num());
            printf("Thread:%d %d\n",omp_get_thread_num(),power);
        }
    }
    return 0;
}
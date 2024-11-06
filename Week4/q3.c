#include<stdio.h>
#include<mpi.h>
#include<math.h>

int main(int argc, char * argv[])
{
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    int a,b;

    if(rank==0)
    {
        printf("Enter two number\n");
        scanf("%d",&a);
        scanf("%d",&b);
    }

    MPI_Bcast(&a,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Bcast(&b,1,MPI_INT,0,MPI_COMM_WORLD);

    switch(rank)
    {
        case(0):
            printf("Sum = %d\n",a+b);
            break;
        case(1):
            printf("Sub = %d\n",a-b);
            break;
        case(2):
            printf("Mul = %d\n",a*b);
            break;
        case(3):
            printf("Div = %d\n",a/b);
            break;
        default:
            printf("Num Proc 4");
    }

    MPI_Finalize();
    return 0;
        
}
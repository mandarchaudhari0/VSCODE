#include<stdio.h>
#include<mpi.h>
#include<math.h>

int main(int argc, char* argv[])
{
    int rank,size;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if(rank%2==0)
    {
        printf("Proc :%d Hello\n",rank);
    }
    else
    {
        printf("Proc :%d World\n",rank);
    }

    MPI_Finalize();
    return 0;

}
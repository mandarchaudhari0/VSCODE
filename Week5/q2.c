#include<stdio.h>
#include<mpi.h>
#include<ctype.h>

int main(int argc, char* argv[])
{
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    int num=0;

    if(rank==0)
    {
        printf("Enter Number :\n");
        scanf("%d",&num);

        for(int i=1;i<3;i++)
        {
            MPI_Send(&num,1,MPI_INT,i,1,MPI_COMM_WORLD);
        }
    }

    if(rank>0)
    {
        MPI_Recv(&num,1,MPI_INT,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

        printf("Process: %d recieved number %d\n",rank,num);
    }

    MPI_Finalize();
    return 0;
}
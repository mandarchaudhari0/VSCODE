#include<stdio.h>
#include<mpi.h>
#include<math.h>

int main(int argc,char *argv[])
{
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    int arr[size];
    int buffer[200];

    int buffersize = sizeof(buffer);

    MPI_Buffer_attach(buffer,buffersize);

    if (rank==0)
    {
        printf("Enter Array Elements\n");
        for(int i=1;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }

        for(int i=1;i<size;i++)
        {
            MPI_Bsend(&arr[i],1,MPI_INT,i,1,MPI_COMM_WORLD);
        }
    }
    else if(rank%2==0)
    {
        int a=0;
        
        MPI_Recv(&a,1,MPI_INT,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

        printf("Rank:%d , %d\n",rank,a*a);
    }
    else
    {
        int a=0;

        MPI_Recv(&a,1,MPI_INT,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        
        printf("Rank:%d , %d\n",rank,a*a*a);
    }

    MPI_Buffer_detach(buffer,&buffersize);

    MPI_Finalize();
    return 0;

}
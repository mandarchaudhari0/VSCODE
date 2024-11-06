#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, n = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Process 0 reads an integer and initiates the send
        printf("Enter an integer value:\n");
        scanf("%d", &n);

        // Send to the next process (rank 1)
        MPI_Send(&n, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Process %d sent %d to process 1\n", rank, n);

        // Receive the integer back from the last process
        MPI_Recv(&n, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received %d back from process %d\n", rank, n, size - 1);
    } else {
        // Each non-root process receives from the previous rank
        MPI_Recv(&n, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received %d from process %d\n", rank, n, rank - 1);

        // Send to the next rank (loop back to 0 if it’s the last process)
        int next_rank = (rank + 1) % size;
        MPI_Send(&n, 1, MPI_INT, next_rank, 0, MPI_COMM_WORLD);
        printf("Process %d sent %d to process %d\n", rank, n, next_rank);
    }

    MPI_Finalize();
    return 0;
}

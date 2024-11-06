#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, n = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter an integer value:\n");
        scanf("%d", &n);

        // Send initial value from process 0 to process 1
        MPI_Send(&n, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
        printf("Sent from process %d\n", rank);

        // Receive the final value back from the last process
        MPI_Recv(&n, 1, MPI_INT, size - 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Received Back In Process %d, %d\n", rank, n);
    }

    for (int i = 1; i < size - 1; i++) {
        if (rank == i) {
            // Each process receives from the previous process
            MPI_Recv(&n, 1, MPI_INT, rank - 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Received %d in process %d\n", n, rank);

            // Each process sends to the next process
            MPI_Send(&n, 1, MPI_INT, rank + 1, 1, MPI_COMM_WORLD);
            printf("Sent from process %d\n", rank);
        }
    }

    if (rank == size - 1) {
        // The last process receives from the previous rank
        MPI_Recv(&n, 1, MPI_INT, size - 2, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Received %d in process %d\n", n, rank);

        // The last process sends back to the root process (process 0)
        MPI_Send(&n, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
        printf("Sent from process %d\n", rank);
    }

    MPI_Finalize();
    return 0;
}

#include<stdio.h>
#include<mpi.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

char toggle(char ch)
{
    if (isupper(ch))
    {
        return tolower(ch);
    }
    if (islower(ch))
    {
        return toupper(ch);
    }
    return ch;
}

int main(int argc, char*argv[])
{
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    char word[50];

    if(rank==0)
    {
        printf("Enter a word\n");
        scanf("%s",word);

        MPI_Ssend(word,50,MPI_CHAR,1,1,MPI_COMM_WORLD);

        MPI_Recv(word,50,MPI_CHAR,1,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

        printf("%s",word);
    }

    if(rank==1)
    {
        MPI_Recv(word,50,MPI_CHAR,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

        for(int i=0;i<strlen(word);i++)
        {
            word[i] = toggle(word[i]);
        }

        MPI_Ssend(word,50,MPI_CHAR,0,1,MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
#include<stdio.h>
#include<mpi.h>
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

int main(int argc,char* argv[])
{
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    char str[100];

    if(rank==0)
    {
        fgets(str,100,stdin);
    }

    MPI_Bcast(str,100,MPI_CHAR,0,MPI_COMM_WORLD);

    if(rank<strlen(str))
    {
        str[rank] = toggle(str[rank]);
    }

    puts(str);

    MPI_Finalize();
    return 0;
}
#include<stdio.h>
#include<omp.h>
#include<ctype.h>
#include<string.h>

char toggle_char(char ch)
{
    if(islower(ch))
    {
        ch = toupper(ch);
    }
    else if(isupper(ch))
    {
        ch = tolower(ch);
    }
    return ch;
}

int main()
{
    char txt[]="Hello World";

    int n = strlen(txt);

    #pragma omp parallel num_threads(n)
    {
        int thread_id = omp_get_thread_num();
        txt[thread_id] = toggle_char(txt[thread_id]);
    }
    puts(txt);
    return 0;
}
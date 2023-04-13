#include <stdio.h>
#include <unistd.h>

/* 
    Creates the following process hierarchy:

      A
     /|\ 
    B C D
      |
      E
*/

int main()
{
    printf("A = %i", getpid());
    printf("\n");

    int B = fork();
    
    if(B == 0)
    {
        printf("B = %i; child of %i", getpid(), getppid());
        printf("\n");
    }

    else
    {
        int C = fork();

        if(C == 0)
        {
            printf("C = %i; child of %i", getpid(), getppid());
            printf("\n");

            int E = fork();

            if(E == 0)
            {
                printf("E = %i; child of %i", getpid(), getppid());
                printf("\n");
            }
        }

        else
        {
            int D = fork();

            if(D == 0)
            {
                printf("D = %i; child of %i", getpid(), getppid());
                printf("\n");
            }
        }
    }

    return 0;
}
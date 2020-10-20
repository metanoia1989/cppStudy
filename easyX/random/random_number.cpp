#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int r; 
    for (int i=0; i<10; i++)
    {
        r = rand();    
        printf("%d\n", r);
    }

    return 0;
}

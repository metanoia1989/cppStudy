#include "apue.h"

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < argc; i++)
    {
        printf("argv[%ld]: %s\n", i, argv[i]);
    }

    return 0;
}

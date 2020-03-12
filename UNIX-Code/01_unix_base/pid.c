#include "apue.h"

int main(int argc, char const *argv[])
{
    printf("hello world from process ID %ld\n", (long)getpid());

    return 0;
}

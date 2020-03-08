#include "apue.h"
#include <errno.h>

int main(int argc, char const *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    perror(argv[0]);
    errno = ENOENT;
    exit(0);
}

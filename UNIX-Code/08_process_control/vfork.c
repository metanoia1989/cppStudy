#include "apue.h"

int globvar = 6;

int main(int argc, char const *argv[])
{
    int var;
    pid_t pid;

    var = 88;
    printf("before vfork\n");
    if ((pid = vfork()) < 0) {
        err_sys("vfork error");
    } else if (pid == 0) { // child
        globvar++;
        var++;
        _exit(0); // child terminates
    }

    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

    return 0;
}

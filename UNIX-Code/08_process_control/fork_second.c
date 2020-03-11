#include "apue.h"
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) { // first child
        if ((pid = fork()) < 0) { 
            err_sys("fork error");
        } else if (pid > 0) {
            exit(0); // parent from second fork == first child
        }

        sleep(2);
        printf("second child, parent pid = %ld\n", (long)getppid());
        exit(0);
    }

    if (waitpid(pid, NULL, 0) != pid)
        err_sys("waitpid erro");

    return 0;
}

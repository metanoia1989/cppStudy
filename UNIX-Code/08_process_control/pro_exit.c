#include "apue.h"
#include <sys/wait.h>

void pr_exit(int status)
{
    if (WIFEXITED(status)) {
        printf("normal termination, exit status = %d\n",
            WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("abnormal ternimation, signal number = %d%s\n", 
            WTERMSIG(status),
#ifdef WCOREDUMP
            WCOREDUMP(status) ? " (core file generated)" : ""); 
#else
            "");
#endif // WCOREDUMP
    } else if (WIFSTOPPED(status)) {
        printf("child stopped, signal number = %d\n",
            WSTOPSIG(status));
    }
}
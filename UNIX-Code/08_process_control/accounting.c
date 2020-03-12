#include "apue.h"

int main(int argc, char const *argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid != 0) { // parent
        sleep(2);
        exit(2);
    }

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid != 0) { // firt child 
        sleep(4);
        abort();
    }

    if ((pid = fork()) < 0) {
        err_sys("fork error"); 
    } else if (pid != 0) { // second child
        execl("/bin/dd", "dd", "if=/etc/passwd", "of=/dev/null", NULL);
        exit(7);
    }

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid != 0) {
        sleep(8);
        exit(0);
    }

    sleep(6); // fourth child
    kill(getpid(), SIGKILL);
    exit(6);
}

#include <signal.h>
#include <unistd.h>
#include <setjmp.h>
#include <stdio.h>
#include "apue.h"

static jmp_buf env_alrm;
static void sig_alrm(int signo);
unsigned int sleep2(unsigned int seconds);
static void sig_int(int signo);

int main(int argc, char const *argv[])
{
    unsigned int unslept;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal(SIGINT) error");
    unslept = sleep2(5);
    printf("sleep2 returned: %u\n", unslept);

    return 0;
}

static void sig_alrm(int signo)
{
    longjmp(env_alrm, 1);
}

static void sig_int(int signo)
{
    volatile int k;

    printf("\nsig_int starting\n");
    for (int i = 0; i < 300000; i++) {
        for (int j = 0; j < 4000; j++) 
            k += i * j; 
    }
    printf("sig_int finished\n");
}

unsigned int sleep2(unsigned int seconds)
{
    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
        return seconds;

    if (setjmp(env_alrm) == 0) {
        alarm(seconds);
        pause();
    }
    return alarm(0);
}
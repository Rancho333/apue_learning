#include "../apue.h"
#include <sys/wait.h>

static void sig_init(int);          /* our signal-catching function*/

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_init) == SIG_ERR)
        err_sys("signal error");

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL){
        if (buf[strlen(buf) -1] == '\n')
            buf[strlen(buf) - 1] = 0;

        if ((pid = fork()) < 0){
            err_sys("fork error!\n");
        } else if (pid == 0){                   /*child*/
            execlp(buf, buf, (char *)0);
            printf("couldn't execute:%s", buf);
            exit(127);
        }

        /*parent*/
        if ((pid = waitpid(pid, &status, 0)) < 0){
            printf("waitpid error\n");
            exit(1);
        }

        printf("%% ");
    }
    return 0;
}

void sig_init(int signo)
{
    printf("interrupt\n%%");
}

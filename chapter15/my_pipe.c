#include "../apue.h"

int main(void)
{
    int n;
    int fd[2], fd2[2];
    pid_t pid;
    char line[MAXLINE];
    char *buf = "hello from parent!\n";
    char *buf2 = "hello form child\n";
    if (pipe(fd) < 0)
        err_sys("pipe error");
    if(pipe(fd2) < 0)
        err_sys("pipe error");
    if ((pid = fork()) < 0){
        err_sys("fork error");
    } else if (pid > 0)
    {
        close(fd[0]);
        close(fd2[1]);
        write(fd[1], buf, strlen(buf));

        n = read(fd2[0], line, MAXLINE);
        fwrite(line, n, 1, stdout);
    } else {
        close(fd[1]);
        close(fd2[0]);
        n = read(fd[0], line, MAXLINE);
        fwrite(line, n, 1, stdout);

        write(fd2[1], buf2, strlen(buf2));
    }

    return 0;
}

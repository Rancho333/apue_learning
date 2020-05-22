#include "../apue.h"
#include <sys/wait.h>

int main(void)
{
    char line[MAXLINE];
    char buf[MAXLINE];
    FILE *fpin;

    if ((fpin = popen("./myuclc", "r")) == NULL)
        err_sys("popen error");

    while (1){
        fputs("prompt> ", stdout);
        /*标准输出通常是行缓冲的，而提示并不包含换行符，所以在写了提示之后，需要
         * 调用fflush*/
        fflush(stdout);
        if (fgets(line, MAXLINE, fpin) == NULL)    /*read from pipe*/
            break;

        if(fputs(line, stdout) == EOF)
            err_sys("fputs error to pipe");
        
       // if(fgets(buf, MAXLINE, stdin))
       //     printf("zhw test:%s", buf);
    }
    if (pclose(fpin) == -1)
        err_sys("pclose error");

    putchar('\n');

    return 0;
}

#include "../apue.h"

static void character_time(char *);

int main(void)
{
    pid_t pid;
        
    TELL_WAIT();

    if((pid = fork()) < 0){
        err_sys("fork error");
    }   else if (pid == 0) {
        //WAIT_PARENT();
        character_time("output from child process\n");
        TELL_PARENT(getppid());
    } else {
        WAIT_CHILD();
        character_time("output from parent process\n");
        //TELL_CHILD(pid);
    }
    return 0;
}

static void character_time(char *str)
{
    char *ptr;
    int c;

    setbuf(stdout, NULL);               /*set unbuffered*/
    for (ptr = str; (c = *ptr++) != 0; )
        putc(c, stdout);
}

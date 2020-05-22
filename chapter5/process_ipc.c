#include "../apue.h"

TELL_WAIT();                /*set things up for TELL_xxx & WAIT_xxx*/

if ((pid = fork()) < 0){
    err_sys("fork error");
}   else if (pid == 0) {        /*child*/
    /*child does whatever is necessary ...*/
    TELL_PARENT(getppid());     /*tell parent we're done*/
    WAIT_PARENT();              /*and wait for parent*/
    /*and the child continues on its necessary ...*/
    exit(0);
}

/*parent does whatever is necessary ...*/
TELL_CILD(pid);                 /*tell child we're done*/
WAIT_CHILD();                   /*and wait for child*/
/*and the parent continues on its way ...*/
exit(0);

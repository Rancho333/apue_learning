#include "../apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        err_quit("usage: ./a.out <pathname>");
    /*access 在内核中使用的是实际用户ID*/
    if (access(argv[1], R_OK) < 0)
        err_ret("access error for %s", argv[1]);
    else
        printf("read access OK\n");
    
    /*open在内核中使用的是有效用户ID*/
    if (open(argv[1], R_OK) < 0)
        err_ret("open error for %s", argv[1]);
    else
        printf("open for reading OK\n");

    return 0;
}

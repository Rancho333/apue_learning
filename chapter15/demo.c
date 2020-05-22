#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    if(fork());
        //exit(0);

    while(1){
        sleep(1);
    }
    return 0;
}       

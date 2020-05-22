#include <signal.h>
#include <unistd.h>

int main(void)
{
    alarm(10);
    while(1);
    return 0;
}

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>


int main(int argc, char* argv[])
{
    pid_t curr = getpid();
    pid_t par = getppid();
    printf("pid and parent pid:\n%d %d \n", curr, par);

    int r = execlp("ps", "ps", "-f", 0);
    perror("exec");
    printf("exec:\n%d \n" ,r);
}

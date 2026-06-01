#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>


int main(int argc, char* argv[])
{
    int child = fork();
    printf("pid ppid and fork:\n%d %d %d \n" , getpid(), getppid(), child);
}

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char* argv[])
{
    printf("pid ppid:\n%d %d \n" , getpid(), getppid());
    
    pid_t child = fork();

    printf("fork pid ppid: %d %d %d\n", child, getpid(), getppid());
    int status;

    if( child > 0 ) 
    {
        pid_t wait_pid = wait(&status);

        printf("pid and return code: %d %d\n", wait_pid, status);
    }
}

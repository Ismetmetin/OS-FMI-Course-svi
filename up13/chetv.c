#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char* argv[])
{
    printf("pid ppid:\n%d %d \n" , getpid(), getppid());
    
    pid_t child = fork();

    printf("fork pid ppid: %d %d %d\n", child, getpid(), getppid());
    if(child == 0) 
    {
        return execlp("ls", "ls", "-l", 0);
    }
    else
    {

        int status;
        
        pid_t wait_pid = wait(&status);

        printf("pid and return code of ls: %d %d\n", wait_pid, status);
    }
}


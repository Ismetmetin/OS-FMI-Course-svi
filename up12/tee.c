#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{ //stdin -> slaga go vuv file/stdout. produljava sus sushtiq vhod
        
        if (argc != 2) return 1;

        
        int fd = open( argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644 );
        if (fd <=0) return 2;
        
        int count = -1;
        char buff[4096];
        
        while( (count = read(0, buff, 4096) ) > 0 ) //0 e fd za stdin
        {
            if (write(fd, buff, count) == -1) 
            {
                perror("error writing to file");
            }
            
            if (write(1,buff,count) == -1) //1 e fd za stdout
            {
                perror("Error writing to stdout");
                close(fd);
                return 3;
            }
        }
 if (count<0) 
 {
     perror("Error reading input");
     close(fd);
     return 1;
 }
    close(fd);

    return 0;
}




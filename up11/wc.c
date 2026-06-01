#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main (int argc, char* argv[])
{
    if ( argc != 2)
    {
        printf("An issue with the parameters\n");
        return -1;
    }

    int rd_fd = open(argv[1], O_RDONLY);
    if ( rd_fd == -1) {printf("error with reading file\n"); return -1;}
    
    int bytes = 0; 
    int lines = 0;
    int words = 0;

    char buffer[4096];
    ssize_t bytes_read;
    
    int in_word = 0;
    
    while((bytes_read = read(rd_fd, buffer, 4096)) > 0)
    {
        for ( int i = 0; i < bytes_read; i++)
        {
            char c = buffer[i];

            ++bytes;            
            if( c == '\n' ) ++lines;

            if( c == '\t' || c == ' ' || c == '\n' || c == '\r')
            {
                in_word=0;
            } else if(in_word == 0) 
            {
                in_word = 1;
                ++words;
            }
        }
    }
    
    if (bytes_read == -1)
    {
        printf("error readin file!\n");
        close(rd_fd);
    }

    printf("%d %d %d %s \n",bytes,words,lines, argv[1]);

    return  0;
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main (int argc, char* argv[])
{
    if ( argc != 3)
    {
        printf("An issue with the parameters\n");
        return -1;
    }

    int rd_fd = open(argv[1], O_RDONLY);
    if ( rd_fd == -1) {printf("error with reading file\n"); return -1;}

    int wr_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (wr_fd == -1) {printf("error with writing file\n"); close(rd_fd); return -1;}
   
    char buffer[4096];
    ssize_t bytes_read = read(rd_fd, buffer, 4096);
    
    
    while(bytes_read > 0)
    {
        if (write(wr_fd, buffer, bytes_read) != bytes_read) {
            printf("Error writing to destination file");
            close(rd_fd);
            close(wr_fd);
            return -1;
        }

        bytes_read = read(rd_fd, buffer, 4096);
    }
    

    close(rd_fd);
    close(wr_fd);
    return  0;
}

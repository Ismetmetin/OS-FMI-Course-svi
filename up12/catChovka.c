#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    //trqbva da se podadat pone 3 argumenta che da ne stane na laina
    if (argc <= 2) return -1;

    char buffer[2048];
    int count = -1;
    
    int fdw = open(argv[argc-1], O_TRUNC | O_WRONLY | O_CREAT, 0644);
    if (fdw < 0) {
        perror("Error opening output file");
        return 1;
    }
 
    for (int i = 1; i < argc-1; ++i)
    {
        int fhr = open(argv[i], O_RDONLY);
        if (fhr < 0) {
            perror("Error opening input file");
            continue; //skipvam tozi file 
        }

        while((count = read(fhr, buffer, sizeof(buffer))) > 0)
        {
            if (write(fdw, buffer, count) != count) {
                perror("Error writing to output file");
                close(fhr);
                close(fdw);
                return 1;
            }
        }

        close(fhr);     }
    
    close(fdw); 
    return 0;
}

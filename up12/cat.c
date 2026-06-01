#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char buffer[2048];
    int count = -1;
    for (int i = 1; i < argc; ++i)
    {
        int fh = open( argv[i], O_RDONLY);
        
        while((count= read(fh,buffer,2048)) > 0)
        {

            for(int j = 0; j < count; ++j)
            {
                printf("%c",buffer[j]);
            }

        }

        close(fh);

        count = -1;
    }
    
    return 0;
}



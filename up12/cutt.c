#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{   
    int m,n;
    
    scanf("%d %d", &m,&n);
    //read(0, &m,sizeof(int));
    //read(0, &n,sizeof(int));
    
    printf("%d %d\n", m, n);
    char car;
    int counter = 0;

    int fd = open(argv[1],O_RDONLY);

    if(fd < 0 ) {printf("stana kur\n"); return 1;}

    while( (read(fd,&car,1)) > 0 )
    {
        ++counter;
        if( car =='\n' ) 
        {
            counter = 0;
            write(1,"\n",1);


        }
        else if(counter >= m && counter <= n)
        {
            write(1,&car,1);
        }
    }
    

}

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


#define KB 1000
#define O_RDWR 0x002
#define O_CREATE 0x200
static char* buf[10*1000*KB];


int main(int argc, char *argv[])
{
    int fd, check_location;
    const char* fname = "test_memory_size";

    if( (fd = open(fname,  O_CREATE | O_RDWR)) >= 0)
    {
        if( (check_location = write(fd,buf, 12*KB)) != 12*KB){
            printf("failed direct\n");
            close(fd);
            exit(-1);
        }
        printf("Finished writing 12KB (direct)\n");


        if( (check_location = write(fd,buf, 256*KB)) != 256*KB){
            printf("failed single indirect\n");
            close(fd);
            exit(-1);
        }
        printf("Finished writing 268KB (single indirect)\n");


        if( (check_location = write(fd,buf, 9732*KB)) != 9732*KB){
            printf("failed Dindirect\n");
            close(fd);
            exit(-1);
        }
        printf("Finished writing 10MB \n");
        close(fd);
    }    
  exit(0);
}
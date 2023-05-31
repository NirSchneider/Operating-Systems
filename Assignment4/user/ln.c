#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc < 3 || argc >4){
    fprintf(2, "Usage: ln old new  |  ls -s old new\n");
    exit(0);
  }

  //NEW
  if(strcmp(argv[1],"-s"))
  {
    if(link(argv[1], argv[2]) < 0)
    {
      printf("link %s %s: error\n", argv[1], argv[2]);
    }
    exit(0);
  }
  char *oldpath = argv[2];
  char *newpath = argv[3];
  if(symlink(oldpath, newpath) !=0)
  {
    printf("symlink %s %s: error", oldpath, newpath);
  }
  exit(0);

  // if(link(argv[1], argv[2]) < 0)
  //   fprintf(2, "link %s %s: failed\n", argv[1], argv[2]);
  // exit(0);
}

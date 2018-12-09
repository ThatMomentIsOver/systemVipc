#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int
main(int argc, char **argv) {
  struct stat st;

  if (argc != 2) {
    printf("usage: ftok <pathname>");
    return 1;
  }

  stat(argv[1], &st);
  printf( "st_dev: %lx, st_ino: %lx, key:%x\n", 
                  (u_long) st.st_dev, (u_long) st.st_ino,
                  ftok(argv[1], 0x57) );

  exit(0);

}

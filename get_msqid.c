#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_R 0400
#define MSG_W 0200
#define SVMSG_MODE  (MSG_R | MSG_W | MSG_R>>3 | MSG_R>>6)

int main (int argc, char **argv) {
  int i, msqid;

  for(i=0; i < 10; i++) {
    msqid = msgget(IPC_PRIVATE, SVMSG_MODE | IPC_CREAT);
    printf("msqid = %d\n", msqid);
    msgctl(msqid, IPC_RMID, NULL);
  }

  exit(0);
}

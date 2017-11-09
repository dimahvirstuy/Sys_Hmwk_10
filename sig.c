#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

static void sig(int signo) {

  if (signo==SIGINT) {
    int fd;
    fd = open("foo",O_WRONLY | O_APPEND | O_CREAT,0644);
    char s[]="SIGINT signal recieved, closing File...\n";
    write(fd,s,sizeof(s));
    printf("Wrote to file\n");
    close(fd);
    exit(0);

  }
  if (signo==SIGUSR1) {
    printf("Parent Process num: %d\n",getppid());

  }

}

int main() {

  signal(SIGINT,sig);
  signal(SIGUSR1,sig);

  while(1) {
    printf("signal.c PID: %d \n",getpid());
    sleep(1);

  }
}

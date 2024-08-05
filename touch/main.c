#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

struct timespec getCurrentTime(void) {
  time_t t = time(NULL);
  struct timespec ts = {.tv_sec = t, .tv_nsec = 0};
  return ts;
}

int main(int argc, char **argv) {

  if (argc < 2) {
    perror("Please provide a file");
    return 1;
  }

  char *filename = argv[1];

  int fd = open(filename, O_CREAT);
  if (fd < 0) {
    perror("file failed to open");
    return 1;
  }

  struct timespec ts = getCurrentTime();
  struct timespec tsa[] = {ts, ts};

  int f = futimens(fd, tsa);
  if (f < 0) {
    perror("failed to set time");
    return 1;
  }

  return 0;
}

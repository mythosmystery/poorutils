#include <fcntl.h>
#include <stdio.h>
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
  printf("file: %s\n", filename);

  int fd = open(filename, O_CREAT);
  if (fd < 0) {
    perror("file failed to open");
    return 1;
  }

  printf("fd: %d", fd);

  return 0;
}

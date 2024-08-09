#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int createDirRecursize(const char *dirname) {

  char *dir = strdup(dirname);
  char *str = strtok(dir, "/");

  return -1;
}

int main(int argc, char **argv) {

  int result;

  /* if (argc < 2) { */
  /*   fprintf(stderr, "not enough args"); */
  /*   return 1; */
  /* } */
  /**/
  /* const char *dirname = argv[argc - 1]; */
  const char *dirname = "foo/bar/baz";

  result = mkdir(dirname, 0);
  if (result < 0) {
    if (errno == ENOENT) {
      result = createDirRecursize(dirname);
      if (result >= 0) {
        return 0;
      }
    }

    const char *msg = "cannot create directory '%s'";
    char *s = (char *)malloc(strlen(dirname) + strlen(msg));
    sprintf(s, msg, dirname);
    perror(s);

    return 1;
  }

  return 0;
}

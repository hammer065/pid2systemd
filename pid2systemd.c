#include <systemd/sd-login.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  const char *suffix = ".service";
  const char suffixLen = strlen(suffix);
  char onlyServices = (argc > 1 && strcmp(argv[1], "-s") == 0);
  char *name;
  int pid = 0, len = 0;
  while(scanf("%i", &pid) > 0)
  {
    if(sd_pid_get_unit(pid, &name) >= 0)
    {
      len = strlen(name);
      if(!onlyServices || (onlyServices && len > 8 && strcmp((name + len - suffixLen), suffix) == 0))
      {
        printf("%s\n", name);
        free(name);
        continue;
      }
      else
      {
        free(name);
      }
    }
    fprintf(stderr, "%i\n", pid);
  }
  return 0;
}

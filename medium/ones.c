#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int count_ones(char * line)
{
  uint32_t x = atoi(line);
  int result = 0;
  int bit_num = 0;

  while (bit_num < 32) {
    if (x & (1 << bit_num))
      result++;
    bit_num++;
  }

  return result;
}

int main(int argc, char** argv)
{
  char line[1024];
  FILE * fd = fopen(argv[1], "r");
  
  while (fgets(line, sizeof(line), fd))
  {
    /* Skip empty lines */
    if (line[0] == '\n')
      continue;
    printf("%d\n", count_ones(line));
  }
  
  fclose(fd);

  return 0;
}

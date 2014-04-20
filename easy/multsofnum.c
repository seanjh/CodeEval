#include <stdio.h>
#include <stdint.h>
#include <string.h>

void parse_line(char line[], uint32_t *x, uint32_t *n)
{
   char *pt;
   pt = strtok (line, ",");
   uint32_t temp;
    while (pt != NULL) {
        temp = atoi(pt);
        if (temp > 0) {
            if (*x == 0)
                *x = temp;
            else if (*n == 0)
                *n = temp;
        }
        pt = strtok (NULL, ",");
     }
}

int process_line(char line[])
{
   uint32_t x = 0;
   uint32_t n = 0;
   parse_line(line, &x, &n);
   uint32_t result = n;
   uint32_t i = 2;
   while (result < x) {
        result = n * i;
        i++;
   }
   return result;
}

int main(int argc, char** argv)
{
   FILE*    fd;
   char     line[1024];

   fd = fopen(argv[1], "r");

   while (fgets(line, sizeof(line), fd))
   {
      /* Skip empty lines */
      if (line[0] == '\n')
         continue;
      printf("%d\n", process_line (line));
   }
   return 0;
}

#include <stdlib.h>
#include <stdio.h>

int get_next_int(char **line)
{
    int result = 0;
    int tmp;
    while ((*line)[0] >= '0' && *(line[0]) <= '9')
    {
        result *= 10;
        result += (*line)[0] - '0';
        (*line)++;
    }
    (*line)++;
    return result;
}

int parse_line(char line[])
{
    int val = get_next_int(&line);
    int p1 = get_next_int(&line);
    int p2 = get_next_int(&line);
    //printf("val: %d, p1: %d, p2: %d\n", val, p1, p2);

    //print_bits(val);
    p1--;
    p2--;
    // ((val & (1 << p1)) >> p1)
    // ((val & (1 << p2)) >> p2)
    return ((val & (1 << p1)) >> p1) == ((val & (1 << p2)) >> p2);
}

int print_bits(int val)
{
    int i;
    for (i = 31; i >= 0; i--)
    {
      if (val & (1 << i))
        printf("1");
      else
        printf("0");
    }
    printf("\n");
}

int main(int argc, char **argv)
{
  if (argc < 2)
    {
        fprintf(stderr, "Error! No filename provided.");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    char line[1024];

    int result;
    while (fgets(line, sizeof(line), fp))
    {
        if (line[0] == '\n' || line[0] == '\r')
            continue;
        result = parse_line(line);
        if (result)
          printf("true\n");
        else
          printf("false\n");
    }

    return 0;
}

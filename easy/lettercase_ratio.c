#include <stdio.h>
#include <stdlib.h>

void count_case(char line[], int * lower, int * total)
{
    while (line[0] != '\0')
    {
        //printf("character: %c lower: %d, total: %d \n", line[0], *lower, *total);
        if (line[0] >= 'a' && line[0] <= 'z')
            (*lower)++;
        if (line[0] != '\n' && line[0] != '\r')
            (*total)++;
        line++;
    }
}

int main(int argc, char **argv)
{
    if ( argc < 2)
    {
        fprintf(stderr, "ERROR. Missing filename.\n");
        return 1;
    }

    FILE * infile = fopen(argv[1], "r");
    char line[1024];

    // total characters
    // total lowercase characters

    int lower;
    int total;
    double result;

    while (fgets(line, sizeof(line), infile))
    {
        // Skip empty lines
        if ( line[0] == '\n' || line[0] == '\r' )
            continue;

        lower = 0;
        total = 0;
        count_case(line, &lower, &total);

        if ( total > 0)
        {
            result = ((double) lower) / total * 100;
            printf("lowercase: %0.2f ", result);
            result = (1 - (((double) lower) / total)) * 100;
            printf("uppercase: %0.2f\n", result);
        }
        else
        {
            printf("ERROR! Cannot divide by 0\n");
            continue;
        }
    }
}

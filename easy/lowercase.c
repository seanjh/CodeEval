#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if ( argc < 2)
        return 1;

    FILE *fp = fopen(argv[1], "r");
    //char line[1024];
    char c;

    //while ( fgets(line, sizeof(line), fp) )
    while ( (c = fgetc(fp)) != EOF )
    {
        if (c >= 'a' && c <= 'z')
            putchar(c);
        else if (c >= 'A' && c <= 'Z')
            putchar(c + 32);
        else
            putchar(c);
    }

    fclose(fp);
}
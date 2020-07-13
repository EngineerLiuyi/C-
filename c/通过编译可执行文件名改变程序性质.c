#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv) /* lower: convert input to lower case*/
{
    printf("argc : %d, argv[0]: %s\n",argc, argv[0]);
    int c;
    const char* tolowercase = "./lower";
    const char* touppercase = "./upper";
    if(strcmp(argv[0], tolowercase) == 0)
        while ((c = getchar())!= EOF)
            putchar(tolower(c));
    else if(strcmp(argv[0], touppercase) == 0)
        while ((c = getchar())!= EOF)
            putchar(toupper(c));
    else
        while ((c = getchar())!= EOF)
            putchar(c);
    return 0;
}


#include <stdio.h>

int main(int argc, char **argv) /* lower: convert input to lower case*/
{
    double a = 123456.789123456;
    printf("double a = 123456.789123456;\n");
    printf("%%-10.1f: |%-*.1f|\n",10, a);
    printf("%%e:      |%e|\n", a);
    printf("%%E:      |%E|\n", a);
    double ae = 1.23456e6;
    printf("double ae = 1.23456e6;\n");
    printf("%%.5g:    |%.5g|\n", ae);
    printf("%%.8G:    |%.8G|\n", ae);
    char* c = "abcdefg";
    printf("char* c = \"abcdefg\"\n");
    printf("%%s:      |%s|\n", c);
    printf("%%p:      |%p|\n", c);
    printf("(*c)%%c:  |%c|\n", *c);
    int b = 84567;
    printf("int b = 84567;\n");
    printf("(-b)%%i:  |%i|\n", -b);
    printf("%%o:      |%o|\n", b);
    printf("%%x:      |%x|\n", b);
    printf("%%X:      |%X|\n", b);
    printf("(-b)%%u:  |%u|\n", -b);
    return 0;
}

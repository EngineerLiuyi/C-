#include <stdio.h>
#include <stdlib.h>
/*
int main(int argc, char** argv)
{
    char* filename = "file2.txt";
    FILE *fp1 = fopen(filename, "w");

    for(double i = 0 ; i < 10000 ; i++)
    {
        fprintf(fp1, "[file 2] for loop process %f %% 100 \n", i / 10000);
    }

    fclose(fp1);

    return 0;
}*/

int main(int argc, char *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);

    char *prog = argv[0]; /* program name for errors */
    if (argc == 1 ) /* no args; copy standard input */
        filecopy(stdin, stdout);
    else
        while (argc-- > 1)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n",prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}

void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}


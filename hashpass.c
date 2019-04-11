#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"

int main(int argc, char *argv[])
{
    FILE *h = fopen(argv[1], "r");
    if(!h)
    {
        printf("Can't open %s.\n", argv[1]);
        exit(1);
    }
    
    FILE *d = fopen(argv[2], "w");
    if(!d)
    {
        printf("Can't open %s.\n", argv[2]);
        exit(1);
    }
    
    char word[100];
    while (fgets(word, 100, h) != NULL)
    {
        word[strlen(word) - 1] = '\0';
        char  *wordhash = md5(word, strlen(word));
        //fprintf(d, "%s \t %s\n", wordhash, word);
        fprintf(d, "%s\n", wordhash);
    }
    
    fclose(d);
    fclose(h);
}
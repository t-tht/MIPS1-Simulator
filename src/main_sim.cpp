#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include "memory.hpp" 
#define BUFSZ 1000000

using namespace std;

int main (int argc, char **argv) {

    unsigned char ROM[BUFSZ] = {0};
    size_t bytes = 0, i, readsz = sizeof ROM;
    FILE *fp = argc > 1 ? fopen (argv[1], "rb") : stdin;

    if (!fp) {
        fprintf (stderr, "error: file open failed '%s'.\n", argv[1]);
        return 1;
    }

    /* read/output BUFSZ bytes at a time */
    while ((bytes = fread (ROM, sizeof *ROM, readsz, fp)) == readsz) {
        for (i = 0; i < readsz; i++)
            printf (" 0x%02x", ROM[i]);
        putchar ('\n');
    }

	//mem_print(ROM,bytes);
	//for (i = 0; i < bytes; i++) /* output final partial buf */
      // printf (" 0x%02x", ROM[i]);
    //putchar ('\n');

    if (fp != stdin)
        fclose (fp);

    return 0;
}
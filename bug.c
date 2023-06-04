// Define main function:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int x = 1;

int main(int argc, char *argv[]) {
    if (5 % (3 * x) + 2 != 4) {
        printf("Hello, world!\n");
    }
    return 0;
}

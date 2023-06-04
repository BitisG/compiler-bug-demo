#include <stdio.h>
#include <string.h>

int main () { // compile with gcc -Wall -O2 -c bug.c
    char a[] = "\0abc";
    return __builtin_memcmp (a, "\0\0\0\0", 4);
  }

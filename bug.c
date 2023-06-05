#include <stdio.h>

#define DEBUG_NOPRINT "\0NOPRINT"

#define NO_DEBUG_INFO(dbg_lvl) (__builtin_memcmp(dbg_lvl, DEBUG_NOPRINT, sizeof(DEBUG_NOPRINT)))

#define debug_continue(condition, dbg_lvl, str, ...) {                         \
    int no_info = NO_DEBUG_INFO(dbg_lvl);                                      \
    if (condition && (no_info != 0)) {                                         \
        printf("Didn't work, try again!\n",no_info);                           \
        continue;                                                              \
    }                                                                          \
}

int main() {
   char DEBUG_PRINT[9] = "";
   for (int i = 0; i < 10; i++) {
      debug_continue((0 != 1), DEBUG_PRINT, "No user match, continuing to search\n");
      printf("Hacked\n");
   }
   return 0;
}
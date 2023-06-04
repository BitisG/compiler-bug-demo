// Define main function:

int x = 1;

int main(int argc, char *argv[]) {
    if (5 % (3 * x) + 2 != 4) {
       __builtin_abort();
    }
    return 0;
}

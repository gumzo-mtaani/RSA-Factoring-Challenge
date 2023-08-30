#include <stdio.h>
#include <stdlib.h>

// Function to factorize a number and print its factorization
void factorize(int n) {
    int i;
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%d=%d*%d\n", n, i, n / i);
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: factors <file>\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int number;
    while (fscanf(input_file, "%d", &number) != EOF) {
        if (number > 1) {
            factorize(number);
        }
    }

    fclose(input_file);
    return 0;
}


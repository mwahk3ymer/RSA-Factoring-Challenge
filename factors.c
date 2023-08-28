#include <stdio.h>
#include <stdlib.h>

int factorize(int n, int *p, int *q) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            *p = i;
            *q = n / i;
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int n;
    while (fscanf(file, "%d", &n) != EOF) {
        int p, q;
        if (factorize(n, &p, &q)) {
            printf("%d=%d*%d\n", n, p, q);
        } else {
            printf("%d is prime\n", n);
        }
    }

    fclose(file);
    return 0;
}

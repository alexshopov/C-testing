#include <stdio.h>
#include "operations.h"

int main(int argc, char **argv) {
    char op;
    int a, b;

    scanf("%c %d %d", &op, &a, &b);

    switch(op) {
        case '+':
            printf("%d\n", add(a, b));
            break;
        case '-':
            printf("%d\n", sub(a, b));
            break;
        default:
            printf("\n");
    }

    return 0;
}

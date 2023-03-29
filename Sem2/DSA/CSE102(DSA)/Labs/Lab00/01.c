// Lab01 Q1

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int x, y;
    int rev = 0;

    scanf("%d", &x);

    y = x;

    while (y != 0) {
        rev = (rev * 10) + (y % 10);
        y /= 10;
    }

    if (rev == x) {
        printf("Yes");
    }
    else {
        printf("No");
    }

    return 0;
}
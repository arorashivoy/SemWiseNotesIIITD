#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

long long int days = 0;

void doAssignment(long long int a[], int l, int r) {
    int min = a[l];
    int minIndex = l;

    for (int i = l + 1; i < r; i++) {
        if (min > a[i]) {
            min = a[i];
            minIndex = i;
        }
    }

    days += min;
    for (int i = l; i < r; i++) {
        a[i] -= min;
    }

    if (l < minIndex) {
        doAssignment(a, l, minIndex);
    }

    if (r > minIndex + 1) {
        doAssignment(a, minIndex + 1, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    long long int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%lld", a + i);
    }

    doAssignment(a, 0, n);

    printf("%lld", days);

    return 0;
}
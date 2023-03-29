#include <stdio.h>

int main() {
    long int n;
    long long int k;
    long long unsigned int t = 0;

    long long unsigned int a[n];

    scanf("%ld", &n);
    scanf("%lld", &k);

    for (long int i = 0; i < n; i++) {
        scanf("%llu ", a + i);
    }

    while (k > 0) {
        t += 1;

        for (long int i = 0; i < n; i++) {
            if (((long long unsigned int)t % (long long unsigned int)a[i]) == 0) {
                k -= 1;
            }
        }
    }

    printf("%llu", t);




    return 0;
}
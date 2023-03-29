#include <stdio.h>

long long int x;
int flag = 0;

void createArr(int i, int k, long long int b[k], int index, int n, long long int a[n]) {
    if (flag == 0) {
        if (index == n + 1);
        else if (i == k) {
            long long int sum = 0;
            for (int j = 0; j < k - 1; j++) {
                sum += b[j];
            }


            sum *= b[k - 1];

            if (sum == x) {
                flag = 1;
                printf("Yes");
            }
        }
        else {
            createArr(i, k, b, index + 1, n, a);
            b[i] = a[index];
            createArr(i + 1, k, b, index + 1, n, a);
        }
    }
}


int main() {
    int n, k;

    scanf("%d %d %lld", &n, &k, &x);

    long long int a[n];
    long long int b[k];

    for (int i = 0; i < n; i++) {
        scanf("%lld ", a + i);
    }

    createArr(0, k, b, 0, n, a);

    if (flag == 0) {
        printf("No");
    }


    return 0;
}
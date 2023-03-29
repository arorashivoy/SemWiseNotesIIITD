#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef long long ll;
const ll inf = 1e9;

int cmpfunc(const void* a, const void* b) {
    return (*(ll*)a - *(ll*)b);
}

ll a[100001], pre[100001];

int main() {
    int n; ll k;
    scanf("%d %lld", &n, &k);
    a[0] = -inf;
    memset(pre, 0, sizeof(pre));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i + 1]);
    }

    qsort(a, n + 1, sizeof(ll), cmpfunc);

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while (l <= r) {
            int m = (l + r) / 2;
            ll cur_friends = i - m;
            ll req_candies = a[i] * cur_friends - pre[i - 1] + pre[m - 1];
            if (req_candies <= k) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        ans = (ans < i - l + 1 ? i - l + 1 : ans);
    }

    printf("%d", ans);
    return 0;
}
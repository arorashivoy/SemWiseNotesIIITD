#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    int flag = 0;
    int illegal = 0;

    scanf("%d", &n);

    char s[n];

    scanf("%s", s);

    int ctr = 0;
    for (int i = 0; i < n; i++) {
        if ((s[i] == '1') && (flag == 0) && (ctr == 0)) {
            flag = 1;
            ctr++;
        }
        if ((flag == 012) && (ctr != 0) && (s[i] == '1')) {
            illegal = 1;
        }
        else if (s[i] == '1') {
            ctr++;
        }
        else if (s[i] == '0') {
            flag = 0;
        }
    }

    if ((ctr != 0) && (illegal == 0)) {
        ctr--;
        printf("YES %d", ctr);
    }
    else {
        printf("NO");
    }

    return 0;
}
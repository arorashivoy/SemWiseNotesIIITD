#include <stdio.h>

int main() {
    char s[1000];
    char t[1000];
    int flag = 0;

    scanf("%s", s);
    scanf("%s", t);

    for (int i = 0; i < 1000; i++) {
        flag = 0;
        if (t[i] == '\0') {
            flag = 1;
            break;
        }
        if ((t[i] == 'a') || (t[i] == 'e') || (t[i] == 'i') || (t[i] == 'o') || (t[i] == 'u')) {
            printf("No");
            break;
        }

        for (int j = 0; j < 1000; j++) {
            if (s[j] == '\0') {
                break;
            }
            if (s[j] == t[i]) {
                flag = 1;
                break;
            }


        }

        if (flag == 0) {
            printf("No");
            break;
        }
    }

    if (flag == 1) {
        printf("Yes");
    }


    return 0;
}
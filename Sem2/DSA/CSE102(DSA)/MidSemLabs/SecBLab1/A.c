// 
// A.c
// By - Shivoy Arora
// 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


void merge(long int arr[], int li, int mi, int ri) {
    int n = mi - li + 1;
    int m = ri - mi;

    long int tmp1[n];
    long int tmp2[m];

    for (int i = 0; i < n; i++) {
        tmp1[i] = arr[li + i];
    }
    for (int i = 0; i < m; i++) {
        tmp2[i] = arr[mi + i + 1];
    }

    int i, j, k;
    i = j = 0;
    k = li;

    while (i < n && j < m) {
        if (tmp1[i] <= tmp2[j]) {
            arr[k] = tmp1[i];
            i++;
        }
        else {
            arr[k] = tmp2[j];
            j++;
        }
        k++;
    }

    while (i < n) {
        arr[k] = tmp1[i];
        i++;
        k++;
    }
    while (j < m) {
        arr[k] = tmp2[j];
        j++;
        k++;
    }
}

void mergeSort(long int arr[], int n, int li, int ri) {
    if (li < ri) {
        int mi = (li + ri) / 2;

        mergeSort(arr, n, li, mi);
        mergeSort(arr, n, mi + 1, ri);

        merge(arr, li, mi, ri);
    }
}


////////// Main Function //////////
int main() {
    int n;
    scanf("%d", &n);

    long long int sum = 0;
    long int marks[n];
    for (int i = 0; i < n; i++) {
        scanf("%ld", marks + i);
    }

    mergeSort(marks, n, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (marks[i] == (n - i - 1)) {
            printf("%ld\n", marks[i]);
            break;
        }
    }

    return 0;
}
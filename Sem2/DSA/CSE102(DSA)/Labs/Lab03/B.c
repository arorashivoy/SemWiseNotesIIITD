// 
// B.c
// The Poisoned knife
// By - Shivoy Arora
// 
#include <stdio.h>


int n;
long long int h;
long long int prevK;


/**
 * merge the splitted sublist while sorting them
 *
 * @param lst main list
 * @param li left index of the sublist
 * @param mi middle index of the sublist
 * @param ri right index of the sublist
 */
void merge(int lst[], int li, int mi, int ri) {
    // Creating temp arrays for the two subsets
    int n1 = (mi - li + 1);
    int n2 = (ri - mi);

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = lst[li + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = lst[mi + 1 + i];
    }

    // Merging the temp arrays back into lst
    int index = li;
    int j = 0, i = 0;

    while ((i < n1) && (j < n2)) {
        if (L[i] <= R[j]) {
            lst[index] = L[i];
            i++;
        }
        else {
            lst[index] = R[j];
            j++;
        }
        index++;
    }

    while (i < n1) {
        lst[index] = L[i];
        i++;
        index++;
    }

    while (j < n2) {
        lst[index] = R[j];
        j++;
        index++;
    }

}


/**
 * Split the list into two nearly equal parts
 *
 * @param lst main list
 * @param li left index of the sublist
 * @param ri right index of the sublist
 */
void mergeSort(int lst[], int li, int ri) {
    if (li < ri) {
        int mi = (li + ri) / 2;


        mergeSort(lst, li, mi);
        mergeSort(lst, mi + 1, ri);

        merge(lst, li, mi, ri);
    }
}


long long int checkDamage(int A[], long long int k, int n) {
    long long int damage = 0;
    for (int i = 0; i < n - 1; i++) {
        damage += (A[i + 1] - A[i]) > k ? k : (A[i + 1] - A[i]);
    }
    damage += k;

    return damage;
}


void calK(int A[], int lk, int rk, int n) {
    if (lk == rk) {
        //TODO: Check this answer
        return;
    }
    else {
        int mk = ((0.5) * (lk + rk) + 1);

        if (h == checkDamage(A, mk, n)) {
            prevK = mk;
            return;
        }
        else if (h < checkDamage(A, mk, n)) {
            prevK = mk;
            calK(A, lk, mk - 1, n);
        }
        else {
            calK(A, mk, rk, n);
        }

    }
}


////////// Main Function //////////
int main() {
    int q;
    scanf("%d", &q);

    // Test cases
    for (int test = 0; test < q; test++) {
        scanf("%d %lld", &n, &h);

        // Getting A[n]
        int A[n];
        for (int i = 0; i < n - 1; i++) {
            scanf("%d ", A + i);
        }
        scanf("%d", &A[n - 1]);

        mergeSort(A, 0, n - 1);

        calK(A, h / n, h, n);

        printf("%lld\n", prevK);

    }

    return 0;
}
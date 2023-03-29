// 
// A.c
// pr0hum and the weekend
// By - Shivoy Arora
// 
#include <stdio.h>


/**
 * Structure showing the follower and the following
 * @param a is the person who is a follower of b
 * @param b is the person who a is following
 */
struct follows {
    int a;
    int b;
};


/**
 * merge the splitted sublist while sorting them
 *
 * @param a main list
 * @param li left index of the sublist
 * @param mi middle index of the sublist
 * @param ri right index of the sublist
 */
void merge(struct follows a[], int li, int mi, int ri) {
    // Creating temp arrays for the two subsets
    int n1 = (mi - li + 1);
    int n2 = (ri - mi);

    struct follows L[n1];
    struct follows R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = a[li + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = a[mi + 1 + i];
    }

    // Merging the temp arrays back into a
    int index = li;
    int j = 0, i = 0;

    while ((i < n1) && (j < n2)) {
        if (L[i].a <= R[j].a) {
            a[index] = L[i];
            i++;
        }
        else {
            a[index] = R[j];
            j++;
        }
        index++;
    }

    while (i < n1) {
        a[index] = L[i];
        i++;
        index++;
    }

    while (j < n2) {
        a[index] = R[j];
        j++;
        index++;
    }

}


/**
 * Split the list into two nearly equal parts
 *
 * @param a main list
 * @param li left index of the sublist
 * @param ri right index of the sublist
 */
void mergeSort(struct follows a[], int li, int ri) {
    if (li < ri) {
        int mi = (li + ri) / 2;


        mergeSort(a, li, mi);
        mergeSort(a, mi + 1, ri);

        merge(a, li, mi, ri);
    }
}


////////// Main Function //////////
int main() {
    freopen("Helper/testA.txt", "r", stdin);
    freopen("Helper/ansA.txt", "w", stdout);


    int n, m;
    int currNum = 1;
    scanf("%d %d", &n, &m);

    // Getting the entries
    struct follows entries[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &entries[i].a, &entries[i].b);
    }

    // Sorting the entries
    mergeSort(entries, 0, m - 1);

    // Printing the followings
    int i = 0;
    while (i < m) {
        if (currNum != entries[i].a) {
            printf("-1\n");
            currNum += 1;
            continue;
        }
        while (entries[i].a == entries[i + 1].a) {
            printf("%d ", entries[i].b);

            i += 1;
        }
        currNum += 1;
        printf("%d\n", entries[i].b);
        i += 1;
    }

    while (currNum <= n) {
        currNum += 1;
        printf("-1\n");
    }


    return 0;
}
// 
// B.c
// Birthday Dilemma
// By - Shivoy Arora
// 
#include <stdio.h>

/**
 * To print a list
 *
 * @param arr the list which has to be printed
 * @param size the length of the array
 */
void printl(long int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");
}

/**
 * To swap the values at positions left and right index of arr
 *
 * @param arr The list whose values are to be swapped
 * @param left The left index to be swapped
 * @param right The right index to be swapped
 */
void swap(long int arr[], int left, int right) {
    long int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}


/**
 * To partition the list by fixing index of one element
 *
 * @param arr The list which is supposed to be partitioned
 * @param lo The lower index of the list
 * @param hi The higher index of the list
 */
int partition(long int arr[], int lo, int hi) {
    int pivot = arr[lo];
    int left = lo;
    int right = hi;
    while (left < right) {
        while (left <= right && arr[left] <= pivot) {
            left += 1;
        }
        while (right >= left && arr[right] > pivot) {
            right -= 1;
        }
        if (left < right) {
            swap(arr, left, right);
        }
    }
    swap(arr, lo, right);
    return right;
}


/**
 * QuickSorting Algorithm
 *
 * @param arr The list which is supposed to be sorted
 * @param lo The lower index of the list
 * @param hi The higher index of the list
 */
void quicksort(long int arr[], int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int p = partition(arr, lo, hi);
    quicksort(arr, lo, p - 1);
    quicksort(arr, p + 1, hi);
}


////////// Main Function //////////
int main() {
    int n;
    long int k;
    int maxFriends = 1;
    long long int sum = 0;
    long long int tempSum = 0;

    scanf("%d %ld", &n, &k);

    // Inputting the list
    long int a[n];
    for (int i = 0; i < (n - 1); i++) {
        scanf("%ld ", a + i);
    }
    scanf("%ld", a + (n - 1));

    // Sorting the list
    quicksort(a, 0, n - 1);

    // Creating a list of difference between the elements
    long int diff[n - 1];
    for (int i = 0; i < n - 1; i++) {
        diff[i] = a[i + 1] - a[i];
        sum += (i + 1) * diff[i];
    }


    // Sliding Window
    //
    // Setting starting index
    for (int i = 0; i < (n - 1); i++) {
        tempSum = sum;

        // Window size
        for (int j = (n - 2); j >= i; j--) {

            if ((j - i + 2) <= maxFriends) break;
            if (k >= tempSum) {
                maxFriends = j - i + 2;
                break;
            }

            tempSum -= (j - i + 1) * diff[j];
        }

        // Subtracting from sum
        for (int j = i; j < n - 1; j++) {
            sum -= diff[j];
        }
    }

    printf("%d", maxFriends);

    return 0;
}
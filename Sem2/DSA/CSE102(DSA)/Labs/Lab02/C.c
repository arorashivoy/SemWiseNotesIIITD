// 
// C.c
// The death sentence
// By - Shivoy Arora
// 
#include <stdio.h>
#include <stdlib.h>


/**
 * To exchange the values at positions left and right index of arr
 *
 * @param arr The list whose values are to be swapped
 * @param left The left index to be swapped
 * @param right The right index to be swapped
 * @param indexes The list of indexes of the elements according to the index in the given list
 */
void exchange(long int arr[], int left, int right, int indexes[]) {
    long int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;

    int temp2 = indexes[right];
    indexes[right] = indexes[left];
    indexes[left] = temp2;
}


/**
 * To partition the list by fixing index of one element
 *
 * @param arr The list which is supposed to be partitioned
 * @param lo The lower index of the list
 * @param hi The higher index of the list
 * @param indexes The list of indexes of the elements according to the index in the given list
 */
int partition(long int arr[], int lo, int hi, int indexes[]) {
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
            exchange(arr, left, right, indexes);
        }
    }
    exchange(arr, lo, right, indexes);
    return right;
}


/**
 * QuickSorting Algorithm
 *
 * @param arr The list which is supposed to be sorted
 * @param lo The lower index of the list
 * @param hi The higher index of the list
 * @param indexes The list of indexes of the elements according to the index in the given list
 */
void quicksort(long int arr[], int lo, int hi, int indexes[]) {
    if (lo >= hi) {
        return;
    }
    int p = partition(arr, lo, hi, indexes);
    quicksort(arr, lo, p - 1, indexes);
    quicksort(arr, p + 1, hi, indexes);
}

int main() {
    int t;
    int n;
    int steps, ctr;
    int tempStep;
    long int largest;
    long int subtracted;

    scanf("%d", &t);
    for (int numTest = 0; numTest < t; numTest++) {
        scanf("%d", &n);

        // setting the length of the arrays
        long int A[n];
        int indexes[n];

        // initializing indexes list
        for (int i = 0; i < n; i++) {
            indexes[i] = i;
        }
        // inputting list A
        for (int i = 0; i < n; i++) {
            scanf("%ld ", &A[i]);
        }

        // Sorting the list
        quicksort(A, 0, n - 1, indexes);

        ctr = 0;
        steps = 0;
        subtracted = 0;
        largest = A[n - 1];
        while (largest >= 0) {

            // Getting the lowest index if there are multiple instances of the index
            tempStep = steps;
            while (A[tempStep] == A[tempStep + 1]) {
                if (indexes[steps] > indexes[tempStep + 1]) {
                    steps = tempStep + 1;
                }
                if (tempStep < (n - 1)) {
                    tempStep += 1;
                }
                else {
                    break;
                }
            }
            indexes[tempStep] = indexes[steps];
            steps = tempStep;

            // subtracting from the largest number
            if (subtracted <= A[steps]) {
                ctr += ((A[steps] - subtracted) / (indexes[steps] + 1)) + 1;
                largest -= (((A[steps] - subtracted) / (indexes[steps] + 1)) + 1) * (indexes[steps] + 1);
                subtracted += (((A[steps] - subtracted) / (indexes[steps] + 1)) + 1) * (indexes[steps] + 1);
            }
            else {
                steps += 1;
            }
        }

        printf("%d\n", ctr);
    }
}

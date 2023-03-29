// 
// C.c
// Smooth, Smoother, Smoothest
// By - Shivoy Arora
// 
#include <stdio.h>


int stepsIndex = 0;

/**
 * The the sub-array smooth
 *
 * @param arr original array
 * @param li left index of the sub-array
 * @param ri right index of the sub-array
 * @param k k-smooth value
 * @param step steps taken till now
 * @param steps list of steps taken
 */
void makeSmooth(long int arr[], int li, int ri, long int k, int step, int steps[]) {
    // printf("Steps: %d li: %d ri: %d k: %ld\n", step, li, ri, k);
    if (li == ri) {
        if (arr[li] == k) {
            steps[stepsIndex] = step;
        }
        else {
            steps[stepsIndex] = step + 1;
        }
        stepsIndex += 1;
        return;
    }

    int mid = (ri + li) / 2;

    // Finding steps to convert half of the array = k
    int tempStep1 = 0;
    int tempStep2 = 0;

    for (int i = li; i <= mid; i++) {
        if (arr[i] != k) {
            tempStep1 += 1;
        }
    }
    for (int i = mid + 1; i <= ri; i++) {
        if (arr[i] != k) {
            tempStep2 += 1;
        }
    }

    makeSmooth(arr, mid + 1, ri, k + 1, step + tempStep1, steps);
    makeSmooth(arr, li, mid, k + 1, step + tempStep2, steps);
}


////////// Main Function //////////
int main() {
    int n;
    long int k;
    scanf("%d %ld", &n, &k);

    // Inputting A
    long int A[n];
    scanf("%ld", &A[0]);
    for (int i = 1; i < n; i++) {
        scanf(" %ld", A + i);
    }

    int steps[n];
    makeSmooth(A, 0, n - 1, k, 0, steps);

    int minSteps = steps[0];
    for (int i = 0; i < stepsIndex; i++) {
        if (steps[i] < minSteps) {
            minSteps = steps[i];
        }
    }

    printf("%d", minSteps);

    return 0;
}
// Lab00 Q2

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int N;
int* happiness;
int happIndex = 0;

void printl(int arr[], int size) {
    /*
    To print a array
    arr: array of the type int
    size: number of elements in the array
    */

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int max(int arr[], int size) {
    int maxEle = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] > maxEle) {
            maxEle = arr[i];
        }
    }

    return maxEle;
}

void calHappiness(int n, char currChoice, int currHappiness, int a[], int b[], int c[]) {
    /*
    Calculate the current happiness of the choice taken
    If all the choices are exhausted then happiness is added to the list

    Args:
        n: current index of the day
        currChoice: the choice of activity for that day
        currHappiness: the happiness up-until that day
        a: list of happiness of activity a for each day
        b: list of happiness of activity b for each day
        c: list of happiness of activity c for each day
    */

    // Base Case
    if (n == (N - 1)) {
        if (currChoice == 'a') {

            currHappiness += a[n];
        }
        else if (currChoice == 'b') {
            currHappiness += b[n];
        }
        else {
            currHappiness += c[n];
        }

        // Adding the happiness to the list
        happiness[happIndex] = currHappiness;
        happIndex++;
    }

    // Recursion case
    else {
        if (currChoice == 'a') {
            currHappiness += a[n];
            calHappiness(n + 1, 'b', currHappiness, a, b, c);
            calHappiness(n + 1, 'c', currHappiness, a, b, c);
        }
        else if (currChoice == 'b') {
            currHappiness += b[n];
            calHappiness(n + 1, 'a', currHappiness, a, b, c);
            calHappiness(n + 1, 'c', currHappiness, a, b, c);
        }
        else {
            currHappiness += c[n];
            calHappiness(n + 1, 'a', currHappiness, a, b, c);
            calHappiness(n + 1, 'b', currHappiness, a, b, c);
        }
    }
}

int main() {
    scanf("%d", &N);

    // Getting the happiness values
    int a[N], b[N], c[N];

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", a + i, b + i, c + i);
    }

    int size = (int)(3 * pow(2, (N - 1)));

    // setting the list size
    happiness = (int*)malloc(size * sizeof(int));

    // calling the recursive function
    calHappiness(0, 'a', 0, a, b, c);
    calHappiness(0, 'b', 0, a, b, c);
    calHappiness(0, 'c', 0, a, b, c);

    printf("%d", max(happiness, size));


    return 0;
}

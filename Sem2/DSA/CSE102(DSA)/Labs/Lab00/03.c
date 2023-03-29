#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int n, m, x, y;
int pathIndex = 0;

long int numPaths = 100;   // Total number of paths possible
int pathLen = 0;    // Length of the array path


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


void movePerson(int cx, int cy, int r, int d, char dir, int stepsTaken, int pathLen, int path[], int paths[numPaths][pathLen], int grid[n][m]) {

    // Moveing the person to the next block
    if (dir == 'd') {
        cx++;
        d--;
    }
    else if (dir == 'r') {
        cy++;
        r--;
    }

    // Adding the persons current position to the path list
    path[2 * stepsTaken] = cx;
    path[(2 * stepsTaken) + 1] = cy;
    stepsTaken++;

    // Calling the recursive function
    if (d > 0) {
        if (grid[cx][cy - 1] == 1) {
            movePerson(cx, cy, r, d, 'd', stepsTaken, pathLen, path, paths, grid);
        }
    }
    if (r > 0) {
        if (grid[cx - 1][cy] == 1) {
            movePerson(cx, cy, r, d, 'r', stepsTaken, pathLen, path, paths, grid);
        }
    }

    // Base case
    if ((r == 0) && (d == 0)) {
        for (int i = 0; i < pathLen; i++) {
            paths[pathIndex][i] = path[i];
        }
        pathIndex++;
    }
}

int main() {
    // Inputting the data
    scanf("%d %d %d %d", &n, &m, &x, &y);

    int grid[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m;j++) {
            scanf("%d", &grid[i][j]);
        }
    }


    int r = (m - 1);    // Number of right move required to reach home
    int d = (n - 1);    // Number of down move required to reach home

    // // Finding number of paths
    // int ctr = (r + d);
    // long int num = 1;
    // long int den = 1;


    // for (int i = 0; i < r; i++) {
    //     num *= ctr;
    //     ctr--;
    // }

    // ctr = r;
    // for (int i = 0; i < r; i++) {
    //     den *= ctr;
    //     ctr--;
    // }

    // numPaths = num / den;

    // if (numPaths > 100) {
    //     numPaths = 100;
    // }

    // Creating paths array
    pathLen = 2 * (r + d + 1);          // Length of the array path
    int path[pathLen];                  // Current path: Even index = x coordinate, Odd index = y coordinate
    int candyPaths[numPaths][pathLen];  // Array of all the paths to the candy shop
    int paths[numPaths][pathLen];       // Array of all the paths to home

    path[0] = 1;
    path[1] = 1;

    // Setting the values to zero of the array
    for (int i = 2; i < pathLen; i++) {
        path[i] = 0;
    }


    for (int i = 0; i < numPaths; i++) {
        for (int j = 0; j < pathLen; j++) {
            candyPaths[i][j] = 0;
        }
    }

    for (int i = 0; i < numPaths; i++) {
        for (int j = 0; j < pathLen; j++) {
            paths[i][j] = 0;
        }
    }


    // Finding the path to the candy shop
    int cx = 1;     // Current x coordinate of the person
    int cy = 1;     // Current y coordinate of the person

    int rc = (y - 1);   // Number of right move required to reach candy shop
    int dc = (x - 1);   // Number of down move required to reach candy shop

    int stepsTaken = 0;

    // Calling the recursive function
    if (dc > 0) {
        if (grid[cx][cy - 1] == 1) {
            movePerson(cx, cy, rc, dc, 'd', stepsTaken, pathLen, path, candyPaths, grid);
        }
    }
    if (rc > 0) {
        if (grid[cx - 1][cy] == 1) {
            movePerson(cx, cy, rc, dc, 'r', stepsTaken, pathLen, path, candyPaths, grid);
        }
    }


    // Finding the path to the home from candy shop
    stepsTaken = rc + dc;
    d = d - dc;
    r = r - rc;

    pathIndex = 0;

    if ((d == 0) && (r == 0)) {
        for (int i = 0; i < numPaths; i++) {
            for (int j = 0; j < pathLen; j++) {
                paths[i][j] = candyPaths[i][j];
            }
        }
    }


    for (int i = 0; i < numPaths; i++) {
        // If no more unique paths are available
        if (candyPaths[i][0] == 0) {
            break;
        }

        // Calling the recursive function again
        if (d > 0) {
            if (grid[x][y - 1] == 1) {
                movePerson(x, y, r, d, 'd', stepsTaken, pathLen, candyPaths[i], paths, grid);
            }
        }
        if (r > 0) {
            if (grid[x - 1][y] == 1) {
                movePerson(x, y, r, d, 'r', stepsTaken, pathLen, candyPaths[i], paths, grid);
            }
        }
    }


    // Checking the number of unique paths
    int ctr = 0;
    for (int i = 0; i < numPaths; i++) {
        if (paths[i][0] == 0) {
            break;
        }
        else {
            ctr++;
        }
    }

    printf("%d", ctr);

    return 0;
}
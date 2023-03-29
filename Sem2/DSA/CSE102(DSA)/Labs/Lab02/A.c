//
// A.c
// BKR moves
// By - Shivoy Arora
//

#include <stdio.h>

char board[8][8];
int moves;

int bishopIndex = 0;
int knightIndex = 0;
int rookIndex = 0;


/**
 * To move the bishop one block at a time
 *
 * @param x current x-coordinate of bishop
 * @param y current y-coordinate of bishop
 * @param steps steps already taken by the bishop
 * @param dir direction in which the bishop is moving
 * @param bishop the positions bishop has already reached
 */
void moveBishop(int x, int y, int steps, int dir, int bishop[]) {

    if ((x < 8) && (x >= 0) && (y < 8) && (y >= 0)) {
        if (board[x][y] == '.') {
            // Checking if already counted
            for (int i = 0; i < bishopIndex; i++) {
                if ((x == bishop[3 * i]) && (y == bishop[3 * i + 1])) {
                    if (steps < bishop[3 * i + 2]) {
                        bishop[3 * i + 2] = steps;
                        goto skipAddBishop;
                    }
                    else return;
                }
            }

            // Adding reached position
            bishop[3 * bishopIndex] = x;
            bishop[(3 * bishopIndex) + 1] = y;
            bishop[(3 * bishopIndex) + 2] = steps;

            bishopIndex += 1;

            // Next step
        skipAddBishop:
            if (dir == 1) {
                moveBishop(x + 1, y - 1, steps, 1, bishop);
            }
            else if (steps < moves) {
                moveBishop(x + 1, y - 1, steps + 1, 1, bishop);
            }

            if (dir == 2) {
                moveBishop(x + 1, y + 1, steps, 2, bishop);
            }
            else if (steps < moves) {
                moveBishop(x + 1, y + 1, steps + 1, 2, bishop);
            }

            if (dir == 3) {
                moveBishop(x - 1, y + 1, steps, 3, bishop);
            }
            else if (steps < moves) {
                moveBishop(x - 1, y + 1, steps + 1, 3, bishop);
            }

            if (dir == 4) {
                moveBishop(x - 1, y - 1, steps, 4, bishop);
            }
            else if (steps < moves) {
                moveBishop(x - 1, y - 1, steps + 1, 4, bishop);
            }
        }
    }
}


/**
 * To move the knight one block at a time
 *
 * @param x current x-coordinate of knight
 * @param y current y-coordinate of knight
 * @param steps steps already taken by the knight
 * @param knight the positions knight has already reached
 */
void moveKnight(int x, int y, int steps, int knight[]) {
    if ((x < 8) && (x >= 0) && (y < 8) && (y >= 0)) {
        if (board[x][y] == '.') {
            // Checking if already counted
            for (int i = 0; i < knightIndex; i++) {
                if ((x == knight[3 * i]) && (y == knight[3 * i + 1])) {
                    if (steps < knight[3 * i + 2]) {
                        knight[3 * i + 2] = steps;
                        goto skipAddKnight;
                    }
                    else return;
                }
            }

            // Adding reached position
            knight[3 * knightIndex] = x;
            knight[3 * knightIndex + 1] = y;
            knight[3 * knightIndex + 2] = steps;

            knightIndex += 1;

        skipAddKnight:
            // Calling the recursive function again
            if (steps < moves) {
                moveKnight(x + 1, y - 2, steps + 1, knight);
                moveKnight(x - 1, y - 2, steps + 1, knight);
                moveKnight(x + 2, y - 1, steps + 1, knight);
                moveKnight(x + 2, y + 1, steps + 1, knight);
                moveKnight(x + 1, y + 2, steps + 1, knight);
                moveKnight(x - 1, y + 2, steps + 1, knight);
                moveKnight(x - 2, y + 1, steps + 1, knight);
                moveKnight(x - 2, y - 1, steps + 1, knight);
            }
        }
    }
}

/**
 * To move the rook one block at a time
 *
 * @param x current x-coordinate of rook
 * @param y current y-coordinate of rook
 * @param steps steps already taken by the rook
 * @param dir direction in which the rook is moving
 * @param rook the positions rook has already reached
 */
void moveRook(int x, int y, int steps, int dir, int rook[]) {

    if ((x < 8) && (x >= 0) && (y < 8) && (y >= 0)) {
        if (board[x][y] == '.') {
            // Checking if already counted
            for (int i = 0; i < rookIndex; i++) {
                if ((x == rook[3 * i]) && (y == rook[3 * i + 1])) {
                    if (steps < rook[3 * i + 2]) {
                        rook[3 * i + 2] = steps;
                        goto skipAddRook;
                    }
                    else return;
                }
            }

            // Adding reached position
            rook[3 * rookIndex] = x;
            rook[(3 * rookIndex) + 1] = y;
            rook[(3 * rookIndex) + 2] = steps;

            rookIndex += 1;

            // Next step
        skipAddRook:
            if (dir == 1) {
                moveRook(x + 1, y, steps, 1, rook);
            }
            else if (steps < moves) {
                moveRook(x + 1, y, steps + 1, 1, rook);
            }

            if (dir == 2) {
                moveRook(x, y + 1, steps, 2, rook);
            }
            else if (steps < moves) {
                moveRook(x, y + 1, steps + 1, 2, rook);
            }

            if (dir == 3) {
                moveRook(x - 1, y, steps, 3, rook);
            }
            else if (steps < moves) {
                moveRook(x - 1, y, steps + 1, 3, rook);
            }

            if (dir == 4) {
                moveRook(x, y - 1, steps, 4, rook);
            }
            else if (steps < moves) {
                moveRook(x, y - 1, steps + 1, 4, rook);
            }
        }
    }
}

//////// Main Function ////////
int main() {

    int initB[2], initK[2], initR[2];

    // Taking input of board
    for (int i = 0; i < 8; i++) {
        scanf("%c%c%c%c%c%c%c%c\n", &board[i][0], &board[i][1], &board[i][2], &board[i][3], &board[i][4], &board[i][5], &board[i][6], &board[i][7]);
    }

    // Getting initial position of the pieces
    scanf("%d %d", initB + 0, initB + 1);
    scanf("%d %d", initK + 0, initK + 1);
    scanf("%d %d", initR + 0, initR + 1);
    scanf("%d", &moves);

    // For bishop
    int bishop[500];
    moveBishop(initB[0] - 1, initB[1] - 1, 0, 0, bishop);

    // For knight
    int knight[500];
    moveKnight(initK[0] - 1, initK[1] - 1, 0, knight);

    // For rook
    int rook[500];
    moveRook(initR[0] - 1, initR[1] - 1, 0, 0, rook);

    printf("%d %d %d", bishopIndex, knightIndex, rookIndex);

    return 0;
}
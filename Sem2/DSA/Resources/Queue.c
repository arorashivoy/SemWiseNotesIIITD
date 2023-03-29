// 
// Queue.c
// By - Shivoy Arora
// 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct queue {
    int head;
    int tail;
    int size;
    int* arr;
} queue;


/**
 * @brief Create a new Queue
 *
 * @param size size of the queue
 * @return queue*
 */
queue* initializeQueue(int size) {
    queue* Q = (queue*)malloc(sizeof(queue));
    Q->arr = (int*)malloc(size * sizeof(int));

    Q->head = Q->tail = 0;
    Q->size = size;
    return Q;
}


/**
 * @brief Check if the queue is empty
 *
 * @param q queue
 * @return 1 if empty, else 0
 */
int isEmpty(queue* q) {
    if (q->head == q->tail)
        return 1;
    return 0;
}


/**
 * @brief See if the queue is full
 *
 * @param q queue
 * @return 1 if full, else 0
 */
int isFull(queue* q) {
    if (((q->tail + 1) % q->size) == q->head)
        return 1;
    return 0;
}


/**
 * @brief Add an item to the queue
 *
 * @param q queue
 * @param val value to be added
 */
void enqueue(queue* q, int val) {
    if (queueFull(q)) {
        printf("Queue overflow\n");
        return;
    }
    q->arr[q->tail] = val;
    q->tail += 1;
    q->tail %= q->size;
}


/**
 * @brief Remove an item from the queue
 *
 * @param Q queue
 * @return 0 if underflow else, removed item
 */
int dequeue(struct queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int ret = Q->arr[Q->head];
    Q->head += 1;
    Q->head %= Q->size;
    return ret;
}


////////// Main Function //////////
int main() {


    return 0;
}
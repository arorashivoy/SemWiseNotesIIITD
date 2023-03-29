// 
// 
// By - Shivoy Arora
// 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* prev;
    struct node* next;
};

struct node* allocateNode(int val) {
    struct node* n = (struct node*)malloc(sizeof(struct node));

    n->val = val;
    n->prev = n;
    n->next = n;

    return n;
}

void insertNode(struct node** head, struct node* n) {
    struct node* tmp = *head;

    if (tmp == NULL) {
        *head = n;

        (*head)->next = *head;
        (*head)->prev = *head;

        return;
    }

    while (tmp->next != *head) {
        tmp = tmp->next;
    }

    tmp->next = n;
    n->prev = tmp;
    n->next = *head;
}

/**
 * Deleting the next node of the head
 *
 * @param head head of the linked list
 *
 * @returns removed node
 */
struct node* deleteNode(struct node* head) {
    struct node* tmp = head;

    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;

    return tmp->next;
}


////////// Main Function //////////
int main() {
    int n, k, t;
    scanf("%d %d %d", &n, &k, &t);

    // creating the initial linked list
    int val;
    scanf("%d", &val);
    struct node* head = allocateNode(val);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &val);
        struct node* n = allocateNode(val);

        insertNode(&head, n);
    }

    printf("Make initial list\n");
    printf("%d %d %d", n, k, t);
    struct node* winner = NULL;
    struct node* newHead = NULL;
    struct node* rem = NULL;
    int reverse = 0;
    // make code to reverse the counting
    for (int j = 0; j < t; t++) {
        printf("hi");
        while (head->next != head) {
            // original order
            for (int i = 0; i < k - 1; i++) {
                printf("1 ");
                head = head->next;
            }
            rem = deleteNode(head);
            insertNode(&newHead, rem);

            // breaking if only one member is left
            if (head->next == head) {
                break;
            }

            printf("initial order");
            // reverse order
            head = head->prev;

            for (int i = 0; i < k + 1; i++) {
                head = head->prev;
            }
            rem = deleteNode(head);
            insertNode(&newHead, rem);

            head = head->next;

            printf("reverse order");

        }
        winner = head;

        head = newHead;
        newHead = NULL;
    }

    printf("%d", winner->val);
    return 0;
}
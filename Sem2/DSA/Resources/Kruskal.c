// 
// Kruskal.c
// By - Shivoy Arora
// 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


/////////// Structures ///////////
typedef struct set {
    int vertex;
    struct set* parent;
    int count;
} set;

typedef struct edge {
    set* u;
    set* v;
    int w;
} edge;

typedef struct edgeList {
    edge* data;
    int n;
} edgeList;


////////////////////// Merge Sort //////////////////////
void merge(edge arr[], int lo, int mid, int hi) {
    int i, j, k;

    int n1 = mid - lo + 1;
    int n2 = hi - mid;

    // Creating temp arrays
    edge tmp1[n1];
    edge tmp2[n2];

    for (i = 0; i < n1; i++) {
        tmp1[i] = arr[lo + i];
    }
    for (j = 0; j < n2; j++) {
        tmp2[j] = arr[mid + 1 + j];
    }

    // Comparing and adding
    i = j = 0;
    k = lo;
    while (i < n1 && j < n2) {
        if (tmp1[i].w <= tmp2[j].w) {
            arr[k] = tmp1[i];
            i += 1;
        }
        else {
            arr[k] = tmp2[j];
            j += 1;
        }
        k += 1;
    }

    // Adding the left over elements
    while (i < n1) {
        arr[k] = tmp1[i];
        i += 1;
        k += 1;
    }
    while (j < n2) {
        arr[k] = tmp2[j];
        j += 1;
        k += 1;
    }
}

void mergeSort(edgeList* E, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int mid = (lo + hi) / 2;
    // recursively sort the first half
    mergeSort(E, lo, mid);
    // recursively sort the second half
    mergeSort(E, mid + 1, hi);
    // merge the sorted arrays
    merge(E->data, lo, mid, hi);
}


////////////////////// Sets //////////////////////
/**
 * @brief Convert a vertex to a set
 *
 * @param u value of the vertex
 * @return set of the vertex
 */
set* makeSet(int u) {
    set* X = (set*)malloc(sizeof(set));
    X->vertex = u;
    X->parent = NULL;
    X->count = 1;

    return X;
}

/**
 * Take union of two sets
 * It sets one of the set as the parent of the other to show that it is in the same set
 *
 * @param u first set
 * @param v second set
 */
void Union(set* u, set* v) {
    if (u->count < v->count) {
        u->parent = v;
        v->count += u->count;
    }
    else {
        v->parent = u;
        u->count += v->count;
    }
}

/**
 * @brief Find the topmost parent of the set
 *
 * @param u set to find the parent
 * @return parent set
 */
set* find(set* u) {
    set* tmp = u;
    while (tmp->parent != NULL) {
        tmp = tmp->parent;
    }
    return tmp;
}

/////// New Function (Not in the notes) ///////
/**
 * @brief If the set of the vertex is already created then return it else create a new one
 *
 * @param u value of the node
 * @param createdSet array storing all the created sets
 * @param n number of nodes available
 * @return set with the value u, if already created then the pointer of that else create a new one
 */
set* returnSet(int u, set* createdSet[], int n) {
    int j = 0;

    for (j = 0; j < n && createdSet[j]->vertex != -1; j++) {
        if (createdSet[j]->vertex == u) {
            return createdSet[j];
        }
    }

    set* _u = makeSet(u);
    createdSet[j] = _u;

    return _u;
}


////////////////////// Kruskal's Algorithm //////////////////////
/**
 * @brief Kruskal's algorithm to find the minimum spanning tree
 *
 * @param E edgeList
 */
edgeList* kruskal(edgeList* E) {
    edgeList* T = (edgeList*)malloc(sizeof(edgeList));
    T->data = (edge*)malloc(sizeof(edge) * E->n);
    T->n = 0;

    mergeSort(E, 0, E->n - 1);
    for (int i = 0; i < E->n; i++) {
        set* a = find(E->data[i].u);
        set* b = find(E->data[i].v);
        if (a != b) {
            T->data[T->n] = E->data[i];
            T->n += 1;
            Union(a, b);
        }
    }

    return T;
}

void printEdges(edgeList* T) {
    for (int i = 0; i < T->n; i++) {
        printf("%d %d %d\n", T->data[i].u->vertex, T->data[i].v->vertex, T->data[i].w);
    }
}


////////////////////////////// Main Function //////////////////////////////
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Creating a list of all sets
    set* emptySet = (set*)malloc(sizeof(set));
    emptySet->vertex = -1;
    emptySet->parent = NULL;
    emptySet->count = 0;

    set* createdSets[n];
    for (int i = 0; i < n; i++) {
        createdSets[i] = emptySet;
    }

    edgeList* E = (edgeList*)malloc(sizeof(edgeList));
    E->n = m;
    E->data = (edge*)malloc(sizeof(edge) * m);
    int edgeIndex = 0;

    int _u, _v, _w;
    set* u, * v;
    edge _e;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &_u, &_v, &_w);
        u = returnSet(_u, createdSets, n);
        v = returnSet(_v, createdSets, n);

        _e.u = u;
        _e.v = v;
        _e.w = _w;

        E->data[edgeIndex] = _e;
        edgeIndex += 1;

    }

    edgeList* T = kruskal(E);

    printf("\n\n");
    printEdges(T);

    return 0;
}
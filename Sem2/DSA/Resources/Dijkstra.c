// 
// Dijkstra.c
// By - Shivoy Arora
// 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define INFTY 99999

////////// Structures //////////
typedef struct Vertex {
    int val;
    int distance;
    struct node* edges;
} Vertex;

typedef struct node {
    struct Vertex* vertex;
    int weight;
    struct node* next;
}node;

typedef struct Graph {
    int numVertex;
    Vertex** adjLists;
    int* sptSet;
    int* otherSet;
} Graph;

typedef struct Heap {
    Vertex** arr;
    int heapLen;    // number of elements in heap
    int arrLen;     // number of elements in arr
    int size;       // size of arr
} Heap;


////////// Vertex //////////
Vertex* createVertex(int val) {
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));
    v->val = val;
    v->edges = NULL;
    v->distance = INFTY;

    return v;
}


////////// Linked List //////////
node* createNode(Vertex* val, int weight) {
    node* n = (node*)malloc(sizeof(node));
    n->vertex = val;
    n->weight = weight;
    n->next = NULL;

    return n;
}


////////// Min Heap //////////
void swap(Vertex** a, Vertex** b) {
    Vertex* tmp = *a;
    *a = *b;
    *b = tmp;
}

Heap* createMinHeap(int size) {
    Heap* H = (Heap*)malloc(sizeof(Heap));

    H->arr = (Vertex**)malloc(sizeof(Vertex*) * (size + 1));
    H->heapLen = 0;
    H->arrLen = 0;
    H->size = size;

    return H;
}

void heapifyAt(Vertex* arr[], int n, int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;

    if (left <= n && arr[smallest]->distance > arr[left]->distance) {
        smallest = left;
    }
    if (right <= n && arr[smallest]->distance > arr[right]->distance) {
        smallest = right;
    }
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapifyAt(arr, n, smallest);
    }
}

void minHeapify(Heap* H, int i) {
    heapifyAt(H->arr, H->heapLen, i);
}

Vertex* extractMinHeap(struct Heap* H) {
    // If the heap is empty
    if (H->heapLen == 0) {
        return NULL;
    }

    // Extracting the min element from the heap
    Vertex* tmp = H->arr[1];

    H->arr[1] = H->arr[H->heapLen];
    H->arr[H->heapLen] = tmp;
    H->heapLen -= 1;
    H->arrLen -= 1;

    minHeapify(H, 1);

    return tmp;
}

void insertAt(Vertex* arr[], int idx) {
    if (idx == 1) {
        return;
    }
    int parent = idx / 2;
    if (arr[parent]->distance > arr[idx]->distance) {
        swap(&arr[parent], &arr[idx]);
        insertAt(arr, parent);
    }
}

void insert(struct Heap* H, Vertex* val) {
    int n = H->heapLen;

    // assuming enough space in the array

    H->arr[n + 1] = val;
    insertAt(H->arr, n + 1);
    H->heapLen += 1;
    H->arrLen += 1;
}

////////// Graph //////////
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertex = vertices;
    graph->adjLists = (Vertex**)malloc(vertices * sizeof(Vertex*));
    graph->sptSet = (int*)malloc(vertices * sizeof(int));
    graph->otherSet = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = createVertex(i);
        graph->sptSet[i] = 0;
        graph->otherSet[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    // Add edge from src to dest
    node* newNode = createNode(graph->adjLists[dest], weight);
    newNode->next = graph->adjLists[src]->edges;
    graph->adjLists[src]->edges = newNode;

    // Add edge from dest to src
    newNode = createNode(graph->adjLists[src], weight);
    newNode->next = graph->adjLists[dest]->edges;
    graph->adjLists[dest]->edges = newNode;
}


////////// Dijkstra //////////
/**
 * @brief Insert all the edges from vertex to the heap
 *
 * @param vertex a vertex of the graph
 * @param graph the given graph
 * @param edgeList min heap of all the edges
 */
void insertEdge(Vertex* vertex, Graph* graph, Heap* otherSet) {
    node* head = vertex->edges;
    while (head != NULL) {
        if (graph->sptSet[head->vertex->val] == 0) {
            // If not in otherSet
            if (graph->otherSet[head->vertex->val] == 0) {
                graph->otherSet[head->vertex->val] = 1;
                head->vertex->distance = vertex->distance + head->weight;
                insert(otherSet, head->vertex);
            }
            // If already present the otherSet heap
            else {
                if (head->vertex->distance > (vertex->distance + head->weight)) {
                    /** @todo check this for errors */
                    int i;
                    for (i = 1; i < otherSet->heapLen + 1; i++) {
                        if (otherSet->arr[i] == vertex)     break;
                    }
                    head->vertex->distance = vertex->distance + head->weight;

                    insertAt(otherSet->arr, i);
                }
            }
        }

        head = head->next;
    }
}


void dijkstra(Graph* graph) {
    Heap* otherSet = createMinHeap(graph->numVertex);

    // Setting the distance of the initial vertex
    graph->adjLists[0]->distance = 0;

    Vertex* _vertex = graph->adjLists[0];
    while (_vertex != NULL) {
        graph->otherSet[_vertex->val] = 0;
        graph->sptSet[_vertex->val] = 1;
        insertEdge(_vertex, graph, otherSet);

        _vertex = extractMinHeap(otherSet);
    }

    free(otherSet);
}

void printDist(Graph* g) {
    for (int i = 0; i < g->numVertex; i++) {
        printf("Vertex: %d;\tDistance: %d\n", i, g->adjLists[i]->distance);
    }
}


////////// Main Function //////////
int main() {
    int n;      // Number of nodes
    int m;      // Number of edges

    scanf("%d %d", &n, &m);

    // Creating the graph
    Graph* graph = createGraph(n);

    // Adding the edges
    int _u, _v, _w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &_u, &_v, &_w);
        addEdge(graph, _u, _v, _w);
    }

    dijkstra(graph);

    printf("\n");
    printDist(graph);


    return 0;
}
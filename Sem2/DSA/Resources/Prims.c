// 
// Prims.c
// By - Shivoy Arora
// 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

////////// Structures //////////
typedef struct node {
    int vertex;
    int weight;
    struct node* next;
}node;

typedef struct Graph {
    int numVertex;
    node** adjLists;
    int* visited;
} Graph;

typedef struct edge {
    int u;
    int v;
    int weight;
}edge;

typedef struct Heap {
    edge* arr;
    int heapLen;    // number of elements in heap
    int arrLen;     // number of elements in arr
    int size;       // size of arr
} Heap;

////////// Linked List //////////
node* createNode(int val, int weight) {
    node* n = (node*)malloc(sizeof(node));
    n->vertex = val;
    n->weight = weight;
    n->next = NULL;

    return n;
}


////////// Min Heap //////////
void swap(edge* a, edge* b) {
    edge tmp = *a;
    *a = *b;
    *b = tmp;
}

Heap* createMinHeap(int size) {
    Heap* H = (Heap*)malloc(sizeof(Heap));

    H->arr = (edge*)malloc(sizeof(edge) * (size + 1));
    H->heapLen = 0;
    H->arrLen = 0;
    H->size = size;

    return H;
}

void heapifyAt(edge arr[], int n, int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;

    if (left <= n && arr[smallest].weight > arr[left].weight) {
        smallest = left;
    }
    if (right <= n && arr[smallest].weight > arr[right].weight) {
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

edge extractMinHeap(struct Heap* H) {
    edge tmp = H->arr[1];

    H->arr[1] = H->arr[H->heapLen];
    H->arr[H->heapLen] = tmp;
    H->heapLen -= 1;
    H->arrLen -= 1;

    minHeapify(H, 1);

    return tmp;
}

void insertAt(edge arr[], int idx) {
    if (idx == 1) {
        return;
    }
    int parent = idx / 2;
    if (arr[parent].weight > arr[idx].weight) {
        swap(&arr[parent], &arr[idx]);
        insertAt(arr, parent);
    }
}

void insert(struct Heap* H, edge val) {
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
    graph->adjLists = (node**)malloc(vertices * sizeof(node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    // Add edge from src to dest
    node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}


////////// Prims //////////
/**
 * @brief Insert all the edges from vertex to the heap
 * 
 * @param vertex a vertex of the graph
 * @param graph teh given graph
 * @param edgeList min heap of all the edges
 */
void insertEdge(int vertex, Graph* graph, Heap* edgeList) {
    edge a;

    node* head = graph->adjLists[vertex];
    while (head != NULL) {
        a.u = vertex;
        a.v = head->vertex;
        a.weight = head->weight;
        insert(edgeList, a);

        head = head->next;
    }
}

Graph* prims(Graph* graph, int m) {
    int edgesInserted = 0;
    Graph* g = createGraph(graph->numVertex);
    Heap* edgeList = createMinHeap(m);

    graph->visited[0] = 1;
    insertEdge(0, graph, edgeList);

    edge added;
    while (edgesInserted < (graph->numVertex - 1)) {
        added = extractMinHeap(edgeList);

        if (graph->visited[added.u] == 1 && graph->visited[added.v] == 1) {
            continue;
        }

        if (graph->visited[added.u] == 1) {
            graph->visited[added.v] = 1;
            insertEdge(added.v, graph, edgeList);
        }
        else {
            graph->visited[added.u] = 1;
            insertEdge(added.u, graph, edgeList);
        }
        printf("Added: %d %d %d\n", added.u, added.v, added.weight);
        addEdge(g, added.u, added.v, added.weight);
        edgesInserted += 1;
    }

    return g;
}

////////// Main Function //////////
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph(n);

    int _u, _v, _w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &_u, &_v, &_w);
        addEdge(graph, _u, _v, _w);
    }

    Graph* g = prims(graph, m);
    printf("Created Graph\n");

    // Printing the total weight of the minimum spanning tree
    int weight = 0;
    for (int i = 0; i < g->numVertex; i++) {
        node* tmp = g->adjLists[i];

        while (tmp != NULL) {
            weight += tmp->weight;
            tmp = tmp->next;
        }
    }

    weight /= 2;

    printf("Weight: %d", weight);

    return 0;
}
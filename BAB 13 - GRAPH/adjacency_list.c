#include <stdio.h>
#include <stdlib.h>

// Struktur Node untuk Adjacency List
struct Node {
    int dest;              // Vertex tujuan
    struct Node* next;     // Pointer ke node berikutnya
};

// Struktur Graph
struct Graph {
    int numVertices;               // Jumlah vertex
    struct Node** adjLists;        // Array dari Linked List
};

// Fungsi membuat node baru
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = NULL;
    return newNode;
}

// Fungsi membuat Graph dengan V vertex
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Fungsi menambahkan edge (Undirected Graph)
void addEdge(struct Graph* graph, int src, int dest) {
    // Tambahkan edge dari src ke dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Karena Undirected, tambahkan juga dari dest ke src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

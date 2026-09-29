#include <stdbool.h>

#define MAX_V 100

int queue[MAX_V];
int front = 0, rear = -1;

void enqueue(int value) { queue[++rear] = value; }
int dequeue() { return queue[front++]; }
bool isEmpty() { return front > rear; }

void BFS(struct Graph* graph, int startVertex) {
    bool visited[MAX_V] = {false};

    enqueue(startVertex);
    visited[startVertex] = true;

    printf("BFS (dari vertex %d): ", startVertex);
    while (!isEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                enqueue(adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

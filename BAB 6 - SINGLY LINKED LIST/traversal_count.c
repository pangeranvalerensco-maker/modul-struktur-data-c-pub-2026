#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* buatNode(int nilai) { // Fungsi membuat node baru
    Node *nodeBaru = (Node*)malloc(sizeof(Node));
    if (nodeBaru == NULL) {
        printf("Alokasi memori gagal!\n");
        return NULL;
    }
    nodeBaru->data = nilai;
    nodeBaru->next = NULL;
    return nodeBaru;
}

void tampilkanList(Node *head) { // Fungsi menampilkan list
    Node *current = head;
    if (current == NULL) {
        printf("Linked list kosong.\n");
        return;
    }
    printf("Isi linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int hitungNode(Node *head) { // Fungsi menghitung jumlah node
    int count = 0;
    Node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    Node *head = NULL;   // inisialisasi kosong

    // Buat beberapa node (untuk contoh, kita buat 3 node)
    Node *node1 = buatNode(10);
    Node *node2 = buatNode(20);
    Node *node3 = buatNode(30);

    head = node1; // Hubungkan node
    node1->next = node2;
    node2->next = node3;
    // node3->next sudah NULL dari buatNode

    tampilkanList(head); // Tampilkan semua data

    printf("Jumlah node: %d\n", hitungNode(head)); // Tampilkan jumlah node

    free(node3); // Bebaskan memori (penting!)
    free(node2);
    free(node1);

    return 0;
}
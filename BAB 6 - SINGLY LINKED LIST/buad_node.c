#include <stdio.h>
#include <stdlib.h>  // untuk malloc dan free

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* buatNode(int nilai) { // Fungsi untuk membuat node baru
    Node *nodeBaru = (Node*)malloc(sizeof(Node)); // 1. Alokasikan memori untuk satu Node
    
    if (nodeBaru == NULL) { // 2. Periksa apakah alokasi berhasil
        printf("Alokasi memori gagal!\n");
        return NULL;
    }
    
    nodeBaru->data = nilai; // 3. Isi data node dengan nilai yang diberikan
    nodeBaru->next = NULL; // 4. Set pointer next ke NULL (karena belum terhubung)

    return nodeBaru; // 5. Kembalikan pointer ke node baru
}

int main() {
    Node *node1 = buatNode(10); // Membuat sebuah node dengan data 10
    
    if (node1 != NULL) {
        printf("Node berhasil dibuat dengan data: %d\n", node1->data);
    }
    
    free(node1); // Jangan lupa bebaskan memori setelah selesai!
    node1 = NULL;
    
    return 0;
}
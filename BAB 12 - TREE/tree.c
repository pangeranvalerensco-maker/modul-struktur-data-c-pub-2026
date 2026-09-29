typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* buatNode(int data) {
    Node *baru = (Node*)malloc(sizeof(Node));
    if (baru == NULL) return NULL;
    baru->data = data;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

void tambahKiri(Node *parent, int data) {
    parent->left = buatNode(data);
}

void tambahKanan(Node *parent, int data) {
    parent->right = buatNode(data);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Tambahkan ini untuk bool

// Fungsi untuk menampilkan tree dalam format hirarki
void cetakTree(Node *root, int level, bool isRight) {
    if (root == NULL) return;

    // Cetak indentasi (spasi) sesuai level
    for (int i = 0; i < level; i++) {
        if (i == level - 1) {
            printf("+-");
        } else if (i == level - 2 && !isRight) {
            printf("| ");
        } else {
            printf("  ");
        }
    }

    printf("%d\n", root->data);
    level++;

    // Rekursif ke kiri dan kanan
    cetakTree(root->left, level, false);
    cetakTree(root->right, level, true);
}

// INSERT
Node* insert(Node *root, int data) {
    if (root == NULL) return buatNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

// SEARCH (return 1 ketemu, 0 gak ketemu)
int search(Node *root, int target) {
    if (root == NULL) return 0;
    if (root->data == target) return 1;
    if (target < root->data) return search(root->left, target);
    return search(root->right, target);
}

// TRAVERSAL (Contoh In-order)
void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

Node* buatNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Alokasi memori gagal!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

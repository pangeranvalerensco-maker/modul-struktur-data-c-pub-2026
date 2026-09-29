#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* buatNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return buatNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

int search(Node* root, int target) {
    if (root == NULL) return 0;
    if (root->data == target) return 1;
    if (target < root->data) return search(root->left, target);
    return search(root->right, target);
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) current = current->left;
    return current;
}

Node* deleteNode(Node* root, int target) {
    if (root == NULL) return root;
    if (target < root->data) root->left = deleteNode(root->left, target);
    else if (target > root->data) root->right = deleteNode(root->right, target);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = NULL;
    int pilihan, data;
    do {
        printf("\n=== MENU BST ===\n");
        printf("1. Insert Data\n");
        printf("2. Search Data\n");
        printf("3. Tampilkan In-Order\n");
        printf("4. Delete Data\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                printf("Masukkan angka: "); scanf("%d", &data);
                root = insert(root, data);
                printf("Data %d berhasil ditambahkan.\n", data);
                break;
            case 2:
                printf("Cari angka: "); scanf("%d", &data);
                if (search(root, data)) printf("Data ditemukan!\n");
                else printf("Data tidak ditemukan.\n");
                break;
            case 3:
                printf("Isi BST (Ascending): ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Hapus angka: "); scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Proses hapus selesai.\n");
                break;
            case 5:
                printf("Keluar.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
    return 0;
}
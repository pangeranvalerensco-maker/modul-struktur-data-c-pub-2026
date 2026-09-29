// Fungsi helper untuk mencari nilai terkecil di Subtree (In-order Successor)
Node* minValueNode(Node* node) {
    Node* current = node;
    // Loop ke kiri sampai ketemu leaf (yang paling kecil)
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int target) {
    // 1. Basis: Jika root NULL, tidak ada yang dihapus.
    if (root == NULL) return root;

    // 2. Cari node yang mau dihapus secara rekursif
    if (target < root->data) {
        root->left = deleteNode(root->left, target);
    } else if (target > root->data) {
        root->right = deleteNode(root->right, target);
    } else {
        // KITA KETEMU NODE-NYA! Sekarang tentukan Kasusnya.

        // Kasus 1 & 2: 1 Child atau 0 Child (Leaf)
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Kasus 3: 2 Children
        // Cari In-order Successor (nilai terkecil di subtree kanan)
        Node* temp = minValueNode(root->right);

        // Salin nilai Successor ke Root (node yang mau dihapus)
        root->data = temp->data;

        // Hapus Successor tersebut (sekarang dia ada di subtree kanan)
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

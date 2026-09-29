#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *next;
}*head = NULL, *baru, *bantu, *sebelum;

void hapusByIndex(int indeks) {
    if (indeks < 0 || indeks >= hitungNode()) { // Cek validitas indeks
        printf("Indeks %d tidak valid\n", indeks);
        return;
    }
    if (indeks == 0) { // Jika indeks 0
        hapusDepan();
        return;
    }
    bantu = head;
    for (int i = 0; i < indeks; i++) { // Traversal ke node yang akan dihapus
        sebelum = bantu;
        bantu = bantu->next;
    }
    sebelum->next = bantu->next; // Lepaskan node dari list
    free(bantu); // Hapus node
}

int main() {
    tambahBelakang(10);
    tambahBelakang(20);
    tambahBelakang(30);

    tampilkanList();  // Output: 10 20 30

    hapusByIndex(1);  // Hapus node pada indeks 1 (20)
    tampilkanList();  // Output: 10 30

    hapusByIndex(5);  // Coba hapus indeks yang tidak ada
    tampilkanList();  // Output: 10 30

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *prev;
    struct node *next;
} *head = NULL, *tail = NULL, *baru, *bantu;

void hapusByValue(int nilai) {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    bantu = head; // Cari node dengan nilai yang dicari
    while (bantu != NULL && bantu->angka != nilai) {
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        printf("Nilai %d tidak ditemukan\n", nilai);
        return;
    }

    if (bantu == head) { // Jika node yang dihapus adalah head
        hapusDepan();
        return;
    }

    if (bantu == tail) { // Jika node yang dihapus adalah tail
        hapusBelakang();
        return;
    }

    // Hapus node di tengah
    bantu->prev->next = bantu->next;
    bantu->next->prev = bantu->prev;

    free(bantu);
}

int main() {
    tambahBelakang(10);
    tambahBelakang(20);
    tambahBelakang(30);

    tampilkanList();  // Output: 10 20 30

    hapusByValue(20); // Hapus node dengan nilai 20
    tampilkanList();  // Output: 10 30

    hapusByValue(40); // Coba hapus nilai yang tidak ada
    tampilkanList();  // Output: 10 30

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *prev;
    struct node *next;
} *head = NULL, *tail = NULL, *baru, *bantu;

void hapusByIndex(int indeks) {
    int count = hitungNode(); // Hitung jumlah node saat ini
    if (indeks < 0 || indeks >= count) {
        printf("Indeks %d tidak valid\n", indeks);
        return;
    }

    if (indeks == 0) {
        hapusDepan();
        return;
    }

    if (indeks == count - 1) {
        hapusBelakang();
        return;
    }

    bantu = head; // Traversal ke node yang akan dihapus
    for (int i = 0; i < indeks; i++) {
        bantu = bantu->next;
    }

    // Hapus node di tengah
    bantu->prev->next = bantu->next;
    bantu->next->prev = bantu->prev;

    free(bantu);
}
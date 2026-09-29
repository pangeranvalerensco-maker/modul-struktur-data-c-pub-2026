#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *prev;
    struct node *next;
} *head = NULL, *tail = NULL, *baru, *bantu;

void tambahSetelahNilai(int target, int angkaBaru) {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    bantu = head; // Cari node dengan nilai target
    while (bantu != NULL && bantu->angka != target) {
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        printf("Nilai %d tidak ditemukan\n", target);
        return;
    }

    baru = (struct node*)malloc(sizeof(struct node)); // Buat node baru
    baru->angka = angkaBaru;
    baru->prev = bantu;
    baru->next = bantu->next;

    if (bantu->next != NULL) {
        bantu->next->prev = baru; // node setelah target prev ke baru
    } else {
        tail = baru; // jika node baru di akhir, update tail
    }

    bantu->next = baru; // target next ke baru
}

int main() {
    tambahBelakang(10);
    tambahBelakang(20);
    tambahBelakang(30);

    tambahSetelahNilai(20, 25); // tambahkan 25 setelah 20

    tampilkanList(); // Output: 10 20 25 30

    return 0;
}
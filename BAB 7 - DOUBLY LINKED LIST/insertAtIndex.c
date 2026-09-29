#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *prev;
    struct node *next;
} *head = NULL, *tail = NULL, *baru, *bantu;

void tambahPadaIndeks(int indeks, int angkaBaru) {
    int count = hitungNode(); // Hitung jumlah node saat ini
    if (indeks < 0 || indeks > count) {
        printf("Indeks %d tidak valid\n", indeks);
        return;
    }

    if (indeks == 0) {
        tambahDepan(angkaBaru);
        return;
    }

    if (indeks == count) {
        tambahBelakang(angkaBaru);
        return;
    }

    bantu = head; // Traversal ke posisi sebelum indeks
    for (int i = 0; i < indeks - 1; i++) {
        bantu = bantu->next;
    }

    baru = (struct node*)malloc(sizeof(struct node)); // Buat node baru
    baru->angka = angkaBaru;
    baru->prev = bantu;
    baru->next = bantu->next;

    bantu->next->prev = baru; // node setelah indeks prev ke baru
    bantu->next = baru; // bantu next ke baru
}

int hitungNode() {
    int count = 0;
    bantu = head;
    while (bantu != NULL) {
        count++;
        bantu = bantu->next;
    }
    return count;
}

int main() {
    tambahBelakang(10);  // [10]
    tambahBelakang(20);  // [10, 20]
    tambahBelakang(30);  // [10, 20, 30]

    tambahPadaIndeks(2, 25); // [10, 20, 25, 30]

    tampilkanList();    // Output: 10 20 25 30

    return 0;
}
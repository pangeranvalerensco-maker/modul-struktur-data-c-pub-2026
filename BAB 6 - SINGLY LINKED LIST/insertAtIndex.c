#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *next;
}*head = NULL, *baru, *bantu;

void tambahPadaIndeks(int indeks, int angkaBaru) {
    // 1. Validasi indeks, gunakan fungsi hitungNode() untuk mendapatkan jumlah node saat ini
    if (indeks < 0 || indeks > hitungNode()) { 
        printf("Indeks %d tidak valid.\n", indeks);
        return;
    }

    if (indeks == 0) { // 2. Jika indeks 0, tambahkan di depan
        tambahDepan(angkaBaru);
        return;
    }

    baru = (struct node*)malloc(sizeof(struct node)); // 3. Buat node baru
    if (baru == NULL) {
        printf("Alokasi memori gagal!\n");
        return;
    }
    baru->angka = angkaBaru;

    bantu = head; // 4. Traversal ke posisi sebelum indeks
    for (int i = 0; i < indeks - 1; i++) {
        bantu = bantu->next;
    }

    baru->next = bantu->next; // 5. Tambahkan node baru
    bantu->next = baru;
}

int main() {
    tambahBelakang(10);  // [10]
    tambahBelakang(20);  // [10, 20]
    tambahBelakang(30);  // [10, 20, 30]

    tambahPadaIndeks(2, 25); // [10, 20, 25, 30]

    tampilkanList(head);    // Output: 10 20 25 30

    return 0;
}
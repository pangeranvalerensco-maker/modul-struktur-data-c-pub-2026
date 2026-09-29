#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *next;
}*head = NULL, *baru, *bantu;

void updateByIndex(int indeks, int newVal) {
    if (head == NULL) { // Cek list kosong
        printf("List kosong!\n");
        return;
    }
    if (indeks < 0 || indeks >= hitungNode()) { // Validasi indeks
        printf("Indeks %d tidak valid\n", indeks);
        return;
    }

    bantu = head; // Mulai dari head
    for (int i = 0; i < indeks; i++) { // Traversal ke indeks yang dituju
        bantu = bantu->next;
    }

    bantu->angka = newVal; // Ubah nilai node
    printf("Nilai pada indeks %d diubah menjadi %d\n", indeks, newVal);
}

int main() {
    tambahBelakang(10);
    tambahBelakang(20);
    tambahBelakang(30);

    tampilkanList();  // Output: 10 20 30

    updateByIndex(1, 25); // Ubah nilai pada indeks 1 menjadi 25
    tampilkanList();      // Output: 10 25 30

    updateByIndex(5, 50); // Coba ubah nilai pada indeks yang tidak ada
    tampilkanList();      // Output: 10 25 30

    return 0;
}
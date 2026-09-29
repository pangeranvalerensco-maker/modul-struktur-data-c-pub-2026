#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *next;
}*head = NULL, *baru, *bantu;

void cari(int data) {
    bantu = head; // Mulai dari head (node pertama)
    int indeks = 0, ditemukan = 0; // indeks untuk mencatat posisi, ditemukan sebagai penanda

    while (bantu != NULL) {
        if (bantu->angka == data) { // Jika data ditemukan, tampilkan indeksnya
            printf("Data %d ditemukan pada indeks %d\n", data, indeks);
            ditemukan++; // increment penanda
        }
        bantu = bantu->next; // Pindah ke node berikutnya
        indeks++;
    }

    if (ditemukan == 0) { // Jika tidak ditemukan
        printf("Data %d tidak ditemukan\n", data);
    }
}

int main() {
    tambahBelakang(10);
    tambahBelakang(20);
    tambahBelakang(30);
    tambahBelakang(20);

    tampilkanList();  // Output: 10 20 30 20

    cari(20);         // Cari nilai 20
    cari(40);         // Cari nilai yang tidak ada

    return 0;
}
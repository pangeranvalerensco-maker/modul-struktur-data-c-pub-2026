#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *prev;
    struct node *next;
} *head = NULL, *tail = NULL, *baru, *bantu;

void tambahTengah(int angka) {
    int count = hitungNode(); // Hitung jumlah node saat ini
    if (head == NULL) {                     // list kosong
        tambahDepan(angka);
        return;
    }

    if (count == 1) {                       // hanya satu node
        tambahBelakang(angka);
        return;
    }

    int posisiTengah; // Tentukan posisi tengah
    if (count % 2 == 1) {                   // ganjil
        posisiTengah = (count - 1) / 2;
    } else {                                // genap
        posisiTengah = (count / 2) - 1;
    }

    bantu = head; // Traversal ke posisi tengah
    for (int i = 0; i < posisiTengah; i++) {
        bantu = bantu->next;
    }

    baru = (struct node*)malloc(sizeof(struct node)); // Buat node baru
    baru->angka = angka;
    baru->prev = bantu;
    baru->next = bantu->next;

    if (bantu->next != NULL) {
        bantu->next->prev = baru;           // node setelah bantu prev ke baru
    } else {
        tail = baru;                        // jika node baru di akhir
    }

    bantu->next = baru;                     // bantu next ke baru
    count++;
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
    tambahTengah(10);
    tambahTengah(20);
    tambahTengah(30);

    bantu = head;
    printf("Isi list: ");
    while (bantu != NULL) {
        printf("|%d|->", bantu->angka);
        bantu = bantu->next;
    }
    printf("NULL\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int angka;
    struct Node *next;
}*head = NULL, *baru, *bantu;

void tambahDepan(int angka) {
    baru = (struct Node*)malloc(sizeof(struct Node)); // 1. Alokasikan memori untuk node baru
    if (baru == NULL) {
        printf("Alokasi memori gagal!\n");
        return;
    }

    baru->angka = angka; // 2. Isi data node baru

    baru->next = head; // 3. Arahkan node baru ke head yang lama

    head = baru; // 4. Head sekarang menunjuk ke node baru
}

void tampilkanList() {
    bantu = head;
    while (bantu != NULL) {
        printf("%d ", bantu->angka);
        bantu = bantu->next;
    }
    printf("\n");
}

int main() {
    tambahDepan(10);
    tambahDepan(20);
    tambahDepan(30);

    tampilkanList();  // Output: 30 20 10

    return 0;
}
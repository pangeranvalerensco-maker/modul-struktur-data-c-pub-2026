#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *next;
}*head = NULL, *baru, *bantu;

void tambahBelakang(int nilai) {
    baru = (struct node*)malloc(sizeof(struct node)); // 1. Alokasikan memori untuk node baru
    if (baru == NULL) {
        printf("Alokasi memori gagal!\n");
        return;
    }

    baru->angka = nilai; // 2. Isi data node baru
    baru->next = NULL;

    if (head == NULL) { // 3. Jika list kosong, node baru menjadi head
        head = baru;
    } else {
        bantu = head; // 4. Cari node terakhir
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }

        bantu->next = baru; // 5. Hubungkan node terakhir ke node baru
    }
}

int main() {
    tambahBelakang(10);
    tambahBelakang(20);
    tambahBelakang(30);

    tampilkanList();  // Output: 10 20 30

    return 0;
}
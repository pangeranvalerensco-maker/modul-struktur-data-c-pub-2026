#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *next;
}*head = NULL, *baru, *bantu;

void hapusBelakang() {
    if (head == NULL) { // Cek list kosong
        printf("List kosong!\n");
        return;
    }
    if (head->next == NULL) { // Jika hanya satu node
        free(head);
        head = NULL;
        return;
    }
    bantu = head; // Cari node sebelum terakhir
    while (bantu->next->next != NULL) { // loop sampai bantu berada di node sebelum node terakhir.
        bantu = bantu->next;
    }
    free(bantu->next); // Hapus node terakhir
    bantu->next = NULL; // Set next node sebelumnya menjadi NULL
}

int main() {
    tambahBelakang(10);
    tambahBelakang(20);
    tambahBelakang(30);

    tampilkanList();  // Output: 10 20 30

    hapusBelakang();  // Hapus node terakhir (30)
    tampilkanList();  // Output: 10 20

    hapusBelakang();  // Hapus node terakhir (20)
    tampilkanList();  // Output: 10

    hapusBelakang();  // Hapus node terakhir (10)
    tampilkanList();  // Output: List kosong!

    hapusBelakang();  // Coba hapus dari list kosong
    return 0;
}
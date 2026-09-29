#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *prev;
    struct node *next;
} *head = NULL, *tail = NULL, *baru, *bantu;

void hapusBelakang() {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    if (head == tail) { // jika hanya satu node
        free(head); // hapus langsung
        head = tail = NULL;
        return;
    }

    bantu = tail; // simpan alamat node terakhir
    tail = tail->prev; // pindahkan tail ke node sebelumnya
    tail->next = NULL; // tail baru next = NULL

    free(bantu); // hapus node terakhir
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
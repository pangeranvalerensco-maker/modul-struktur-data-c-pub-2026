#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *prev;
    struct node *next;
} *head = NULL, *tail = NULL, *baru, *bantu;

void hapusDepan() {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    bantu = head; // simpan alamat node pertama untuk di-free
    head = head->next; // pindahkan head ke node berikutnya

    if (head != NULL) {
        head->prev = NULL; // atur prev node baru menjadi NULL
    } else {
        tail = NULL; // jika list kosong, tail juga NULL
    }

    free(bantu); // hapus node pertama
}

int main() {
    tambahBelakang(10);
    tambahBelakang(20);
    tambahBelakang(30);

    tampilkanList();  // Output: 10 20 30

    hapusDepan();     // Hapus node pertama (10)
    tampilkanList();  // Output: 20 30

    hapusDepan();     // Hapus node pertama (20)
    tampilkanList();  // Output: 30

    hapusDepan();     // Hapus node pertama (30)
    tampilkanList();  // Output: List kosong!

    hapusDepan();     // Coba hapus dari list kosong
    return 0;
}
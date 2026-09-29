#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *next;
}*head = NULL, *baru, *bantu;

void hapusDepan() {
    if (head == NULL) { // Cek apakah list kosong
        printf("List kosong!\n");
        return;
    }
    bantu = head; // pointer bantu menyimpan alamat node pertama agar bisa di-free
    head = head->next; // head sekarang menunjuk ke node kedua / NULL
    free(bantu); // Bebaskan memori node pertama
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
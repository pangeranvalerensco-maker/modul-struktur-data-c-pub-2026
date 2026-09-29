#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *prev;
    struct node *next;
} *head = NULL, *tail = NULL, *baru, *bantu;

void hapusTengah() {
    int count = hitungNode(); // Hitung jumlah node saat ini
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    if (head == tail) { // jika hanya satu node
        free(head);
        head = tail = NULL;
        return;
    }

    int posisiTengah; // Tentukan posisi tengah
    if (count % 2 == 1) { // ganjil
        posisiTengah = (count - 1) / 2;
    } else { // genap
        posisiTengah = (count / 2) - 1;
    }

    bantu = head; // Traversal ke node tengah
    for (int i = 0; i < posisiTengah; i++) {
        bantu = bantu->next;
    }

    if (bantu->prev != NULL) { // Hubungkan node sebelum dan sesudah bantu
        bantu->prev->next = bantu->next;
    } else {
        head = bantu->next; // jika bantu adalah head (tidak mungkin di tengah)
    }

    if (bantu->next != NULL) {
        bantu->next->prev = bantu->prev;
    } else {
        tail = bantu->prev; // jika bantu adalah tail (tidak mungkin di tengah)
    }

    free(bantu); // hapus node tengah
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
    tambahBelakang(10);
    tambahBelakang(20);
    tambahBelakang(30);
    tambahBelakang(40);
    tambahBelakang(50);

    printf("Sebelum menghapus node tengah:\n");
    tampilkanList();

    hapusTengah();

    printf("Setelah menghapus node tengah:\n");
    tampilkanList();

    return 0;
}
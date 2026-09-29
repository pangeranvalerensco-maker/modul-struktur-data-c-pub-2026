#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *next;
}*head = NULL, *baru, *bantu, *cepat, *sebelum;

void hapusTengah() {
    if (head == NULL) { // Cek list kosong
        printf("List kosong!\n");
        return;
    }
    if (head->next == NULL) { // Jika hanya satu node
        free(head);
        head = NULL;
        return;
    }
    // Dua pointer: bantu (lambat), cepat (cepat)
    bantu = head;
    cepat = head;
    sebelum = NULL; // Untuk menyimpan node sebelum bantu

    while (cepat != NULL && cepat->next != NULL) {
        sebelum = bantu; // Simpan node sebelum bantu untuk menghubungkan ulang list setelah penghapusan.
        bantu = bantu->next; // bantu maju 1 langkah
        cepat = cepat->next->next; // cepat maju 2 langkah
    }
    // Setelah loop, bantu menunjuk ke node tengah
    sebelum->next = bantu->next; // Hubungkan node sebelum tengah ke node setelah tengah.
    free(bantu); // Hapus node tengah
}

int main() {
    // Contoh penggunaan fungsi hapusTengah
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
#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *next;
}*head = NULL, *baru, *bantu;

// Fungsi menambahkan node setelah node dengan nilai tertentu
void tambahSetelahNilai(int target, int angkaBaru) {
    // 1. Jika list kosong, tidak bisa menambahkan
    if (head == NULL) {
        printf("List kosong, tidak bisa menambahkan setelah nilai tertentu.\n");
        return;
    }

    // 2. Cari node dengan nilai target
    bantu = head;
    while (bantu != NULL && bantu->angka != target) {
        bantu = bantu->next;
    }

    // 3. Jika tidak ditemukan
    if (bantu == NULL) {
        printf("Nilai %d tidak ditemukan.\n", target);
        return;
    }

    // 4. Buat node baru
    baru = (struct node*)malloc(sizeof(struct node));
    if (baru == NULL) {
        printf("Alokasi memori gagal!\n");
        return;
    }
    baru->angka = angkaBaru;

    // 5. Tambahkan setelah node yang ditemukan
    baru->next = bantu->next;
    bantu->next = baru;
}

int main() {
    tambahBelakang(10);
    tambahBelakang(&head, 20);
    tambahBelakang(&head, 30);

    tambahSetelahNilai(20, 25);  // tambahkan 25 setelah 20

    tampilkanList();  // Output: 10 20 25 30

    return 0;
}
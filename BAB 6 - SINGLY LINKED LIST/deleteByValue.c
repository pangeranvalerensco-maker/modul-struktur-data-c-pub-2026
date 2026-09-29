#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *next;
}*head = NULL, *baru, *bantu, *sebelum;

void hapusByValue(int nilai) {
    if (head == NULL) { // Cek list kosong
        printf("List kosong!\n");
        return;
    }
    if (head->angka == nilai) { // Jika node pertama yang dihapus
        hapusDepan(); // Pakai fungsi hapusDepan
        return;
    }
    bantu = head;
    while (bantu != NULL && bantu->angka != nilai) {
        sebelum = bantu; // Simpan node sebelum bantu
        bantu = bantu->next;
    }
    if (bantu == NULL) { // Jika tidak ditemukan
        printf("Nilai %d tidak ditemukan\n", nilai);
        return;
    }
    sebelum->next = bantu->next; // Lepaskan node dari list
    free(bantu);     
}

int main() {
    tambahBelakang(10);
    tambahBelakang(20);
    tambahBelakang(30);

    tampilkanList();  // Output: 10 20 30

    hapusByValue(20); // Hapus node dengan nilai 20
    tampilkanList();  // Output: 10 30

    hapusByValue(40); // Coba hapus nilai yang tidak ada
    tampilkanList();  // Output: 10 30

    return 0;
}
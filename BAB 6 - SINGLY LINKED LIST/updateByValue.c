#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *next;
}*head = NULL, *baru, *bantu;

void updateByValue(int oldVal, int newVal) {
    bantu = head; // Mulai dari head

    while (bantu != NULL) {
        if (bantu->angka == oldVal) { // Jika nilai ditemukan
            bantu->angka = newVal; // Ganti dengan nilai baru
            printf("Nilai %d diubah menjadi %d\n", oldVal, newVal);
            return; // Keluar setelah perubahan pertama
        }
        bantu = bantu->next; // Pindah ke node berikutnya
    }

    printf("Data %d tidak ditemukan\n", oldVal); // Jika tidak ditemukan
}

int main() {
    tambahBelakang(10);
    tambahBelakang(20);
    tambahBelakang(30);

    tampilkanList();  // Output: 10 20 30

    updateByValue(20, 25); // Ubah nilai 20 menjadi 25
    tampilkanList();       // Output: 10 25 30

    updateByValue(40, 50); // Coba ubah nilai yang tidak ada
    tampilkanList();       // Output: 10 25 30

    return 0;
}
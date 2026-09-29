#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *next;
}*head = NULL; // pointer head untuk menunjuk ke node pertama

void tampilkanList() { // Fungsi untuk menampilkan semua data dalam linked list
    struct node *bantu = head; // 1. Buat pointer bantu yang menunjuk ke head

    if (bantu == NULL) { // 2. Periksa apakah list kosong
        printf("Linked list kosong.\n");
        return;
    }

    printf("Isi linked list: "); // 3. Traversal: selama bantu != NULL
    while (bantu != NULL) {
        printf("|%d|->", bantu->angka);   // tampilkan data
        bantu = bantu->next;              // pindah ke node berikutnya
    }
    printf("NULL\n");
}

void tampilkanListRekursif() { // Fungsi menampilkan list secara rekursif
    if (head == NULL) { // Basis: jika head == NULL, berhenti
        return;
    }

    printf("%d ", head->angka); // Tampilkan data di node saat ini

    tampilkanListRekursif(head->next); // Panggil diri sendiri untuk node berikutnya
}

int hitungNode() { // Fungsi menghitung jumlah node dalam linked list
    int count = 0;
    struct node *bantu = head;

    while (bantu != NULL) {
        count++;
        bantu = bantu->next;
    }

    return count;
}

int main() {
    // struct node *head = NULL;  // inisialisasi kosong

    // // ... (nanti kita akan tambahkan node di subbab selanjutnya)

    tampilkanListRekursif();  // menampilkan semua data

    return 0;
}
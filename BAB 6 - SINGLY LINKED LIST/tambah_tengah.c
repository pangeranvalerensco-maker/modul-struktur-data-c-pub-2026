#include <stdio.h>
#include <stdlib.h>

struct Node {
    int angka;
    struct Node *next;
}*head = NULL, *baru, *bantu;

void tambahTengah(int nilai) {
    int count = 0;
    baru = (struct Node*)malloc(sizeof(struct Node)); // 1. Buat node baru
    if (baru == NULL) {
        printf("Alokasi memori gagal!\n");
        return;
    }
    baru->angka = nilai;

    if (head == NULL) { // 2. Jika list kosong, tambahkan di depan
        baru->next = NULL;
        head = baru;
        count++;
        return;
    }

    if (head->next == NULL) { // 3. Jika hanya satu node, tambahkan setelah head
        head->next = baru;
        baru->next = NULL;
        count++;
        return;
    }

    int posisiTengah = count / 2; // 4. Tentukan posisi tengah

    bantu = head; // 5. Traversal ke posisi tengah
    for (int i = 0; i < posisiTengah; i++) {
        bantu = bantu->next;
    }
    baru->next = bantu->next; // 6. Sisipkan node baru
    bantu->next = baru;
}

int main() {
    tambahTengah(10);
    tambahTengah(20);
    tambahTengah(30);

    tampilkanList(head);  // Output: 10 20 30

    return 0;
}
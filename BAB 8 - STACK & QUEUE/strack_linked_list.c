#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;              // data yang disimpan
    struct node *next;      // pointer ke node berikutnya
} *head = NULL, *baru, *bantu;  // head sebagai penunjuk puncak stack

void push(int data) { // Menambahkan data di puncak stack (di awal linked list)
    baru = (struct node*)malloc(sizeof(struct node));
    baru->angka = data;
    baru->next = head;      // node baru menunjuk ke head lama
    head = baru;            // head sekarang menunjuk ke node baru
}

void pop() { // Menghapus elemen puncak stack (head)
    if (head == NULL) {
        printf("Stack kosong!\n");
        return;
    }
    bantu = head;           // simpan node yang akan dihapus
    head = head->next;      // pindahkan head ke node berikutnya
    free(bantu);            // bebaskan memori node lama
}

int peek() { // Melihat data di puncak stack tanpa menghapusnya
    if (head == NULL) return -1;
    return head->angka;     // data di node head
}

void tampilkanStack() { // Menampilkan semua data stack dari atas ke bawah
    if (head == NULL) {
        printf("Stack kosong.\n");
        return;
    }
    bantu = head;
    printf("Stack (atas ke bawah): ");
    while (bantu != NULL) {         // loop selama masih ada node
        printf("|%d| ", bantu->angka);
        bantu = bantu->next;        // pindah ke node berikutnya
    }
    printf("\n");
}

int main() {
    int pilihan, data;
    do {
        printf("======== STACK DENGAN LINKED LIST =========\n");
        printf("1. Push (Tambah di Atas)\n");
        printf("2. Pop (Hapus dari Atas)\n");
        printf("3. Peek (Lihat Atas)\n");
        printf("4. Tampilkan\n");
        printf("5. Keluar\n");
        printf("==========================================\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan angka: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                data = peek();
                if (data != -1) printf("Elemen teratas: %d\n", data);
                break;
            case 4:
                tampilkanStack();
                break;
            case 5:
                printf("Keluar.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
    return 0;
}
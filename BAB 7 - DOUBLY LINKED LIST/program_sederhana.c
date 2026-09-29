#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *prev;
    struct node *next;
} *head = NULL, *tail = NULL, *baru, *bantu;

int count = 0;

void tambahBelakang(int angka) {
    baru = (struct node*)malloc(sizeof(struct node));
    baru->angka = angka;
    baru->prev = NULL;
    baru->next = NULL;

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    count++;
}

void tampilkanList() {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }
    bantu = head;
    printf("Isi list (maju): ");
    while (bantu != NULL) {
        printf("|%d|->", bantu->angka);
        bantu = bantu->next;
    }
    printf("NULL\n");
}

void hapusDepan() {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }
    bantu = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    else tail = NULL;
    free(bantu);
    count--;
}

void updateByValue(int oldVal, int newVal) {
    bantu = head;
    while (bantu != NULL) {
        if (bantu->angka == oldVal) {
            bantu->angka = newVal;
            printf("Nilai %d diubah menjadi %d\n", oldVal, newVal);
            return;
        }
        bantu = bantu->next;
    }
    printf("Nilai %d tidak ditemukan\n", oldVal);
}

int main() {
    int pilihan, angka, oldVal, newVal;

    tambahBelakang(10);
    tambahBelakang(20);
    tambahBelakang(30);
    do {
        // system("cls");
        printf("========== MENU DLL ==========\n");
        printf("1. Tambah Belakang\n");
        printf("2. Tampilkan List\n");
        printf("3. Hapus Depan\n");
        printf("4. Update By Value\n");
        printf("5. Keluar\n");
        printf("==============================\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan angka: ");
                scanf("%d", &angka);
                tambahBelakang(angka);
                break;
            case 2:
                tampilkanList();
                break;
            case 3:
                hapusDepan();
                break;
            case 4:
                tampilkanList();
                printf("Masukkan nilai lama: ");
                scanf("%d", &oldVal);
                printf("Masukkan nilai baru: ");
                scanf("%d", &newVal);
                updateByValue(oldVal, newVal);
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
        // printf("\nTekan Enter untuk melanjutkan...");
        // getchar();
        // getchar();
    } while (pilihan != 5);

    return 0;
}
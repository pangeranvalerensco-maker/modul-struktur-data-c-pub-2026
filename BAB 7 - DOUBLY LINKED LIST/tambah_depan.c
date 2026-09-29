#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *prev;
    struct node *next;
} *head = NULL, *tail = NULL, *baru, *bantu;

void tambahDepan(int angka) {
    baru = (struct node*)malloc(sizeof(struct node));
    baru->angka = angka;
    baru->prev = NULL;
    baru->next = NULL;

    if (head == NULL) {               // list kosong
        head = tail = baru;
    } else {
        baru->next = head;            // sambungkan ke head lama
        head->prev = baru;            // head lama prev ke baru
        head = baru;                  // head sekarang node baru
    }
}

int main() {
    tambahDepan(10);
    tambahDepan(20);
    tambahDepan(30);

    bantu = head;
    printf("Isi list: ");
    while (bantu != NULL) {
        printf("|%d|->", bantu->angka);
        bantu = bantu->next;
    }
    printf("NULL\n");

    return 0;
}
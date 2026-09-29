#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *prev;
    struct node *next;
} *head = NULL, *tail = NULL, *baru, *bantu;

void tambahBelakang(int angka) {
    baru = (struct node*)malloc(sizeof(struct node));
    baru->angka = angka;
    baru->prev = NULL;
    baru->next = NULL;

    if (head == NULL) {               // list kosong
        head = tail = baru;
    } else {
        tail->next = baru;            // sambungkan tail ke node baru
        baru->prev = tail;            // node baru prev ke tail
        tail = baru;                  // tail sekarang node baru
    }
}

int main() {
    tambahBelakang(10);
    tambahBelakang(20);
    tambahBelakang(30);

    bantu = head;
    printf("Isi list: ");
    while (bantu != NULL) {
        printf("|%d|->", bantu->angka);
        bantu = bantu->next;
    }
    printf("NULL\n");

    return 0;
}
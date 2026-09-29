#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;
    struct node *next;
} *head = NULL;   // head sebagai pointer global

int isEmpty() { // Fungsi mengecek apakah linked list kosong
    return head == NULL;
}

int main() {
    // head sudah otomatis NULL karena deklarasi global

    if (isEmpty()) {
        printf("Linked list kosong.\n");
    } else {
        printf("Linked list tidak kosong.\n");
    }
    return 0;
}
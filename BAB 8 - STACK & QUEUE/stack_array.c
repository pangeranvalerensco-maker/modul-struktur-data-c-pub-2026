#include <stdio.h>
#include <stdlib.h>

#define MAX 10          // kapasitas maksimum stack

int stack[MAX];         // array penyimpan data
int top = -1;           // top = -1 berarti kosong

int isEmpty() { // Mengecek apakah stack kosong
    return top == -1;   // jika top = -1, kosong (bernilai 1)
}

int isFull() { // Mengecek apakah stack penuh
    return top == MAX - 1; // jika top mencapai indeks terakhir array
}

void push(int data) { // Menambahkan data ke atas stack
    if (isFull()) {                         // cek apakah stack sudah penuh
        printf("Stack penuh! Tidak bisa push.\n");
        return;
    }
    top++;                                  // naikkan posisi top
    stack[top] = data;                      // simpan data di posisi top
    printf("Data %d berhasil ditambahkan.\n", data);
}

void pop() { // Menghapus elemen dari atas stack
    if (isEmpty()) { // cek apakah stack kosong
        printf("Stack kosong! Tidak bisa pop.\n");
        return;
    }
    int data = stack[top];    // ambil data teratas
    top--;                    // turunkan posisi top
    printf("Data %d dihapus dari stack.\n", data);
}

int peek() { // Melihat elemen teratas tanpa menghapusnya
    if (isEmpty()) {
        printf("Stack kosong!\n");
        return -1;
    }
    return stack[top]; // kembalikan nilai di top
}

void tampilkanStack() { // Menampilkan seluruh isi stack dari atas ke bawah
    if (isEmpty()) {
        printf("Stack kosong.\n");
        return;
    }
    printf("Stack (atas ke bawah): ");
    for (int i = top; i >= 0; i--) {        // loop dari atas ke bawah
        printf("|%d| ", stack[i]);
    }
    printf("\n");
}

int main() {
    int pilihan, data;
    do {
        printf("========== STACK DENGAN ARRAY ==========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Tampilkan\n");
        printf("5. Keluar\n");
        printf("========================================\n");
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
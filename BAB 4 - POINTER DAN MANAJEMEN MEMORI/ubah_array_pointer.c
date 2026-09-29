#include <stdio.h>

// Fungsi mengalikan semua elemen array dengan 2
// Parameter arr adalah pointer ke elemen pertama array
// Ukuran adalah jumlah elemen array
void kali_dua(int *arr, int ukuran) {
    for(int i = 0; i < ukuran; i++) {
        // arr[i] sama dengan *(arr + i)
        // Ini mengakses elemen ke-i secara langsung di memori
        arr[i] = arr[i] * 2;   // kalikan dua, lalu simpan kembali
    }
}

void main() {
    int data[4] = {1, 2, 3, 4};   // array biasa

    printf("Sebelum: ");
    for(int i = 0; i < 4; i++) {
        printf("%d ", data[i]);
    }

    // Jadi kita kirim alamat pertama ke fungsi
    kali_dua(data, 4);   // data = &data[0] adalah pointer ke elemen pertama

    printf("\nSesudah: ");
    for(int i = 0; i < 4; i++) {
        printf("%d ", data[i]);
    }
}
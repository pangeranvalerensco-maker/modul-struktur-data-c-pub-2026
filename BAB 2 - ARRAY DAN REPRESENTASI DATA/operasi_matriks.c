#include <stdio.h>

int main() {
    // Deklarasi matriks A dan B ukuran 2x2, serta matriks C untuk hasil
    int A[2][2] = {
        {1, 2},
        {3, 4}
    };
    int B[2][2] = {
        {5, 6},
        {7, 8}
    };
    int C[2][2];   // belum diisi

    // PENJUMLAHAN MATRIKS --- Loop baris (i) dan kolom (j)
    for(int i = 0; i < 2; i++) {        // i = indeks baris
        for(int j = 0; j < 2; j++) {    // j = indeks kolom
            C[i][j] = A[i][j] + B[i][j]; // Jumlahkan elemen yang posisinya sama
        }
    }

    // --- TAMPILKAN HASIL ---
    printf("Hasil penjumlahan matriks A + B:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", C[i][j]);   // cetak setiap elemen
        }
        printf("\n");  // pindah baris setelah satu baris selesai
    }

    return 0;
}
#include <stdio.h>

int main() {
    // Array 3D: 2 cabang, 3 produk, 4 bulan
    // Data penjualan (dalam unit barang)
    int penjualan[2][3][4] = {
        { // Cabang 0
            {10, 15, 20, 25},   // Produk 0, bulan 0..3
            {5, 8, 12, 18},     // Produk 1
            {7, 9, 14, 22}      // Produk 2
        },
        { // Cabang 1
            {12, 18, 24, 30},   // Produk 0
            {6, 10, 16, 20},    // Produk 1
            {8, 11, 17, 25}     // Produk 2
        }
    };

    // Hitung total penjualan per cabang
    for(int c = 0; c < 2; c++) {          // loop cabang
        int total_cabang = 0;
        for(int p = 0; p < 3; p++) {      // loop produk
            for(int b = 0; b < 4; b++) {  // loop bulan
                total_cabang += penjualan[c][p][b];
            }
        }
        printf("Total penjualan cabang %d: %d unit\n", c+1, total_cabang);
    }

    // Tampilkan penjualan produk 0 di cabang 0 per bulan
    printf("\nPenjualan produk 0 cabang 0 per bulan:\n");
    for(int b = 0; b < 4; b++) {
        printf("Bulan %d: %d unit\n", b+1, penjualan[0][0][b]);
    }

    return 0;
}
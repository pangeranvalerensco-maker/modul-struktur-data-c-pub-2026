#include <stdio.h>

int main() {
    int nilai[5] = {85, 90, 78, 73, 72};
    int ukuran = 5;
    int total = 0;
    float rata;

    // Menjumlahkan semua elemen
    for(int i = 0; i < ukuran; i++) {
        total += nilai[i];
    }

    // Menghitung rata-rata
    rata = (float)total / ukuran;

    printf("Jumlah: %d\n", total);
    printf("Rata-rata: %.2f\n", rata);

    return 0;
}
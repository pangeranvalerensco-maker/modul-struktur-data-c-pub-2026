#include <stdio.h>

int main() {
    int nilai[3] = {80, 85, 90};

    // Menampilkan nilai
    printf("Nilai siswa 1: %d\n", nilai[0]);
    printf("Nilai siswa 2: %d\n", nilai[1]);
    printf("Nilai siswa 3: %d\n", nilai[2]);

    // Mengubah nilai siswa ke-2
    nilai[1] = 100;
    printf("Setelah perbaikan, nilai siswa 2 menjadi: %d\n", nilai[1]);

    return 0;
}
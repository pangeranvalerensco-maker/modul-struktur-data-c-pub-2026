#include <stdio.h>

int main() {
    int nilai[3][2] = {{85, 90}, {78, 82}, {92, 88}};

    printf("Nilai siswa 0 (UTS): %d\n", nilai[0][0]);
    printf("Nilai siswa 0 (UAS): %d\n", nilai[0][1]);

    // Ubah nilai siswa 1 UAS menjadi 100
    nilai[1][1] = 100;
    printf("Nilai siswa 1 (UAS) setelah diubah: %d\n", nilai[1][1]);

    return 0;
}
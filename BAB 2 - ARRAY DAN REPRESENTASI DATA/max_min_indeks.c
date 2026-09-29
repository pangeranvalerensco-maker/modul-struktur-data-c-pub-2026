#include <stdio.h>

int main() {
    int nilai[5] = {85, 90, 78, 73, 72};
    int ukuran = 5;
    int max, min, idx_max, idx_min;

    max = min = nilai[0];
    idx_max = idx_min = 0;

    for(int i = 1; i < ukuran; i++) {
        if(nilai[i] > max) {
            max = nilai[i];
            idx_max = i;
        }
        if(nilai[i] < min) {
            min = nilai[i];
            idx_min = i;
        }
    }

    printf("Daftar nilai: ");
    for(int i = 0; i < ukuran; i++) printf("%d ", nilai[i]);
    printf("\nNilai terbesar: %d (indeks %d)\n", max, idx_max);
    printf("Nilai terkecil: %d (indeks %d)\n", min, idx_min);

    return 0;
}
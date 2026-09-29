#include <stdio.h>

int main() {
    int nilai[] = {85, 90, 78, 73, 72};
    // Hitung ukuran array otomatis
    int ukuran = sizeof(nilai) / sizeof(nilai[0]);
    int temp;

    // Tampilkan sebelum reverse
    printf("Sebelum reverse: \n");
    for(int i = 0; i < ukuran; i++) {
        printf("%d ", nilai[i]);
    }
    printf("\n");

    // Proses reverse
    for(int i = 0; i < ukuran/2; i++) {
        // Tukar nilai[i] dengan nilai[ukuran-1-i]
        temp = nilai[i];
        nilai[i] = nilai[ukuran - 1 - i];
        nilai[ukuran - 1 - i] = temp;
    }

    // Tampilkan setelah reverse
    printf("Setelah reverse: \n");
    for(int i = 0; i < ukuran; i++) {
        printf("%d ", nilai[i]);
    }
    printf("\n");

    return 0;
}
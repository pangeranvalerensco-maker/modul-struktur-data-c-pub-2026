#include <stdio.h>

int main() {
    int ukuran;
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &ukuran);

    int nilai[ukuran];  // array dengan ukuran dinamis (VLA)

    printf("Masukkan %d angka:\n", ukuran);
    for(int i = 0; i < ukuran; i++) {
        printf("Elemen ke-%d: ", i);
        scanf("%d", &nilai[i]);
    }

    // Reverse
    int temp;
    for(int i = 0; i < ukuran/2; i++) {
        temp = nilai[i];
        nilai[i] = nilai[ukuran - 1 - i];
        nilai[ukuran - 1 - i] = temp;
    }

    // Tampilkan hasil
    printf("\nArray setelah reverse: ");
    for(int i = 0; i < ukuran; i++) {
        printf("%d ", nilai[i]);
    }
    printf("\n");

    return 0;
}
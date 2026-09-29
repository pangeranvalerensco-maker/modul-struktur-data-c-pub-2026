#include <stdio.h>

int main() {
    int nilai[5] = {85, 90, 78, 73, 72};
    int temp;

    // Tampilkan array sebelum swap
    printf("Array sebelum swap:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", nilai[i]);
    }
    printf("\n");

    // Proses swap indeks 0 dan indeks 4
    temp = nilai[0];
    nilai[0] = nilai[4];
    nilai[4] = temp;

    // Tampilkan array setelah swap
    printf("Array setelah swap:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", nilai[i]);
    }
    printf("\n");

    return 0;
}
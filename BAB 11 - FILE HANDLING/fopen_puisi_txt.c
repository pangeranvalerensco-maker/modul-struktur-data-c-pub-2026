#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[100];
    FILE *fptr;

    fptr = fopen("puisi.txt", "r"); // 1. Buka file untuk dibaca

    if (fptr == NULL) { // 2. Cek apakah file berhasil dibuka
        printf("Error: File tidak ditemukan!\n");
        exit(1);
    }

    fgets(buffer, sizeof(buffer), fptr); // 3. Baca satu baris dari file
    printf("Baris pertama: %s", buffer);

    fclose(fptr); // 4. Tutup file

    return 0;
}

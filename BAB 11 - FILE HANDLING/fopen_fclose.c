#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    
    // Mencoba membuka file yang (mungkin) tidak ada
    fptr = fopen("data.txt", "r");

    // PENGECEKAN ERROR: Jika fptr == NULL, berarti file tidak ditemukan.
    if (fptr == NULL) {
        printf("Error: File 'data.txt' tidak ditemukan!\n");
        printf("Pastikan file ada di folder yang sama, atau nama filenya benar.\n");
        exit(1); // Hentikan program dengan kode error 1
    }

    printf("File berhasil dibuka.\n");

    // ... (baca atau proses file di sini) ...

    return 0;
}
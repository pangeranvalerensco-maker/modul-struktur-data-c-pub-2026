#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    int id;
    char nama[50];
    float ipk;

    fptr = fopen("data_mhs.txt", "r");
    if (fptr == NULL) {
        printf("File tidak ditemukan!\n");
        exit(1);
    }

    printf("--- DATA MAHASISWA ---\n");
    // %d: baca ID sampai bertemu '/', lalu lewati '/'
    // %[^/]: baca semua karakter sampai bertemu '/', aman dari spasi!
    // %f: baca IPK sampai bertemu baris baru (\n)
    while (fscanf(fptr, "%d/%[^/]/%f\n", &id, nama, &ipk) == 3) {
        printf("ID: %d | Nama: %s | IPK: %.2f\n", id, nama, ipk);
    }

    fclose(fptr);
    return 0;
}
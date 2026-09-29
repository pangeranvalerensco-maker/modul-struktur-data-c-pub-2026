#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    int id;
    char nama[50];
    float ipk;

    // Buka file data_mhs.txt (asumsikan file ini sudah ada)
    fptr = fopen("data_mhs.txt", "r");
    if (fptr == NULL) {
        printf("File tidak ditemukan!\n");
        exit(1);
    }

    printf("--- DATA MAHASISWA ---\n");
    // Baca data sesuai format: int, string, float
    while (fscanf(fptr, "%d %s %f", &id, nama, &ipk) != EOF) {
        printf("ID: %d | Nama: %s | IPK: %.2f\n", id, nama, ipk);
    }

    fclose(fptr);
    return 0;
}

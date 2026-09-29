#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    int id; char nama[50];
    float ipk; char buff[100];

    fptr = fopen("mahasiswa.txt", "a"); // --- BAGIAN MENULIS (APPEND) ---
    if (fptr == NULL) {
        printf("Gagal membuka file untuk menulis!\n");
        exit(1);
    }

    printf("--- INPUT DATA MAHASISWA ---\n");
    printf("ID: "); scanf("%d", &id);
    printf("Nama: "); scanf("%s", nama);
    printf("IPK: "); scanf("%f", &ipk);

    // Tulis data ke file dengan format yang rapi (ada \n)
    fprintf(fptr, "%d %s %.2f\n", id, nama, ipk);
    fclose(fptr);
    printf("Data berhasil disimpan.\n\n");

    fptr = fopen("mahasiswa.txt", "r"); // --- BAGIAN MEMBACA (READ) ---
    if (fptr == NULL) {
        printf("File belum ada atau gagal dibuka!\n");
        exit(1);
    }

    printf("--- DATA MAHASISWA SAAT INI ---\n");
    // Membaca seluruh data dengan loop while(fscanf(...) != EOF)
    while (fscanf(fptr, "%d %s %f", &id, nama, &ipk) != EOF) {
        printf("ID: %d | Nama: %s | IPK: %.2f\n", id, nama, ipk);
    }

    fclose(fptr);
    return 0;
}
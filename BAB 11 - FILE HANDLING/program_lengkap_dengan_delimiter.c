#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Untuk strcspn

int main() {
    FILE *fptr;
    int id;
    char nama[100];
    float ipk;

    fptr = fopen("data_mhs.txt", "a"); // --- BAGIAN MENULIS (CREATE) ---
    if (fptr == NULL) {
        printf("Gagal membuka file untuk menulis!\n");
        exit(1);
    }

    printf("--- INPUT DATA MAHASISWA ---\n");
    printf("ID: "); scanf("%d", &id);
    
    // Trik: " %[^\n]" membaca nama lengkap dengan spasi dari keyboard
    printf("Nama Lengkap: "); scanf(" %[^\n]", nama); 
    
    printf("IPK: "); scanf("%f", &ipk);

    // Simpan ke file dengan delimiter '/'
    fprintf(fptr, "%d/%s/%.2f\n", id, nama, ipk);
    fclose(fptr);
    printf("Data berhasil disimpan.\n\n");

    fptr = fopen("data_mhs.txt", "r"); // --- BAGIAN MEMBACA (READ) ---
    if (fptr == NULL) {
        printf("Belum ada data mahasiswa.\n");
        exit(1);
    }

    printf("--- DATA MAHASISWA SAAT INI ---\n");
    // Baca data dengan fscanf dan delimiter '/'. 
    // Kembalikan nilai 3 jika berhasil membaca 3 data.
    while (fscanf(fptr, "%d/%[^/]/%f\n", &id, nama, &ipk) == 3) {
        printf("ID: %d | Nama: %s | IPK: %.2f\n", id, nama, ipk);
    }
    fclose(fptr);

    return 0;
}
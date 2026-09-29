#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fptr;
    int id;
    char nama[50];
    float ipk;

    // Buka file dengan mode "a" (append - menambah di akhir)
    fptr = fopen("data_mhs.txt", "a");
    if (fptr == NULL) {
        printf("Gagal membuka file!\n");
        exit(1);
    }

    printf("Masukkan ID: "); scanf("%d", &id); getchar(); 
    printf("Masukkan Nama: "); fgets(nama, sizeof(nama), stdin); 
    nama[strcspn(nama, "\n")] = 0; 
    printf("Masukkan IPK: "); scanf("%f", &ipk);

    // Tulis data ke file dengan format yang sama
    fprintf(fptr, "%d %s %.2f\n", id, nama, ipk);

    fclose(fptr);
    printf("Data berhasil ditambahkan.\n");
    return 0;
}

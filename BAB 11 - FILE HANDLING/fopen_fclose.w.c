#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    
    // 1. Buka file dengan mode "w" (Write).
    // Jika file belum ada, ini akan membuat file baru bernama mahasiswa.txt
    fptr = fopen("mahasiswa.txt", "w");

    if (fptr == NULL) {
        printf("Gagal membuat file!\n");
        exit(1);
    }

    // 2. Tulis data ke file menggunakan fprintf
    // Perhatikan: kita menambahkan \n di akhir setiap baris, agar data menjadi rapi per baris
    fprintf(fptr, "1 Andi 3.75\n");
    fprintf(fptr, "2 Budi 3.50\n");
    fprintf(fptr, "3 Citra 3.90\n");

    // 3. Tutup file agar data benar-benar tersimpan ke hard disk
    fclose(fptr);

    printf("File berhasil dibuat dan diisi!\n");
    return 0;
}
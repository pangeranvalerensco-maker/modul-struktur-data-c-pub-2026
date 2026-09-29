#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    
    // 1. Buka file dengan mode "a" (Append). File lama tetap aman.
    fptr = fopen("mahasiswa.txt", "a");

    if (fptr == NULL) {
        printf("Gagal membuka file!\n");
        exit(1);
    }

    // 2. Data baru ditulis di bagian paling akhir
    fprintf(fptr, "4 Dedi 4.00\n");

    fclose(fptr);
    printf("Data baru berhasil ditambahkan!\n");
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     char buff[100];
//     FILE *fptr;

//     fptr = fopen("puisi.txt", "r");
//     if (fptr == NULL) {
//         printf("File tidak ditemukan!\n");
//         exit(1);
//     }

//     // Baca satu baris file, simpan ke buff
//     fgets(buff, sizeof(buff), fptr);
    
//     printf("Isi baris pertama: %s", buff);
//     fclose(fptr);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     char buff[100];
//     FILE *fptr;

//     fptr = fopen("puisi.txt", "r");
//     if (fptr == NULL) {
//         printf("File tidak ditemukan!\n");
//         exit(1);
//     }

//     // Selama fgets() masih bisa membaca baris (belum EOF), loop terus berjalan
//     while (fgets(buff, sizeof(buff), fptr) != NULL) {
//         printf("%s", buff); // Cetak baris yang baru saja dibaca
//     }

//     fclose(fptr);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fptr;
    char teks[100];

    // Buka file dengan mode "w" (Write - akan menghapus isi lama)
    fptr = fopen("catatan.txt", "w");
    if (fptr == NULL) {
        printf("Gagal membuat file!\n");
        exit(1);
    }

    printf("Masukkan teks yang ingin disimpan: ");
    fgets(teks, sizeof(teks), stdin);
    teks[strcspn(teks, "\n")] = 0; // Hapus

    // Tulis input user ke file
    fputs(teks, fptr);

    fclose(fptr);
    printf("Data berhasil disimpan.\n");
    return 0;
}

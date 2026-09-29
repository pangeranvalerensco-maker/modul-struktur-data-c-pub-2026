#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[10];
    char nama[50];
    int umur;
    float ipk;
} Mahasiswa;

int main() {
    Mahasiswa daftarMhs[3];

    // Mengisi data mahasiswa pertama
    strcpy(daftarMhs[0].nim, "A001");
    strcpy(daftarMhs[0].nama, "Andi");
    daftarMhs[0].umur = 20;
    daftarMhs[0].ipk = 3.75;

    // Mengisi data mahasiswa kedua
    strcpy(daftarMhs[1].nim, "A002");
    strcpy(daftarMhs[1].nama, "Budi");
    daftarMhs[1].umur = 21;
    daftarMhs[1].ipk = 3.50;

    // Mengisi data mahasiswa ketiga
    strcpy(daftarMhs[2].nim, "A003");
    strcpy(daftarMhs[2].nama, "Citra");
    daftarMhs[2].umur = 19;
    daftarMhs[2].ipk = 3.90;

    // Menampilkan data mahasiswa pertama
    printf("Data Mahasiswa 1:\n");
    printf("  NIM  : %s\n", daftarMhs[0].nim);
    printf("  Nama : %s\n", daftarMhs[0].nama);
    printf("  Umur : %d\n", daftarMhs[0].umur);
    printf("  IPK  : %.2f\n", daftarMhs[0].ipk);

    return 0;
}
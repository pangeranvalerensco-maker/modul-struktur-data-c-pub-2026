#include <stdio.h>
#include <string.h>

// Definisi struct dengan typedef
typedef struct {
    char nim[10];
    char nama[50];
    int umur;
    float ipk;
} Mahasiswa;

int main() {
    // Deklarasi variabel struct tanpa inisialisasi
    Mahasiswa mhs1;

    // Mengisi nilai anggota (satu per satu)
    strcpy(mhs1.nim, "A001");
    strcpy(mhs1.nama, "Andi");
    mhs1.umur = 20;
    mhs1.ipk = 3.75;

    // Menampilkan data
    printf("NIM  : %s\n", mhs1.nim);
    printf("Nama : %s\n", mhs1.nama);
    printf("Umur : %d\n", mhs1.umur);
    printf("IPK  : %.2f\n", mhs1.ipk);

    return 0;
}

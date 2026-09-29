#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[10];
    char nama[50];
    int umur;
    float ipk;
} Mahasiswa;

int main() {
    // Inisialisasi berurutan
    Mahasiswa mhs1 = {"A001", "Andi", 20, 3.75};

    // Menampilkan data
    printf("NIM  : %s\n", mhs1.nim);
    printf("Nama : %s\n", mhs1.nama);
    printf("Umur : %d\n", mhs1.umur);
    printf("IPK  : %.2f\n", mhs1.ipk);

    return 0;
}

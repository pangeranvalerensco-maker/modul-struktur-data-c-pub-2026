#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[10];
    char nama[50];
    int umur;
    float ipk;
} Mahasiswa;

int main() {
    // Designated initializer
    Mahasiswa mhs1 = {
        .nim = "A001",
        .nama = "Andi",
        .umur = 20,
        .ipk = 3.75
    };

    // Bisa diurutkan tidak sesuai urutan struct
    Mahasiswa mhs2 = {
        .ipk = 3.90,
        .nama = "Citra",
        .umur = 19,
        .nim = "A003"
    };

    printf("=== MAHASISWA 1 ===\n");
    printf("NIM  : %s\n", mhs1.nim);
    printf("Nama : %s\n", mhs1.nama);
    printf("Umur : %d\n", mhs1.umur);
    printf("IPK  : %.2f\n\n", mhs1.ipk);

    printf("=== MAHASISWA 2 ===\n");
    printf("NIM  : %s\n", mhs2.nim);
    printf("Nama : %s\n", mhs2.nama);
    printf("Umur : %d\n", mhs2.umur);
    printf("IPK  : %.2f\n", mhs2.ipk);

    return 0;
}

typedef struct {
    char nim[10];
    char nama[50];
    int umur;
    float ipk;
    char jurusan[30];   // anggota baru
} Mahasiswa;
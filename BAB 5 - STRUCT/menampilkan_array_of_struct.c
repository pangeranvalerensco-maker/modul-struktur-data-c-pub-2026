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

    // Mengisi data
    strcpy(daftarMhs[0].nim, "A001");
    strcpy(daftarMhs[0].nama, "Andi");
    daftarMhs[0].umur = 20;
    daftarMhs[0].ipk = 3.75;

    strcpy(daftarMhs[1].nim, "A002");
    strcpy(daftarMhs[1].nama, "Budi");
    daftarMhs[1].umur = 21;
    daftarMhs[1].ipk = 3.50;

    strcpy(daftarMhs[2].nim, "A003");
    strcpy(daftarMhs[2].nama, "Citra");
    daftarMhs[2].umur = 19;
    daftarMhs[2].ipk = 3.90;

    // Menampilkan semua data dengan perulangan
    printf("=== DATA MAHASISWA ===\n");
    for(int i = 0; i < 3; i++) {
        printf("Mahasiswa ke-%d:\n", i+1);
        printf("  NIM  : %s\n", daftarMhs[i].nim);
        printf("  Nama : %s\n", daftarMhs[i].nama);
        printf("  Umur : %d\n", daftarMhs[i].umur);
        printf("  IPK  : %.2f\n", daftarMhs[i].ipk);
        printf("\n");
    }

    return 0;
}

Mahasiswa daftarMhs[3] = {
    {.nim = "A001", .nama = "Andi", .umur = 20, .ipk = 3.75},
    {.nim = "A002", .nama = "Budi", .umur = 21, .ipk = 3.50},
    {.nim = "A003", .nama = "Citra", .umur = 19, .ipk = 3.90}
};

typedef struct {
    char nim[10];
    char nama[50];
    int umur;
    float ipk;
    char jalan[100];
    char kota[50];
    char provinsi[50];
    int kodePos;
} Mahasiswa;
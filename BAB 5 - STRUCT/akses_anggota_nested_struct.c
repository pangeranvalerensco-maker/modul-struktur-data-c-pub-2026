#include <stdio.h>
#include <string.h>

typedef struct {
    char jalan[100];
    char kota[50];
    char provinsi[50];
    int kodePos;
} Alamat;

typedef struct {
    char nim[10];
    char nama[50];
    int umur;
    float ipk;
    Alamat alamat;   // nested struct
} Mahasiswa;

int main() {
    Mahasiswa mhs1;

    // Mengisi data Mahasiswa
    strcpy(mhs1.nim, "A001");
    strcpy(mhs1.nama, "Andi");
    mhs1.umur = 20;
    mhs1.ipk = 3.75;

    // Mengisi nested struct (alamat)
    strcpy(mhs1.alamat.jalan, "Jl. Merdeka No. 10");
    strcpy(mhs1.alamat.kota, "Bandung");
    strcpy(mhs1.alamat.provinsi, "Jawa Barat");
    mhs1.alamat.kodePos = 40112;

    // Menampilkan data
    printf("=== DATA MAHASISWA ===\n");
    printf("NIM      : %s\n", mhs1.nim);
    printf("Nama     : %s\n", mhs1.nama);
    printf("Umur     : %d\n", mhs1.umur);
    printf("IPK      : %.2f\n", mhs1.ipk);
    printf("\n--- ALAMAT ---\n");
    printf("Jalan    : %s\n", mhs1.alamat.jalan);
    printf("Kota     : %s\n", mhs1.alamat.kota);
    printf("Provinsi : %s\n", mhs1.alamat.provinsi);
    printf("Kode Pos : %d\n", mhs1.alamat.kodePos);

    return 0;
}

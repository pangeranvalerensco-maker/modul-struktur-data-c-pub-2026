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
    Alamat alamat;
} Mahasiswa;

int main() {
    Mahasiswa daftarMhs[2] = { // Array of struct dengan nested struct
        {
            .nim = "A001",
            .nama = "Andi",
            .umur = 20,
            .ipk = 3.75,
            .alamat = {
                .jalan = "Jl. Merdeka No. 10",
                .kota = "Bandung",
                .provinsi = "Jawa Barat",
                .kodePos = 40112
            }
        },
        {
            .nim = "A002",
            .nama = "Budi",
            .umur = 21,
            .ipk = 3.50,
            .alamat = {
                .jalan = "Jl. Asia No. 20",
                .kota = "Jakarta",
                .provinsi = "DKI Jakarta",
                .kodePos = 10110
            }
        }
    };

    for(int i = 0; i < 2; i++) { // Menampilkan data
        printf("Mahasiswa ke-%d:\n", i+1);
        printf("  NIM      : %s\n", daftarMhs[i].nim);
        printf("  Nama     : %s\n", daftarMhs[i].nama);
        printf("  Umur     : %d\n", daftarMhs[i].umur);
        printf("  IPK      : %.2f\n", daftarMhs[i].ipk);
        printf("  Alamat   : %s, %s, %s - %d\n",
               daftarMhs[i].alamat.jalan,
               daftarMhs[i].alamat.kota,
               daftarMhs[i].alamat.provinsi,
               daftarMhs[i].alamat.kodePos);
        printf("\n");
    }

    return 0;
}
#include <stdio.h>

typedef struct {
    char nim[10];
    char nama[50];
    int umur;
    float ipk;
} Mahasiswa;

int main() {
    // Array of struct dengan inisialisasi designated
    Mahasiswa daftarMhs[3] = {
        {.nim = "A001", .nama = "Andi", .umur = 20, .ipk = 3.75},
        {.nim = "A002", .nama = "Budi", .umur = 21, .ipk = 3.50},
        {.nim = "A003", .nama = "Citra", .umur = 19, .ipk = 3.90}
    };

    // Menampilkan semua data
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
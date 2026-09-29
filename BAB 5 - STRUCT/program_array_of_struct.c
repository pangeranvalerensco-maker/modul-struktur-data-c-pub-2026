#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[13];
    char nama[50];
    int umur;
    float ipk;
} Mahasiswa;

int main() {
    int jumlah;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jumlah);
    getchar(); // membersihkan newline

    Mahasiswa daftarMhs[jumlah]; // Membuat array of struct dengan ukuran sesuai input

    for(int i = 0; i < jumlah; i++) { // Input data mahasiswa
        printf("\nMahasiswa ke-%d:\n", i+1);
        printf("  NIM  : ");
        fgets(daftarMhs[i].nim, sizeof(daftarMhs[i].nim), stdin);
        daftarMhs[i].nim[strcspn(daftarMhs[i].nim, "\n")] = '\0'; // hapus newline

        printf("  Nama : ");
        fgets(daftarMhs[i].nama, sizeof(daftarMhs[i].nama), stdin);
        daftarMhs[i].nama[strcspn(daftarMhs[i].nama, "\n")] = '\0';

        printf("  Umur : ");
        scanf("%d", &daftarMhs[i].umur);
        getchar(); // membersihkan newline

        printf("  IPK  : ");
        scanf("%f", &daftarMhs[i].ipk);
        getchar(); // membersihkan newline
    }

    printf("\n=== DATA MAHASISWA ===\n"); // Menampilkan semua data
    for(int i = 0; i < jumlah; i++) {
        printf("Mahasiswa ke-%d:\n", i+1);
        printf("  NIM  : %s\n", daftarMhs[i].nim);
        printf("  Nama : %s\n", daftarMhs[i].nama);
        printf("  Umur : %d\n", daftarMhs[i].umur);
        printf("  IPK  : %.2f\n", daftarMhs[i].ipk);
        printf("\n");
    }

    return 0;
}
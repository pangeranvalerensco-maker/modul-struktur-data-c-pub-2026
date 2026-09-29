#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[10];
    char nama[50];
    int umur;
    float ipk;
} Mahasiswa;

// Fungsi menerima struct (pass by value)
void tampilkanMahasiswa(Mahasiswa m) {
    printf("NIM  : %s\n", m.nim);
    printf("Nama : %s\n", m.nama);
    printf("Umur : %d\n", m.umur);
    printf("IPK  : %.2f\n", m.ipk);
}

void main() {
    Mahasiswa mhs1 = {"A001", "Andi", 20, 3.75};

    // Mengirim salinan struct ke fungsi
    tampilkanMahasiswa(mhs1);
}
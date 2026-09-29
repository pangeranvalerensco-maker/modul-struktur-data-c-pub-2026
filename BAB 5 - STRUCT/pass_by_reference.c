#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[10];
    char nama[50];
    int umur;
    float ipk;
} Mahasiswa;

// Fungsi menerima pointer ke struct (pass by reference)
void tampilkanMahasiswa(Mahasiswa *m) {
    printf("NIM  : %s\n", m->nim);
    printf("Nama : %s\n", m->nama);
    printf("Umur : %d\n", m->umur);
    printf("IPK  : %.2f\n", m->ipk);
}

// Fungsi mengubah IPK (mengubah data asli)
void ubahIPK(Mahasiswa *m, float ipkBaru) {
    m->ipk = ipkBaru;   // mengubah data asli
}

void main() {
    Mahasiswa mhs1 = {"A001", "Andi", 20, 3.75};

    printf("Sebelum diubah:\n");
    tampilkanMahasiswa(&mhs1);   // kirim alamat

    ubahIPK(&mhs1, 3.90);        // kirim alamat

    printf("\nSetelah diubah:\n");
    tampilkanMahasiswa(&mhs1);
}

typedef struct {
    char nama[50];
    int umur;
} Mahasiswa;

int main() {
    Mahasiswa mhs1;
    mhs1.nama = "Andi"; // Apakah ini valid?
    mhs1.umur = 20;
}

#include <stdio.h>
#include <string.h>

// 1. Mendefinisikan struct Mahasiswa dengan typedef
typedef struct {
    char nim[10];     // anggota: NIM (string)
    char nama[50];    // anggota: Nama (string)
    int umur;         // anggota: Umur (integer)
    float ipk;        // anggota: IPK (float)
} Mahasiswa;

int main() {
    // 2. Mendeklarasikan variabel struct mhs1
    Mahasiswa mhs1;

    // 3. Mengisi nilai anggota-anggota mhs1
    strcpy(mhs1.nim, "A001");          // isi nim dengan "A001"
    strcpy(mhs1.nama, "Andi");         // isi nama dengan "Andi"
    mhs1.umur = 20;                    // isi umur dengan 20
    mhs1.ipk = 3.75;                   // isi ipk dengan 3.75

    // 4. Menampilkan data mahasiswa
    printf("=== DATA MAHASISWA ===\n");
    printf("NIM  : %s\n", mhs1.nim);
    printf("Nama : %s\n", mhs1.nama);
    printf("Umur : %d\n", mhs1.umur);
    printf("IPK  : %.2f\n", mhs1.ipk);

    // 5. Mengubah salah satu nilai (misal IPK)
    mhs1.ipk = 3.90;                   // ubah ipk menjadi 3.90

    // 6. Menampilkan data setelah perubahan
    printf("\n=== SETELAH PERUBAHAN ===\n");
    printf("IPK baru : %.2f\n", mhs1.ipk);

    return 0;
}

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
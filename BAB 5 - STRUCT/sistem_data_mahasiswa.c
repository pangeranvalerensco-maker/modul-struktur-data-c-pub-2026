#include <stdio.h>
#include <string.h>

typedef struct {
    char jalan[100];
    char kota[50];
    char provinsi[50];
    int kodePos;
} Alamat;

typedef struct { // Struct Mahasiswa (dengan nested struct Alamat)
    char nim[10];
    char nama[50];
    int umur;
    float ipk;
    Alamat alamat;      // nested struct
} Mahasiswa;

void tampilkanMahasiswa(Mahasiswa *m) { // Fungsi untuk menampilkan data satu mahasiswa
    printf("NIM      : %s\n", m->nim);
    printf("Nama     : %s\n", m->nama);
    printf("Umur     : %d\n", m->umur);
    printf("IPK      : %.2f\n", m->ipk);
    printf("Alamat   : %s, %s, %s - %d\n",
           m->alamat.jalan,
           m->alamat.kota,
           m->alamat.provinsi,
           m->alamat.kodePos);
    printf("------------------------\n");
}

// Fungsi untuk menampilkan semua mahasiswa dalam array
void tampilkanSemuaMahasiswa(Mahasiswa *daftar, int jumlah) {
    printf("\n=== DATA MAHASISWA ===\n");
    for(int i = 0; i < jumlah; i++) {
        printf("Mahasiswa ke-%d:\n", i+1);
        tampilkanMahasiswa(&daftar[i]);  // kirim alamat elemen ke-i
    }
}

// Fungsi untuk mencari mahasiswa dengan IPK tertinggi
// Mengembalikan pointer ke mahasiswa dengan IPK tertinggi
Mahasiswa* cariIPKTertinggi(Mahasiswa *daftar, int jumlah) {
    if(jumlah <= 0) return NULL;

    Mahasiswa *tertinggi = &daftar[0];   // asumsikan elemen pertama tertinggi
    for(int i = 1; i < jumlah; i++) {
        if(daftar[i].ipk > tertinggi->ipk) {
            tertinggi = &daftar[i];
        }
    }
    return tertinggi;
}

void ubahIPK(Mahasiswa *m, float ipkBaru) { // Fungsi untuk mengubah IPK mahasiswa
    m->ipk = ipkBaru;
}

// Fungsi untuk menghitung rata-rata IPK semua mahasiswa
float hitungRataIPK(Mahasiswa *daftar, int jumlah) {
    if(jumlah <= 0) return 0.0;

    float total = 0;
    for(int i = 0; i < jumlah; i++) {
        total += daftar[i].ipk;
    }
    return total / jumlah;
}
int main() {
    // Inisialisasi array of struct dengan nested struct
    Mahasiswa daftarMhs[4] = {
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
        },
        {
            .nim = "A003",
            .nama = "Citra",
            .umur = 19,
            .ipk = 3.90,
            .alamat = {
                .jalan = "Jl. Diponegoro No. 5",
                .kota = "Surabaya",
                .provinsi = "Jawa Timur",
                .kodePos = 60111
            }
        },
        {
            .nim = "A004",
            .nama = "Dewi",
            .umur = 22,
            .ipk = 3.60,
            .alamat = {
                .jalan = "Jl. Sudirman No. 8",
                .kota = "Yogyakarta",
                .provinsi = "DIY Yogyakarta",
                .kodePos = 55222
            }
        }
    };

    int jumlah = 4;

    // TAMPILKAN SEMUA DATA
    tampilkanSemuaMahasiswa(daftarMhs, jumlah);

    // CARI IPK TERTINGGI
    Mahasiswa *tertinggi = cariIPKTertinggi(daftarMhs, jumlah);
    if(tertinggi != NULL) {
        printf("\n=== MAHASISWA DENGAN IPK TERTINGGI ===\n");
        tampilkanMahasiswa(tertinggi);
    }

    // HITUNG RATA-RATA IPK
    float rata = hitungRataIPK(daftarMhs, jumlah);
    printf("\nRata-rata IPK semua mahasiswa: %.2f\n", rata);

    // UBAH IPK MAHASISWA (melalui pointer)
    printf("\n=== MENGUBAH IPK ANDI ===\n");
    printf("IPK Andi sebelum diubah: %.2f\n", daftarMhs[0].ipk);
    ubahIPK(&daftarMhs[0], 3.95);   // kirim alamat mahasiswa pertama
    printf("IPK Andi setelah diubah : %.2f\n", daftarMhs[0].ipk);

    // TAMPILKAN ULANG DATA
    printf("\n=== DATA SETELAH PERUBAHAN ===\n");
    tampilkanSemuaMahasiswa(daftarMhs, jumlah);
}


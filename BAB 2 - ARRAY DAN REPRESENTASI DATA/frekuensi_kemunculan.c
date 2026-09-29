#include <stdio.h>

int main() {
    // Data nilai ujian (bisa juga diisi dari input user)
    int nilai[] = {85, 90, 78, 85, 90, 78, 85, 100, 90, 78};
    
    // Hitung jumlah elemen array secara otomatis
    int ukuran = sizeof(nilai) / sizeof(nilai[0]); 

    int frekuensi[101] = {0}; // Inisialisasi semua elemen dengan 0

    // --- HITUNG FREKUENSI ---
    // Loop semua data nilai
    for(int i = 0; i < ukuran; i++) {
        // Ambil nilai siswa ke-i, lalu naikkan counter di indeks tersebut
        int angka = nilai[i];
        frekuensi[angka]++;   // contoh: nilai 85 -> frekuensi[85] bertambah 1
    }

    // --- TAMPILKAN HASIL (hanya nilai yang muncul) ---
    printf("Frekuensi kemunculan nilai:\n");
    for(int i = 0; i <= 100; i++) {
        if(frekuensi[i] > 0) {
            printf("Nilai %d muncul %d kali\n", i, frekuensi[i]);
        }
    }

    return 0;
}
#include <stdio.h>

int main() {
    // Deklarasi dan inisialisasi array 2D: 3 baris (siswa), 2 kolom (UTS, UAS)
    int nilai[3][2] = {
        {85, 90},
        {78, 82},
        {92, 88}
    };
    
    // Menampilkan header tabel
    printf("Siswa\tUTS\tUAS\tRata-rata\n");
    printf("--------------------------------\n");
    
    // Perulangan untuk setiap siswa
    for(int i = 0; i < 3; i++) {
        int uts = nilai[i][0]; // menyimpan nilai UTS untuk siswa ke-i kolom 0
        int uas = nilai[i][1]; // menyimpan nilai UAS untuk siswa ke-i kolom 1
        float rata = (uts + uas) / 2.0;   // rata-rata UTS dan UAS
        
        printf("Siswa %d\t%d\t%d\t%.2f\n", i+1, uts, uas, rata);
    }
    
    // Hitung rata-rata kelas untuk UTS dan UAS
    int total_uts = 0, total_uas = 0;
    for(int i = 0; i < 3; i++) {
        total_uts += nilai[i][0]; // jumlahkan nilai UTS untuk semua siswa
        total_uas += nilai[i][1]; // jumlahkan nilai UAS untuk semua siswa
    }
    float rata_uts = total_uts / 3.0; // rata-rata UTS kelas
    float rata_uas = total_uas / 3.0; // rata-rata UAS kelas
    
    printf("\nRata-rata kelas UTS: %.2f\n", rata_uts);
    printf("Rata-rata kelas UAS: %.2f\n", rata_uas);
    
    return 0;
}
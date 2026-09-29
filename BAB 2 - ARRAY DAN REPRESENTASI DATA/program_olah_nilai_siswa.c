#include <stdio.h>

int main() {
    int nilai[5];       // Deklarasi array 1D untuk menyimpan 5 nilai siswa
    int total = 0;      // variabel untuk menjumlah semua nilai
    int max, min;       // nanti diisi nilai tertinggi & terendah

    printf("Masukkan 5 nilai siswa:\n");
    for(int i = 0; i < 5; i++) {
        // i dimulai dari 0, tapi user lebih familiar dengan "Siswa 1"
        printf("Siswa %d: ", i + 1);
        scanf("%d", &nilai[i]);   // simpan nilai ke array indeks i
        total = total + nilai[i]; // tambahkan ke total (bisa pakai total += nilai[i])
    }

    // Asumsikan sementara nilai pertama adalah yang tertinggi dan terendah
    max = nilai[0];
    min = nilai[0];

    // Bandingkan dengan elemen ke-1 sampai ke-4 (indeks 1..4)
    for(int i = 1; i < 5; i++) {
        if(nilai[i] > max) {
            max = nilai[i];   // jika lebih besar, perbarui max
        }
        if(nilai[i] < min) {
            min = nilai[i];   // jika lebih kecil, perbarui min
        }
    }

    printf("\n=== HASIL ===\n");
    printf("Total nilai   : %d\n", total);
    printf("Rata-rata     : %.2f\n", (float)total / 5); // casting ke float agar hasil pecahan
    printf("Nilai tertinggi: %d\n", max);
    printf("Nilai terendah : %d\n", min);

    return 0;
}
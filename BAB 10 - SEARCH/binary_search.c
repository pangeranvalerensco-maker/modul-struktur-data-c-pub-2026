#include <stdio.h>

// Fungsi Binary Search (Iteratif)
// Hanya bisa dipanggil jika data[] sudah terurut ascending
int cariBiner(int data[], int n, int target) {
    int kiri = 0;
    int kanan = n - 1;

    while (kiri <= kanan) { // Hitung posisi tengah. 
        // Rumus ini lebih aman daripada (kiri+kanan)/2 untuk data sangat besar (mencegah overflow)
        int tengah = kiri + (kanan - kiri) / 2;

        if (data[tengah] == target) {
            return tengah; // Ditemukan
        } else if (data[tengah] < target) {
            kiri = tengah + 1; // Cari di sisi kanan
        } else {
            kanan = tengah - 1; // Cari di sisi kiri
        }
    }
    return -1; // Tidak ditemukan
}

void main() {
    int data[] = {2, 3, 5, 8, 9, 11, 15, 20}; // Data HARUS terurut ascending!
    int n = sizeof(data) / sizeof(data[0]);
    int target = 11;

    int hasil = cariBiner(data, n, target);

    if (hasil != -1) {
        printf("Data %d ditemukan pada indeks ke-%d.\n", target, hasil);
    } else {
        printf("Data %d tidak ditemukan dalam array.\n", target);
    }
}

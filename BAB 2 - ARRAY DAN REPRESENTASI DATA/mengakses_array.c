#include <stdio.h>

int main() {
    // Array nilai dengan 5 elemen
    int nilai_siswa[5] = {80, 85, 90, 75, 95};

    // Menampilkan header
    printf("Daftar nilai siswa:\n");

    // Perulangan for: i mulai dari 0, 
    // selama i < 5, i bertambah 1 setiap kali
    for(int i = 0; i < 5; i++) {
        // i akan bernilai 0,1,2,3,4 secara berurutan
        // nilai_siswa[i] akan mengambil elemen ke-0, ke-1, dst.
        printf("Nilai indeks ke-%d: %d\n", i, nilai_siswa[i]);
    }

    return 0;
}
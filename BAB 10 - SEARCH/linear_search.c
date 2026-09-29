#include <stdio.h>

// Fungsi Linear Search
// Mengembalikan indeks jika data ditemukan, atau -1 jika tidak ditemukan
int cariLinear(int data[], int n, int target) {
    // Loop dari indeks 0 sampai n-1
    for (int i = 0; i < n; i++) {
        // Jika data pada indeks saat ini sama dengan target
        if (data[i] == target) {
            return i; // Kembalikan indeksnya
        }
    }
    return -1; // Jika loop selesai dan tidak ketemu, kembalikan -1
}

void main() {
    int data[] = {5, 2, 8, 1, 9, 3};
    int n = sizeof(data) / sizeof(data[0]);
    int target = 8;

    int hasil = cariLinear(data, n, target);

    if (hasil != -1) {
        printf("Data %d ditemukan pada indeks ke-%d.\n", target, hasil);
    } else {
        printf("Data %d tidak ditemukan dalam array.\n", target);
    }
}

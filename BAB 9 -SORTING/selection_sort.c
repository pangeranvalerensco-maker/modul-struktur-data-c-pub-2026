#include <stdio.h>

// Fungsi Selection Sort ascending (kecil → besar)
void selectionSortAsc(int data[], int n) {
    // Loop luar: menentukan posisi yang akan diisi (n-1 kali)
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;  // anggap elemen pertama dari sisa array adalah terkecil

        for (int j = i + 1; j < n; j++) { // Cari elemen terkecil dari sisa array
            if (data[j] < data[minIdx]) {
                minIdx = j;
            }
        }

        if (minIdx != i) { // Jika ditemukan elemen yang lebih kecil, tukar
            int temp = data[i];
            data[i] = data[minIdx];
            data[minIdx] = temp;
        }
    }
}

// Fungsi Selection Sort descending (besar → kecil)
void selectionSortDesc(int data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;  // anggap elemen pertama dari sisa array adalah terbesar

        for (int j = i + 1; j < n; j++) { // Cari elemen terbesar dari sisa array
            if (data[j] > data[maxIdx]) {
                maxIdx = j;
            }
        }

        if (maxIdx != i) {
            int temp = data[i];
            data[i] = data[maxIdx];
            data[maxIdx] = temp;
        }
    }
}

void cetakArray(int data[], int n) { // Fungsi mencetak array
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {85, 70, 90, 60, 80, 75};
    int n = sizeof(data) / sizeof(data[0]);

    printf("OUTPUT: \n");
    printf("Sebelum sorting : ");
    cetakArray(data, n);

    selectionSortAsc(data, n);
    printf("Setelah ascending : ");
    cetakArray(data, n);

    int data2[] = {85, 70, 90, 60, 80, 75}; // Reset data untuk contoh descending
    selectionSortDesc(data2, n);
    printf("Setelah descending: ");
    cetakArray(data2, n);

    return 0;
}
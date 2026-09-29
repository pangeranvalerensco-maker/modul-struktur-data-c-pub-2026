#include <stdio.h>

// Fungsi untuk menukar dua elemen
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Lomuto partition: pivot = elemen terakhir
int partitionLomuto(int data[], int kiri, int kanan) {
    int pivot = data[kanan];  // pivot di elemen terakhir
    int i = kiri - 1;         // indeks batas elemen kecil (awal -1)


    for (int j = kiri; j < kanan; j++) {
        // Jika elemen saat ini <= pivot, pindahkan ke sisi kiri
        if (data[j] <= pivot) {
            i++;
            swap(&data[i], &data[j]);
        }
    }

    // Tempatkan pivot di posisi yang benar (setelah elemen <= pivot)
    swap(&data[i + 1], &data[kanan]);
    return i + 1;  // kembalikan posisi pivot
}

// Fungsi Quick Sort rekursif
void quickSortLomuto(int data[], int kiri, int kanan) {
    if (kiri < kanan) {
        int pivotIndex = partitionLomuto(data, kiri, kanan);

        // Urutkan bagian kiri dan kanan secara rekursif
        quickSortLomuto(data, kiri, pivotIndex - 1);
        quickSortLomuto(data, pivotIndex + 1, kanan);
    }
}

void cetakArray(int data[], int n) { // Fungsi mencetak array
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {12, 5, 26, 7, 14, 3, 7, 2};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Sebelum sorting : ");
    cetakArray(data, n);

    quickSortLomuto(data, 0, n - 1);

    printf("Setelah ascending : ");
    cetakArray(data, n);

    return 0;
}
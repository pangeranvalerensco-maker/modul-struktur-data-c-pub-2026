#include <stdio.h>

void swap(int *a, int *b) { // Fungsi untuk menukar dua elemen
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hoare partition: pivot = elemen tengah
int partitionHoare(int data[], int kiri, int kanan) {
    // Pilih pivot sebagai elemen tengah
    int pivot = data[(kiri + kanan) / 2];
    int i = kiri - 1;
    int j = kanan + 1;

    while (1) {
        do { // Cari elemen dari kiri yang >= pivot
            i++;
        } while (data[i] < pivot);

        do { // Cari elemen dari kanan yang <= pivot
            j--;
        } while (data[j] > pivot);

        if (i >= j) return j;  // pointer bertemu, partisi selesai

        swap(&data[i], &data[j]);
    }
}

// Fungsi Quick Sort rekursif
void quickSortHoare(int data[], int kiri, int kanan) {
    if (kiri < kanan) {
        int pivotIndex = partitionHoare(data, kiri, kanan);

        // Urutkan bagian kiri dan kanan secara rekursif
        quickSortHoare(data, kiri, pivotIndex);
        quickSortHoare(data, pivotIndex + 1, kanan);
    }
}

void cetakArray(int data[], int n) {
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

    quickSortHoare(data, 0, n - 1);

    printf("Setelah ascending : ");
    cetakArray(data, n);

    return 0;
}

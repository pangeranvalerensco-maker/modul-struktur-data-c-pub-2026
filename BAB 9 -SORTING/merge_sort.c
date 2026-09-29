#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menggabungkan dua bagian array yang sudah terurut
void merge(int data[], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;  // ukuran bagian kiri
    int n2 = kanan - tengah;     // ukuran bagian kanan

    // Buat array sementara untuk bagian kiri dan kanan
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        printf("Alokasi memori gagal!\n");
        return;
    }

    // Salin data ke array sementara
    for (int i = 0; i < n1; i++) L[i] = data[kiri + i];
    for (int j = 0; j < n2; j++) R[j] = data[tengah + 1 + j];

    int i = 0, j = 0, k = kiri; // Proses penggabungan (merge)
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { // Salin sisa elemen kiri (jika ada)
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) { // Salin sisa elemen kanan (jika ada)
        data[k] = R[j];
        j++;
        k++;
    }

    free(L); // Bebaskan memori array sementara
    free(R);
}

void mergeSort(int data[], int kiri, int kanan) { // Fungsi Merge Sort rekursif
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;  // cari titik tengah
        
        mergeSort(data, kiri, tengah); // Urutkan bagian kiri dan kanan secara rekursif
        mergeSort(data, tengah + 1, kanan);

        merge(data, kiri, tengah, kanan); // Gabungkan dua bagian yang sudah terurut
    }
}

void cetakArray(int data[], int n) { // Fungsi mencetak array
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {38, 27, 43, 10, 3, 82, 9};
    int n = sizeof(data) / sizeof(data[0]);

    printf("OUTPUT: \n");
    printf("Sebelum sorting : ");
    cetakArray(data, n);

    mergeSort(data, 0, n - 1);

    printf("Setelah ascending : ");
    cetakArray(data, n);

    return 0;
}

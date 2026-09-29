#include <stdio.h>
#include <stdlib.h>

void countingSortSederhana(int data[], int n) { // Fungsi Counting Sort sederhana (asumsi data >= 0)
    int max = data[0]; // 1. Cari nilai maksimum
    for (int i = 1; i < n; i++) {
        if (data[i] > max) max = data[i];
    }

    int *count = (int*)calloc(max + 1, sizeof(int)); // 2. Buat array count berukuran max+1
    if (count == NULL) {
        printf("Alokasi memori gagal!\n");
        return;
    }

    for (int i = 0; i < n; i++) { // 3. Hitung frekuensi
        count[data[i]]++;
    }

    for (int i = 1; i <= max; i++) { // 4. Prefix sum
        count[i] += count[i - 1];
    }

    int *output = (int*)malloc(n * sizeof(int)); // 5. Buat array output
    if (output == NULL) {
        printf("Alokasi memori gagal!\n");
        free(count);
        return;
    }

    for (int i = n - 1; i >= 0; i--) { // 6. Tempatkan elemen di posisi yang benar (dari belakang)
        int index = count[data[i]] - 1;
        output[index] = data[i];
        count[data[i]]--;
    }

    for (int i = 0; i < n; i++) { // 7. Salin output ke data
        data[i] = output[i];
    }

    free(count); // 8. Bebaskan memori
    free(output);
}

void cetakArray(int data[], int n) { // Fungsi mencetak array
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int n = sizeof(data) / sizeof(data[0]);

    printf("OUTPUT: \n");
    printf("Sebelum sorting : ");
    cetakArray(data, n);

    countingSortSederhana(data, n);
    printf("Setelah ascending : ");
    cetakArray(data, n);

    return 0;
}
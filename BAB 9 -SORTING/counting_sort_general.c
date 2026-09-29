#include <stdio.h>
#include <stdlib.h>

void countingSortUmum(int data[], int n) {
    int min = data[0], max = data[0]; // 1. Cari nilai minimum dan maksimum
    for (int i = 1; i < n; i++) {
        if (data[i] < min) min = data[i];
        if (data[i] > max) max = data[i];
    }

    int range = max - min + 1; // 2. Tentukan rentang
    int *count = (int*)calloc(range, sizeof(int));
    if (count == NULL) {
        printf("Alokasi memori gagal!\n");
        return;
    }

    for (int i = 0; i < n; i++) { // 3. Hitung frekuensi
        count[data[i] - min]++;
    }

    for (int i = 1; i < range; i++) { // 4. Prefix sum
        count[i] += count[i - 1];
    }

    int *output = (int*)malloc(n * sizeof(int)); // 5. Buat array output
    if (output == NULL) {
        printf("Alokasi memori gagal!\n");
        free(count);
        return;
    }

    for (int i = n - 1; i >= 0; i--) { // 6. Tempatkan elemen di posisi yang benar (dari belakang)
        int index = count[data[i] - min] - 1;
        output[index] = data[i];
        count[data[i] - min]--;
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
    int data[] = {20, 25, 21, 22, 20, 21};
    int n = sizeof(data) / sizeof(data[0]);

    printf("OUTPUT: \n");
    printf("Sebelum sorting : ");
    cetakArray(data, n);

    countingSortUmum(data, n);
    printf("Setelah ascending : ");
    cetakArray(data, n);

    return 0;
}
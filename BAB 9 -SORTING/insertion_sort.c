#include <stdio.h>

void insertionSortAsc(int data[], int n) { // Fungsi scending (kecil → besar)
    // Mulai dari indeks 1 (elemen kedua), karena indeks 0 dianggap sudah terurut
    for (int i = 1; i < n; i++) {
        int key = data[i];  // elemen yang akan disisipkan
        int j = i - 1;      // posisi elemen di sebelah kiri

        // Geser elemen yang lebih besar ke kanan untuk memberi ruang
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = key; // Sisipkan key di posisi yang tepat
    }
}

void insertionSortDesc(int data[], int n) { // Fungsi descending (besar → kecil)
    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] < key) { // Perhatikan: operator < untuk descending
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
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

    insertionSortAsc(data, n);
    printf("Setelah ascending : ");
    cetakArray(data, n);

    int data2[] = {85, 70, 90, 60, 80, 75}; // Reset data untuk contoh descending
    insertionSortDesc(data2, n);
    printf("Setelah descending: ");
    cetakArray(data2, n);

    return 0;
}
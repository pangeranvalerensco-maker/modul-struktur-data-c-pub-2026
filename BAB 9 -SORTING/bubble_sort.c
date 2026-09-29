#include <stdio.h>

void bubbleSortAsc(int data[], int n) { // Fungsi ascending (kecil → besar)
    // Loop luar: menentukan jumlah iterasi (n-1 kali)
    for (int i = 0; i < n - 1; i++) {
        // Loop dalam: membandingkan elemen yang berdekatan
        // Batas n-1-i karena elemen di akhir sudah terurut
        for (int j = 0; j < n - 1 - i; j++) {
            // Jika elemen sekarang lebih besar dari elemen berikutnya
            if (data[j] > data[j + 1]) { 
                int temp = data[j]; // Tukar posisi (swap)
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void bubbleSortDesc(int data[], int n) { // Fungsi descending (besar → kecil)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            // Perhatikan: operator < untuk descending
            if (data[j] < data[j + 1]) { 
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
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

    bubbleSortAsc(data, n);
    printf("Setelah ascending : ");
    cetakArray(data, n);

    int data2[] = {85, 70, 90, 60, 80, 75}; // Reset data untuk contoh descending
    bubbleSortDesc(data2, n);
    printf("Setelah descending: ");
    cetakArray(data2, n);

    return 0;
}
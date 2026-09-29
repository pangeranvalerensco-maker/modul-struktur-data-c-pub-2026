#include <stdio.h>

// Fungsi mencari nilai max dan min sekaligus
// Parameter arr: pointer ke array
// ukuran: jumlah elemen
// max, min: pointer ke variabel di main yang akan diisi hasil
void cari_max_min(int *arr, int ukuran, int *max, int *min) {
    // Mulai dengan asumsi elemen pertama adalah max dan min
    *max = arr[0];
    *min = arr[0];

    // Loop dari elemen kedua sampai akhir
    for(int i = 1; i < ukuran; i++) {
        if(arr[i] > *max) {     // jika ditemukan lebih besar
            *max = arr[i];      // perbarui max (lewat pointer)
        }
        if(arr[i] < *min) {     // jika ditemukan lebih kecil
            *min = arr[i];      // perbarui min (lewat pointer)
        }
    }
}

int main() {
    int data[5] = {85, 90, 78, 73, 72};
    int max, min;   // variabel untuk menyimpan hasil (akan diisi fungsi)

    // Kirim alamat max dan min agar fungsi bisa mengisinya
    cari_max_min(data, 5, &max, &min);

    printf("Nilai tertinggi: %d\n", max);
    printf("Nilai terendah: %d\n", min);

    return 0;
}

int *ptr;
*ptr = 10;
printf("%d", *ptr);

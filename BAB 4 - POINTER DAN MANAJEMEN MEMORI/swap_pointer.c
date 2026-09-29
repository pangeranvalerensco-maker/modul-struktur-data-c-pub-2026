#include <stdio.h>

// Fungsi untuk menukar dua nilai integer menggunakan pointer
// Parameter a dan b adalah pointer (berisi alamat variabel asli)
void tukar(int *a, int *b) {
    int temp;          // variabel sementara untuk menyimpan nilai

    // Simpan nilai asli yang ditunjuk a ke temp
    temp = *a;         // *a artinya: ambil isi dari alamat yang disimpan a

    // Isi alamat a dengan nilai dari alamat b
    *a = *b;           // sekarang variabel asli a mendapat nilai variabel b

    // Isi alamat b dengan nilai temp (nilai asli a)
    *b = temp;         // sekarang variabel asli b mendapat nilai asli a
}

int main() {
    int x = 10, y = 20;  

    printf("Sebelum tukar: x = %d, y = %d\n", x, y);

    // Kirim alamat x dan y ke fungsi tukar
    // Dengan mengirim alamat, fungsi bisa mengubah variabel asli
    tukar(&x, &y);        // &x = alamat x, &y = alamat y

    printf("Setelah tukar: x = %d, y = %d\n", x, y);

    return 0;
}
#include <stdio.h>

int main() {
    int *ptr = NULL;   // ptr belum menunjuk ke mana pun

    if (ptr != NULL) {
        *ptr = 10;     // hanya dijalankan jika ptr tidak NULL
    } else {
        printf("Pointer masih NULL, tidak bisa digunakan.\n");
    }

    // Kemudian kita bisa menunjuk ke variabel
    int nilai = 85;
    ptr = &nilai;      // sekarang ptr menunjuk ke nilai

    if (ptr != NULL) {
        printf("Nilai: %d\n", *ptr);  // aman, mencetak 85
    }

    return 0;
}

struct Mahasiswa {
    char nim[10];
    char nama[50];
    int umur;
    float ipk;
};

typedef struct Mahasiswa Mahasiswa;
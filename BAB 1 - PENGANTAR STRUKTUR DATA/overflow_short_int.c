#include <stdio.h>

int main() {

    short int angka = 127;

    printf("Nilai awal: %d\n", angka);

    angka = 128; // Nilai ini melebihi batas maksimum untuk short int
    // tapi karena tipe data short int hanya dapat menyimpan nilai hingga 127
    // maka terjadi overflow sehingga nilai yang disimpan menjadi -128 (nilai minimum untuk short int)
    printf("Setelah ditambah 1: %d\n", angka);

    angka = 129; // Nilai ini juga melebihi batas maksimum untuk short int
    // sehingga terjadi overflow lagi dan nilai yang disimpan menjadi -127
    printf("Setelah ditambah 1 lagi: %d\n", angka);

    return 0;
}
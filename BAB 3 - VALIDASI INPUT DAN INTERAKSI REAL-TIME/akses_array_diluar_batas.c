#include <stdio.h>

void main()
{
    // int nilai[3] = {85, 90, 78};
    // int indeks;
    // printf("Masukkan indeks: ");
    // scanf("%d", &indeks);
    // printf("Nilai: %d", nilai[indeks]); // bahaya jika indeks = 5

    // int umur;
    // printf("Masukkan umur: ");
    // scanf("%d", &umur);
    // printf("Umur: %d", umur);

    int stok = 100;
    int beli;
    printf("Jumlah beli: ");
    scanf("%d", &beli);
    stok = stok - beli; // jika beli = 200, stok menjadi negatif!
    printf("Sisa stok: %d", stok);int tombol;


    if (tombol >= 48 && tombol <= 57) {
        // ini adalah angka
    }
}
#include <stdio.h>

int main() {
    // BYTE: rentang nilai 0 s/d 255 (hanya bilangan positif)
    unsigned char byte = 200;       
    printf("Jumlah barang di toko kecil: %u\n\n", byte);

    // SHORT INT: rentang nilai -128 s/d 127 (bisa negatif)
    signed char shortInt = -100;    
    printf("Suhu ruangan saat ini: %d derajat\n\n", shortInt);

    // INT: rentang nilai -32768 s/d 32767
    int angka = 30000;              
    printf("Jumlah siswa di beberapa sekolah: %d\n\n", angka);

    // WORD: rentang nilai 0 s/d 65535 (tanpa negatif)
    unsigned int word = 50000;      
    printf("Jumlah stok barang di gudang besar: %u\n\n", word);

    // LONG INT: rentang nilai -2147483648 s/d 2147483647
    long int longAngka = 1000000;   
    printf("Jumlah penduduk suatu negara: %ld\n\n", longAngka);

    return 0;
}
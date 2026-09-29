#include <stdio.h>

struct Mahasiswa {
    char nama[50];
    int umur;
};

int main() {

    struct Mahasiswa mhs = {"Budi", 20};

    printf("Nama: %s\n", mhs.nama);
    printf("Umur: %d\n", mhs.umur);

    return 0;
}
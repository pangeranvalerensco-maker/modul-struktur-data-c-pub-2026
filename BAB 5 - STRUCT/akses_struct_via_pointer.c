#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[10];
    char nama[50];
    int umur;
    float ipk;
} Mahasiswa;

int main() {
    Mahasiswa mhs1;
    Mahasiswa *ptr = &mhs1;   // pointer ke struct

    // Mengisi data melalui pointer (menggunakan ->)
    strcpy(ptr->nim, "A001");
    strcpy(ptr->nama, "Andi");
    ptr->umur = 20;
    ptr->ipk = 3.75;

    // Menampilkan data melalui pointer
    printf("NIM  : %s\n", ptr->nim);
    printf("Nama : %s\n", ptr->nama);
    printf("Umur : %d\n", ptr->umur);
    printf("IPK  : %.2f\n", ptr->ipk);

    return 0;
}
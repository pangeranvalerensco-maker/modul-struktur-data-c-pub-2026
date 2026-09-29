#include <stdio.h>
#include <string.h>

typedef struct {
    char jalan[100];
    char kota[50];
    char provinsi[50];
    int kodePos;
} Alamat;

typedef struct {
    char nim[10];
    char nama[50];
    int umur;
    float ipk;
    Alamat alamat;
} Mahasiswa;

void main() {
    Mahasiswa mhs1;
    Mahasiswa *ptr = &mhs1;   // pointer ke struct

    strcpy(ptr->nim, "A001"); // Mengisi data melalui pointer
    strcpy(ptr->nama, "Andi");
    ptr->umur = 20;
    ptr->ipk = 3.75;

    // Mengisi nested struct melalui pointer
    strcpy(ptr->alamat.jalan, "Jl. Merdeka No. 10");
    strcpy(ptr->alamat.kota, "Bandung");
    strcpy(ptr->alamat.provinsi, "Jawa Barat");
    ptr->alamat.kodePos = 40112;

    // Menampilkan data melalui pointer
    printf("NIM      : %s\n", ptr->nim);
    printf("Nama     : %s\n", ptr->nama);
    printf("Umur     : %d\n", ptr->umur);
    printf("IPK      : %.2f\n", ptr->ipk);
    printf("Alamat   : %s, %s, %s - %d\n",
           ptr->alamat.jalan,
           ptr->alamat.kota,
           ptr->alamat.provinsi,
           ptr->alamat.kodePos);
}
#include <stdio.h>

int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60}; // 6 data awal, kapasitas 10
    int ukuran = 6;
    int posisi, nilaiBaru;
    
    printf("Array awal: ");
    for(int i = 0; i < ukuran; i++) printf("%d ", arr[i]);
    printf("\n");
    
    printf("Masukkan posisi indeks (0-%d): ", ukuran);
    scanf("%d", &posisi);
    if(posisi < 0 || posisi > ukuran) {
        printf("Posisi tidak valid!\n");
        return 1;
    }
    
    printf("Masukkan nilai baru: ");
    scanf("%d", &nilaiBaru);
    
    // Geser elemen ke kanan
    for(int i = ukuran; i > posisi; i--) {
        arr[i] = arr[i-1];
    }
    arr[posisi] = nilaiBaru;
    ukuran++;
    
    printf("Array setelah sisip: ");
    for(int i = 0; i < ukuran; i++) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
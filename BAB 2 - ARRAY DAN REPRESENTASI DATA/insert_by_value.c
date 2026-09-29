#include <stdio.h>

int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60};
    int ukuran = 6;
    int cari, nilaiBaru, posisi = -1;
    
    printf("Array awal: ");
    for(int i = 0; i < ukuran; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Masukkan nilai yang dicari: ");
    scanf("%d", &cari);
    
    for(int i = 0; i < ukuran; i++) {
        if(arr[i] == cari){ 
            posisi = i; 
            break; 
        }
    }
    
    if(posisi == -1) {
        printf("Nilai tidak ditemukan.\n");
        return 1;
    }
    
    printf("Masukkan nilai baru setelah %d: ", cari);
    scanf("%d", &nilaiBaru);
    
    for(int i = ukuran; i > posisi+1; i--) {
        arr[i] = arr[i-1];
    }
    arr[posisi+1] = nilaiBaru;
    ukuran++;
    
    printf("Array setelah sisip: ");
    for(int i = 0; i < ukuran; i++) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
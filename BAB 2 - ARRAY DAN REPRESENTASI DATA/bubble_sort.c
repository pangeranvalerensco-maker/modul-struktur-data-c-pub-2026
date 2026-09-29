#include <stdio.h>

int main() {
    int nilai[6] = {85, 70, 90, 60, 80, 75};
    int ukuran = 6;
    int temp;
    
    printf("Sebelum diurutkan: ");
    for(int i = 0; i < ukuran; i++){ 
        printf("%d ", nilai[i]);
    }
    printf("\n");
    
    // Bubble sort ascending
    for(int i = 0; i < ukuran-1; i++) {
        for(int j = 0; j < ukuran-1-i; j++) {
            if(nilai[j] > nilai[j+1]) {
                temp = nilai[j];
                nilai[j] = nilai[j+1];
                nilai[j+1] = temp;
            }
        }
    }
    
    printf("Setelah diurutkan (kecil ke besar): ");
    for(int i = 0; i < ukuran; i++) printf("%d ", nilai[i]);
    printf("\n");
    
    return 0;
}
#include <stdio.h>
#include <conio.h>

int main() {
    char tombol;
    
    printf("Tekan sembarang tombol...\n");
    tombol = getch();   // program berhenti sampai ada tombol ditekan, tidak perlu Enter
    
    printf("Anda menekan tombol: %c\n", tombol); //  Misalnya tombol spasi
    printf("Kode ASCII-nya: %d\n", tombol);
    
    return 0;
}
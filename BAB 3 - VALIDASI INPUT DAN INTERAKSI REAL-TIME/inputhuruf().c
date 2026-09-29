#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void inputHuruf(char *buffer, int maxPanjang, int izinkanSpasi) {
    int idx = 0;
    char tombol;
    
    while (1) {
        tombol = getch();
        
        // Validasi huruf
        if ((tombol >= 'A' && tombol <= 'Z') || (tombol >= 'a' && tombol <= 'z')) {
            if (idx < maxPanjang - 1) {
                // Format kapital: huruf pertama setelah spasi atau awal -> besar, else kecil
                if (idx == 0 || (idx > 0 && buffer[idx-1] == ' ')) {
                    tombol = toupper(tombol);
                } else {
                    tombol = tolower(tombol);
                }
                buffer[idx++] = tombol;
                printf("%c", tombol);
            } else {
                printf("\a"); // bunyi jika mencapai batas
            }
        }
        // Spasi (jika diizinkan)
        else if (izinkanSpasi && tombol == ' ' && idx > 0 && buffer[idx-1] != ' ') {
            if (idx < maxPanjang - 1) {
                buffer[idx++] = tombol;
                printf("%c", tombol);
            } else {
                printf("\a");
            }
        }
        // Backspace
        else if (tombol == 8 && idx > 0) {
            idx--;
            printf("\b \b");
        }
        // Enter
        else if (tombol == 13 && idx > 0) {
            buffer[idx] = '\0';
            break;
        }
        else {
            printf("\a");
        }
    }
}

int main() {
    char nama[50];
    printf("Masukkan nama (huruf dan spasi): ");
    inputHuruf(nama, 50, 1);
    printf("\nNama: %s\n", nama);
    
    char kode[10];
    printf("Masukkan kode (huruf saja, tanpa spasi): ");
    inputHuruf(kode, 10, 0);
    printf("\nKode: %s\n", kode);
    
    return 0;
}
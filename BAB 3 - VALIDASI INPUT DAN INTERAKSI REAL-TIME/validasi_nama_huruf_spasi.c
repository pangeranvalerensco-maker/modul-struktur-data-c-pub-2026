#include <stdio.h>
#include <conio.h>
#include <ctype.h>  // untuk toupper(), tolower()

int main() {
    char buffer[50];
    int idx = 0;
    char tombol;
    
    printf("Masukkan nama (hanya huruf dan spasi): ");
    
    while (1) {
        tombol = getch();
        
        // Huruf besar atau huruf kecil
        if ((tombol >= 'A' && tombol <= 'Z') || (tombol >= 'a' && tombol <= 'z')) {
            // Jika ini karakter pertama setelah spasi atau awal, buat huruf besar
            if (idx == 0 || buffer[idx-1] == ' ') {
                tombol = toupper(tombol);
            } else {
                tombol = tolower(tombol);
            }
            buffer[idx++] = tombol;
            printf("%c", tombol);
        }
        // Spasi: hanya boleh jika idx > 0 (tidak di awal) dan karakter sebelumnya bukan spasi
        else if (tombol == ' ' && idx > 0 && buffer[idx-1] != ' ') {
            buffer[idx++] = tombol;
            printf("%c", tombol);
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
        // Tombol lain: bunyi peringatan
        else {
            printf("\a");
        }
    }
    
    printf("\nNama yang dimasukkan: %s\n", buffer);
    return 0;
}
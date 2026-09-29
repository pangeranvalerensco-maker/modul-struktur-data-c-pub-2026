#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void inputNoHP(char *buffer, int maxPanjang) {
    int idx = 0;
    char tombol;
    while (1) {
        tombol = getch();
        if (tombol >= '0' && tombol <= '9') { // Hanya angka
            if (idx < maxPanjang - 1) { // Batasan panjang
                if (idx == 0 && tombol == '0') { // Cek aturan awalan
                    buffer[idx++] = tombol;
                    printf("%c", tombol);
                }
                else if (idx == 0 && tombol == '6') {
                    buffer[idx++] = tombol;
                    printf("%c", tombol);
                }
                else if (idx == 1 && buffer[0] == '0' && tombol == '8') {
                    buffer[idx++] = tombol;
                    printf("%c", tombol);
                }
                else if (idx == 1 && buffer[0] == '6' && tombol == '2') {
                    buffer[idx++] = tombol;
                    printf("%c", tombol);
                }
                else if (idx >= 2) { // Setelah awalan, semua angka bebas
                    buffer[idx++] = tombol;
                    printf("%c", tombol);
                }
                else {
                    printf("\a"); // awalan tidak sesuai
                }
            } else { printf("\a"); }
        }
        else if (tombol == 8 && idx > 0) {
            idx--;
            printf("\b \b");
        }
        else if (tombol == 13) {
            if (idx >= 10 && idx <= 13) {
                buffer[idx] = '\0';
                break;
            } else {
                printf("\a"); // panjang tidak sesuai
            }
        }
        else if (tombol == 27) {
            buffer[0] = '\0';
            break;
        }
        else {
            printf("\a");
        }
    }
}

void inputEmail(char *buffer, int maxPanjang) {
    int idx = 0;
    char tombol;
    int atCount = 0;
    int dotAfterAt = 0;
    while (1) {
        tombol = getch();
        // Karakter yang diizinkan: huruf, angka, '.', '_', '@'
        if ( (tombol >= 'A' && tombol <= 'Z') || (tombol >= 'a' && tombol <= 'z') ||
             (tombol >= '0' && tombol <= '9') || tombol == '.' || tombol == '_' || tombol == '@' )
        {
            if (idx < maxPanjang - 1) {
                if (tombol == '@') { // Cek aturan '@'
                    if (atCount == 0 && idx > 0) {
                        atCount++;
                        buffer[idx++] = tombol;
                        printf("%c", tombol);
                    } else {
                        printf("\a"); // '@' kedua atau di awal
                    }
                }
                else if (tombol == '.') {
                    // Jangan terima titik jika setelah '@' belum ada karakter
                    if (atCount == 1 && idx > 0 && buffer[idx-1] == '@') { 
                        printf("\a"); // titik langsung setelah '@'
                    } else {
                        buffer[idx++] = tombol;
                        printf("%c", tombol);
                        if (atCount == 1) dotAfterAt = 1;
                    }
                }
                else {
                    buffer[idx++] = tombol;
                    printf("%c", tombol);
                    if (atCount == 1) dotAfterAt = 1;
                }
            } else { printf("\a"); }
        }else if (tombol == 8 && idx > 0) {
            if (buffer[idx-1] == '@') atCount--; // saat backspace, update flag atCount dan dotAfterAt
            if (buffer[idx-1] == '.' && atCount == 1) dotAfterAt = 0;
            idx--;
            printf("\b \b");
        }else if (tombol == 13 && idx > 0 && atCount == 1 && dotAfterAt == 1) {
            buffer[idx] = '\0';
            break;
        }else if (tombol == 27) {
            buffer[0] = '\0';
            break;
        }else {
            printf("\a");
        }
    }
}

void inputPassword(char *buffer, int maxPanjang) {
    int idx = 0;
    char tombol;
    int adaHuruf = 0, adaAngka = 0;
    while (1) {
        tombol = getch();
        // Menerima huruf, angka, dan karakter khusus tertentu
        if ( (tombol >= 'A' && tombol <= 'Z') || (tombol >= 'a' && tombol <= 'z') ||
             (tombol >= '0' && tombol <= '9') || tombol == '!' || tombol == '@' || 
             tombol == '#' || tombol == '$' || tombol == '%' )
{
            if (idx < maxPanjang - 1) {
                if (isalpha(tombol)) adaHuruf = 1;
                if (isdigit(tombol)) adaAngka = 1;
                buffer[idx++] = tombol;
                printf("*");  // tampilkan bintang, bukan karakter asli
            } else { printf("\a"); }
        }
        else if (tombol == 8 && idx > 0) {
            idx--;
            printf("\b \b");
        }
        else if (tombol == 13 && idx >= 6 && adaHuruf == 1 && adaAngka == 1) {
            buffer[idx] = '\0';
            break;
        }
        else if (tombol == 27) {
            buffer[0] = '\0';
            break;
        }
        else {
            printf("\a");
        }
    }
}

int main() {
    char hp[15];
    char email[50];
    char password[20];

    printf("Masukkan nomor HP (08/62): ");
    inputNoHP(hp, 15);
    if (hp[0] != '\0') printf("HP: %s\n", hp);

    printf("Masukkan email: ");
    inputEmail(email, 50);
    if (email[0] != '\0') printf("Email: %s\n", email);

    printf("Masukkan password (min 6, huruf+angka): ");
    inputPassword(password, 20);
    if (password[0] != '\0') printf("Password tersimpan.\n");

    return 0;
}
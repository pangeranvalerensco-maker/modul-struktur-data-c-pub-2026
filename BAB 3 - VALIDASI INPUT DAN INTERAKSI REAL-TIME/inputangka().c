#include <stdio.h>
#include <conio.h>

void inputAngka(char *buffer, int maxPanjang) {
    int idx = 0;
    char tombol;
    while (1) {
        tombol = getch();

        if (tombol >= '0' && tombol <= '9') { // 1. Hanya angka 0-9 yang disimpan
            if (idx < maxPanjang - 1) {
                buffer[idx++] = tombol;
                printf("%c", tombol);
            } else {
                printf("\a"); // bunyi jika buffer penuh
            }
        }
        else if (tombol == 8) { // 2. Backspace (ASCII 8)
            if (idx > 0) {
                idx--;
                printf("\b \b");
            } else {
                printf("\a");
            }
        }
        else if (tombol == 13) { // 3. Enter (ASCII 13) – selesai, hanya jika sudah ada karakter
            if (idx > 0) {
                buffer[idx] = '\0';
                break;
            } else {
                printf("\a"); // input kosong tidak diterima
            }
        }
        else if (tombol == 27) { // 4. ESC (ASCII 27) – batal
            buffer[0] = '\0';
            break;
        }
        else { // 5. Tombol lain (huruf, spasi, simbol, dll) -> bunyi
            printf("\a");
        }
    }
}

int main() {
    char nomorHP[15];
    printf("Masukkan nomor HP (hanya angka, ESC untuk batal): ");
    inputAngka(nomorHP, 15);
    if (nomorHP[0] == '\0') {
        printf("\nInput dibatalkan.\n");
    } else {
        printf("\nNomor HP yang dimasukkan: %s\n", nomorHP);
    }
    return 0;
}


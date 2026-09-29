#include <stdio.h>
#include <conio.h>

int main() {
    char buffer[50];
    int idx = 0;
    char tombol;

    printf("Ketik sesuatu (ESC untuk batal, Enter untuk selesai):\n");

    while (1) {
        tombol = getch();

        // Jika tombol adalah karakter yang bisa dicetak (misal huruf, angka, spasi)
        if (tombol >= 32 && tombol <= 126) {  // rentang karakter cetak ASCII
            if (idx < 49) {
                buffer[idx++] = tombol;
                printf("%c", tombol);
            } else {
                printf("\a"); // bunyi jika buffer penuh
            }
        }
        else if (tombol == 8) { // Backspace
            if (idx > 0) {
                idx--;
                printf("\b \b");
            } else {
                printf("\a");
            }
        }
        else if (tombol == 13) { // Enter
            if (idx > 0) {
                buffer[idx] = '\0';
                break;
            } else {
                printf("\a"); // tidak terima input kosong
            }
        }
        else if (tombol == 27) { // ESC
            buffer[0] = '\0';
            break;
        }
        else { // Tombol lainnya (misal panah, fungsi) -> bunyi
            printf("\a");
        }
    }

    if (buffer[0] == '\0') {
        printf("\nInput dibatalkan.\n");
    } else {
        printf("\nAnda mengetik: %s\n", buffer);
    }
    return 0;
}


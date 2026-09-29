#include <ctype.h>

void inputAngka(char *buffer, int maxPanjang) {
    int idx = 0;
    char tombol;
    while (1) {
        tombol = getch();
        if (isdigit(tombol)) {// lebih jelas dari rentang ASCII
            if (idx < maxPanjang - 1) {
                buffer[idx++] = tombol;
                printf("%c", tombol);
            } else { printf("\a"); }
        }
        else if (tombol == 8 && idx > 0) { /* backspace */ }
        else if (tombol == 13 && idx > 0) { /* enter */ }
        else { printf("\a"); }
    }
}


#include <stdio.h>
#include <conio.h>
#include <windows.h>

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Fungsi untuk mendapatkan posisi kursor saat ini
void getxy(int *x, int *y) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    *x = csbi.dwCursorPosition.X;
    *y = csbi.dwCursorPosition.Y;
}

#define RED         4
#define LIGHTRED    12
#define WHITE       7

void inputNoHP(char *buffer, int maxPanjang) {
    int idx = 0;
    char tombol;
    int startX, startY;
    // Simpan posisi kursor awal (tempat input dimulai)
    getxy(&startX, &startY);
    while (1) {
        tombol = getch();

        if (tombol >= '0' && tombol <= '9') {
            if (idx < maxPanjang - 1) {
                buffer[idx++] = tombol;
                printf("%c", tombol);
            } else {
                printf("\a");
                // Tampilkan notifikasi di baris 24
                gotoxy(1, 2);
                setColor(RED);
                printf("Maksimal %d digit!", maxPanjang-1);
                Sleep(800);
                // Hapus notifikasi
                gotoxy(1, 2);
                printf("                        ");
                // Kembalikan kursor ke posisi input (startX + idx)
                gotoxy(startX + idx, startY);
                setColor(WHITE);
            }
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
                printf("\a");
                gotoxy(1, 2);
                setColor(RED);
                printf("Nomor HP harus 10-13 digit!");
                Sleep(1000);
                gotoxy(1, 2);
                printf("                            ");
                // Kembalikan kursor ke posisi input
                gotoxy(startX + idx, startY);
                setColor(WHITE);
            }
        }
        else if (tombol == 27) {
            buffer[0] = '\0';
            gotoxy(1, 2);
            setColor(LIGHTRED);
            printf("Input dibatalkan. Tekan sembarang tombol...");
            getch();
            gotoxy(1, 2);
            printf("                                          ");
            break;
        }
        else {
            printf("\a");
            gotoxy(1, 2);
            setColor(RED);
            printf("Hanya angka 0-9 yang diizinkan!");
            Sleep(600);
            gotoxy(1, 2);
            printf("                                 ");
            // Kembalikan kursor ke posisi input
            gotoxy(startX + idx, startY);
            setColor(WHITE);
        }
    }
}

int main() {
    system("cls");
    char nomor[16];
    printf("Masukkan nomor HP (08/62, 10-13 digit, ESC batal): ");
    inputNoHP(nomor, 16);
    if (nomor[0] != '\0')
        printf("\nNomor HP: %s\n", nomor);
    else
        printf("\nInput dibatalkan.\n");
    return 0;
}
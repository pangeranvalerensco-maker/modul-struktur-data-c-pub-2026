#include <stdio.h>
#include <conio.h>
#include <windows.h>   // untuk Sleep, gotoxy (opsional)

// ========== Validasi Fungsi (ringkasan) ==========
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
        else if(tombol == 27){
            buffer[0] = '\0';
            break;
        }
        else {
            printf("\a");
        }
    }
}

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

// ========== Menu Input Data ==========
void menuInputData() {
    char nama[50], umur[5], nim[15], hp[16];
    
    system("cls");
    printf("=== INPUT DATA MAHASISWA ===\n");
    printf("ESC untuk membatalkan dan kembali ke menu utama.\n\n");
    
    printf("Nama: ");
    inputHuruf(nama, 50, 1); // izinkan spasi
    if (nama[0] == '\0') {
        printf("\nInput nama dibatalkan. Kembali ke menu.\n");
        getch();
        return;
    }
    printf("\nUmur: ");
    inputAngka(umur, 5);
    if (umur[0] == '\0') {
        printf("\nInput umur dibatalkan. Kembali ke menu.\n");
        getch();
        return;
    }
    printf("\nNIM (hanya angka): ");
    inputAngka(nim, 15);
    if (nim[0] == '\0') {
        printf("\nInput NIM dibatalkan. Kembali ke menu.\n");
        getch();
        return;
    }
    printf("\nNomor HP (08/62): ");
    inputNoHP(hp, 16);
    if (hp[0] == '\0') {
        printf("\nInput HP dibatalkan. Kembali ke menu.\n");
        getch();
        return;
    }
    // Jika semua input valid, tampilkan ringkasan
    printf("\n\n=== DATA TERSIMPAN ===\n");
    printf("Nama : %s\n", nama);
    printf("Umur : %s tahun\n", umur);
    printf("NIM  : %s\n", nim);
    printf("HP   : %s\n", hp);
    printf("\nTekan sembarang tombol untuk kembali ke menu utama.");
    getch();
}

int main() {
    char pilihan;
    do {
        system("cls");
        printf("================================\n");
        printf("   APLIKASI DATA MAHASISWA\n");
        printf("================================\n");
        printf("1. Input Data Mahasiswa\n");
        printf("2. Tampilkan Data (contoh)\n");
        printf("3. Keluar\n");
        printf("--------------------------------\n");
        printf("Tekan ESC untuk keluar dari program.\n");
        printf("Pilihan: ");
        
        pilihan = getch();
        
        if (pilihan == 27) {
            printf("\nTerima kasih telah menggunakan program.\n");
            break;
        }
        
        switch (pilihan) {
            case '1':
                menuInputData();
                break;
            case '2':
                system("cls");
                printf("Fitur tampilkan data belum diimplementasikan.\n");
                printf("Tekan sembarang tombol untuk kembali...");
                getch();
                break;
            case '3':
                printf("\nTerima kasih.\n");
                return 0;
            default:
                printf("\nPilihan tidak valid! (1,2,3, atau ESC)\n");
                printf("Tekan sembarang tombol untuk melanjutkan...");
                getch();
        }
    } while (1);
    return 0;
}
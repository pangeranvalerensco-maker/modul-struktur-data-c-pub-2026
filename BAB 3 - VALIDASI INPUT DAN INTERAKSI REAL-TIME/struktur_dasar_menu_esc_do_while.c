int main() {
    char pilihan;
    do {
        system("cls"); // bersihkan layar (Windows)
        printf("=== MENU UTAMA ===\n");
        printf("1. Input Data\n");
        printf("2. Tampilkan Data\n");
        printf("3. Keluar\n");
        printf("Tekan ESC untuk keluar kapan saja.\n");
        printf("Pilihan: ");
        
        pilihan = getch(); // baca satu tombol tanpa Enter
        
        if (pilihan == 27) { // ESC
            printf("\nKeluar dari program.\n");
            break;
        }
        
        switch (pilihan) {
            case '1':
                // panggil sub-menu input data
                break;
            case '2':
                // tampilkan data
                break;
            case '3':
                printf("\nTerima kasih.\n");
                return 0;
            default:
                printf("\nPilihan tidak valid!\n");
                printf("Tekan sembarang tombol untuk melanjutkan...");
                getch();
        }
    } while (1);
    return 0;
}

else if (tombol == 8 && idx > 0) {
    idx--;
    printf("\b \b");
}

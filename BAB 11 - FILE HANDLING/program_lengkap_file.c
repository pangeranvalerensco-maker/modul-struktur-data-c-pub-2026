#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nama[100];
    float ipk;
} Mahasiswa;

void tambahData() { // --- CREATE: Menambah Data Baru ---
    FILE *fptr = fopen("mahasiswa.txt", "a"); // Mode "a" agar data lama tetap aman
    if (fptr == NULL) {
        printf("Gagal membuka file untuk menulis!\n");
        return;
    }

    Mahasiswa m;
    printf("\n--- TAMBAH MAHASISWA ---\n");
    printf("ID: "); scanf("%d", &m.id);
    printf("Nama Lengkap: "); scanf(" %[^\n]", m.nama); // Trik membaca nama dengan spasi
    printf("IPK: "); scanf("%f", &m.ipk);

    // Simpan ke file dengan delimiter '/'
    fprintf(fptr, "%d/%s/%.2f\n", m.id, m.nama, m.ipk);
    fclose(fptr);
    printf("Data mahasiswa berhasil ditambahkan!\n");
}

void tampilkanData() { // --- READ: Menampilkan Semua Data ---
    FILE *fptr = fopen("mahasiswa.txt", "r");
    if (fptr == NULL) {
        printf("Belum ada data mahasiswa.\n");
        return;
    }

    Mahasiswa m;
    printf("\n--- DATA MAHASISWA ---\n");
    // Keamanan: Kondisi loop hanya berjalan jika fscanf berhasil membaca tepat 3 kolom.
    // Jika file habis, fscanf mengembalikan EOF, loop berhenti otomatis (tanpa duplikat).
    while (fscanf(fptr, "%d/%[^/]/%f\n", &m.id, m.nama, &m.ipk) == 3) {
        printf("ID: %d | Nama: %s | IPK: %.2f\n", m.id, m.nama, m.ipk);
    }
    fclose(fptr);
}

void updateData() { // --- UPDATE: Mengubah Data Berdasarkan ID ---
    FILE *fileAsli = fopen("mahasiswa.txt", "r");
    FILE *fileTemp = fopen("tamp.txt", "w");

    if (fileAsli == NULL || fileTemp == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    int targetID, ditemukan = 0;
    Mahasiswa m;

    printf("Masukkan ID mahasiswa yang ingin diubah: ");
    scanf("%d", &targetID);

    while (fscanf(fileAsli, "%d/%[^/]/%f\n", &m.id, m.nama, &m.ipk) == 3) {
        if (m.id == targetID) {
            ditemukan = 1;
            printf("Masukkan NAMA BARU untuk ID %d: ", targetID);
            scanf(" %[^\n]", m.nama);
            printf("Masukkan IPK BARU: ");
            scanf("%f", &m.ipk);
        }
        // Tulis data ke file temp (data yang diupdate sudah berubah, data lain tetap)
        fprintf(fileTemp, "%d/%s/%.2f\n", m.id, m.nama, m.ipk);
    }

    fclose(fileAsli);
    fclose(fileTemp);

    if (ditemukan) {
        remove("mahasiswa.txt");
        rename("tamp.txt", "mahasiswa.txt");
        printf("Data berhasil diperbarui!\n");
    } else {
        remove("tamp.txt");
        printf("Mahasiswa dengan ID %d tidak ditemukan.\n", targetID);
    }
}

void hapusData() { // --- DELETE: Menghapus Data Berdasarkan ID ---
    FILE *fileAsli = fopen("mahasiswa.txt", "r");
    FILE *fileTemp = fopen("tamp.txt", "w");

    if (fileAsli == NULL || fileTemp == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    int targetID, ditemukan = 0;
    Mahasiswa m;

    printf("Masukkan ID mahasiswa yang ingin dihapus: ");
    scanf("%d", &targetID);

    while (fscanf(fileAsli, "%d/%[^/]/%f\n", &m.id, m.nama, &m.ipk) == 3) {
        if (m.id == targetID) {
            ditemukan = 1;
            // Jika data target ditemukan, JANGAN tulis ke fileTemp (efektif terhapus)
        } else {
            // Data lain ditulis ulang ke fileTemp
            fprintf(fileTemp, "%d/%s/%.2f\n", m.id, m.nama, m.ipk);
        }
    }

    fclose(fileAsli);
    fclose(fileTemp);

    if (ditemukan) {
        remove("mahasiswa.txt");
        rename("tamp.txt", "mahasiswa.txt");
        printf("Mahasiswa ID %d berhasil dihapus.\n", targetID);
    } else {
        remove("tamp.txt");
        printf("Mahasiswa dengan ID %d tidak ditemukan.\n", targetID);
    }
}

int main() { // --- PROGRAM UTAMA ---
    int pilihan;
    do {
        printf("\n=========== MENU CRUD ===========\n");
        printf("1. Tambah Data (Create)\n");
        printf("2. Tampilkan Data (Read)\n");
        printf("3. Update Data (Update)\n");
        printf("4. Hapus Data (Delete)\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: tambahData(); break;
            case 2: tampilkanData(); break;
            case 3: updateData(); break;
            case 4: hapusData(); break;
            case 5: printf("Terima kasih telah menggunakan program.\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 5);

    return 0;
}

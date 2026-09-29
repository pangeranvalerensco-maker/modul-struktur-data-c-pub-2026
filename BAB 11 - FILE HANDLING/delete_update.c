#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nama[100];
    float ipk;
} Mahasiswa;

void hapusMahasiswa(int targetID) { // Fungsi untuk menghapus mahasiswa berdasarkan ID
    FILE *fileAsli = fopen("mahasiswa.txt", "r");
    FILE *fileTemp = fopen("tamp.txt", "w");

    // 1. SELALU CEK NULL! Jika file asli tidak ada, tidak bisa diapa-apakan.
    if (fileAsli == NULL || fileTemp == NULL) {
        printf("Error: Gagal membuka file!\n");
        return;
    }

    Mahasiswa m;
    int ditemukan = 0; // Penanda untuk tahu apakah data ditemukan

    // 2. Baca data dari file asli satu per satu
    while (fscanf(fileAsli, "%d/%[^/]/%f\n", &m.id, m.nama, &m.ipk) == 3) {
        
        // Jika ID saat ini sama dengan ID yang mau dihapus
        if (m.id == targetID) {
            ditemukan = 1; // Tandai ditemukan
            // JANGAN tulis data ini ke fileTemp (efektif terhapus)
        } else {
            // Jika bukan target, salin data ke fileTemp
            fprintf(fileTemp, "%d/%s/%.2f\n", m.id, m.nama, m.ipk);
        }
    }

    fclose(fileAsli); // 3. Tutup kedua file
    fclose(fileTemp);

    if (ditemukan) { // 4. Proses penggantian file
        remove("mahasiswa.txt"); // Hapus file asli
        rename("tamp.txt", "mahasiswa.txt"); // Ganti nama file temp menjadi file asli
        printf("Mahasiswa dengan ID %d berhasil dihapus.\n", targetID);
    } else {
        // Jika tidak ditemukan, hapus file temp yang sudah tidak berguna
        remove("tamp.txt");
        printf("Mahasiswa dengan ID %d tidak ditemukan.\n", targetID);
    }
}

void updateMahasiswa(int targetID) {
    FILE *fileAsli = fopen("mahasiswa.txt", "r");
    FILE *fileTemp = fopen("tamp.txt", "w");

    if (fileAsli == NULL || fileTemp == NULL) { printf("Gagal buka file\n"); return; }

    Mahasiswa m;
    int ditemukan = 0;

    while (fscanf(fileAsli, "%d/%[^/]/%f\n", &m.id, m.nama, &m.ipk) == 3) {
        if (m.id == targetID) {
            ditemukan = 1;
            printf("Masukkan Nama Baru untuk ID %d: ", targetID);
            scanf(" %[^\n]", m.nama); // Baca nama baru (bisa ada spasi)
            printf("Masukkan IPK Baru: ");
            scanf("%f", &m.ipk);
        }
        // Tulis data (bisa data lama atau data baru yang sudah diubah)
        fprintf(fileTemp, "%d/%s/%.2f\n", m.id, m.nama, m.ipk);
    }

    fclose(fileAsli);
    fclose(fileTemp);

    if (ditemukan) {
        remove("mahasiswa.txt");
        rename("tamp.txt", "mahasiswa.txt");
        printf("Data berhasil diupdate!\n");
    } else {
        remove("tamp.txt");
        printf("ID %d tidak ditemukan.\n", targetID);
    }
}

int main() {
    updateMahasiswa(3); // Contoh: update mahasiswa dengan ID 3
    return 0;
}

// BENAR
fscanf(fptr, "%d/%[^/]/%f\n", &id, nama, &ipk);

// SALAH (yang sering terjadi pada pemula)
fscanf(fptr, "%d/%[^/]/%f\n", id, nama, ipk);


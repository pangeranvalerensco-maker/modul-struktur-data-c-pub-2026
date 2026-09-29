#include <stdio.h>
#include <stdlib.h>

struct node {
    int angka;              // data yang disimpan
    struct node *next;      // pointer ke node berikutnya
} *head = NULL, *tail = NULL, *baru, *bantu;

void enqueue(int data) { // Menambahkan data di belakang queue (tambah di TAIL)
    baru = (struct node*)malloc(sizeof(struct node));
    baru->angka = data;
    baru->next = NULL;          // node baru selalu di akhir

    if (tail == NULL) {         // jika queue kosong
        head = tail = baru;     // head dan tail menunjuk ke node yang sama
    } else {
        tail->next = baru;      // sambungkan tail ke node baru
        tail = baru;            // tail sekarang menunjuk ke node baru
    }
    printf("Data %d ditambahkan ke queue.\n", data);
}

void dequeue() { // Mengambil data dari depan queue (hapus di HEAD)
    if (head == NULL) {
        printf("Queue kosong!\n");
        return;
    }
    bantu = head;               // simpan node depan
    head = head->next;          // pindahkan head ke node berikutnya

    if (head == NULL) {         // jika queue menjadi kosong
        tail = NULL;            // tail juga harus NULL
    }
    free(bantu);                // bebaskan memori node lama
    printf("Data depan dihapus dari queue.\n");
}

int front() { // Melihat data di depan tanpa menghapus
    if (head == NULL) return -1;
    return head->angka;
}

void tampilkanQueue() { // Menampilkan seluruh isi queue dari depan ke belakang
    if (head == NULL) {
        printf("Queue kosong.\n");
        return;
    }
    bantu = head;
    printf("Isi queue (depan->belakang): ");
    while (bantu != NULL) {
        printf("|%d| ", bantu->angka);
        bantu = bantu->next;
    }
    printf("\n");
}

int main() {
    int pilihan, data;
    enqueue(10);
    enqueue(20);
    printf("======== QUEUE DENGAN LINKED LIST =========\n");
    printf("1. Enqueue (Tambah di Belakang)\n");
    printf("2. Dequeue (Ambil dari Depan)\n");
    printf("3. Front (Lihat Depan)\n");
    printf("4. Tampilkan\n");
    printf("5. Keluar\n");
    printf("===========================================\n");
    do {
    printf("Pilih: ");
    scanf("%d", &pilihan);

    
        switch (pilihan) {
            case 1:
                printf("Masukkan angka: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                data = front();
                if (data != -1) printf("Elemen depan: %d\n", data);
                break;
            case 4:
                tampilkanQueue();
                break;
            case 5:
                printf("Keluar.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
    return 0;
}
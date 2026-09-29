#include <stdio.h>
#include <stdlib.h>

#define MAX 10          // kapasitas maksimum queue

int queue[MAX];         // array penyimpan data
int front = -1;         // front = -1 berarti queue kosong
int rear = -1;          // rear = -1 berarti queue kosong

int isEmpty() { // Mengecek apakah queue kosong
    return front == -1 || front > rear; // front > rear menandakan kosong
}

int isFull() { // Mengecek apakah queue penuh
    return rear == MAX - 1;
}

void enqueue(int data) { // Menambahkan data di belakang queue
    if (isFull()) {
        printf("Queue penuh!\n");
        return;
    }
    if (isEmpty()) {
        front = 0;          // jika kosong, front dan rear diatur ke 0
    }
    rear++;                 // naikkan rear
    queue[rear] = data;     // simpan data di posisi rear
    printf("Data %d ditambahkan ke queue.\n", data);
}

void dequeue() { // Mengambil data dari depan queue
    if (isEmpty()) {
        printf("Queue kosong!\n");
        return;
    }
    printf("Data %d diambil dari queue.\n", queue[front]);
    front++;                // majukan front

    if (front > rear) {     // jika front melewati rear, queue kosong
        front = rear = -1;
    }
}

int frontElement() { // Melihat data di depan tanpa menghapus
    if (isEmpty()) return -1;
    return queue[front];
}

void tampilkanQueue() { // Menampilkan seluruh isi queue dari depan ke belakang
    if (isEmpty()) {
        printf("Queue kosong.\n");
        return;
    }
    printf("Isi queue (depan->belakang): ");
    for (int i = front; i <= rear; i++) {
        printf("|%d| ", queue[i]);
    }
    printf("\n");
}

int main() {
    int pilihan, data;
    enqueue(10); // Contoh data awal
    enqueue(20);
    printf("========= QUEUE DENGAN ARRAY =========\n");
    printf("1. Enqueue (Tambah di Belakang)\n");
    printf("2. Dequeue (Ambil dari Depan)\n");
    printf("3. Front (Lihat Depan)\n");
    printf("4. Tampilkan\n");
    printf("5. Keluar\n");
    printf("=====================================\n");
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
                data = frontElement();
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
#include <stdio.h>
#include <stdlib.h>

// ========== DEKLARASI STRUCT DAN POINTER GLOBAL ==========
struct node
{
    int angka;
    struct node *next;
};

struct node *head = NULL;                    // Head global
struct node *baru, *bantu, *cepat, *sebelum; // Pointer bantu global
int count = 0;                               // Counter jumlah node

// ========== FUNGSI-FUNGSI TAMBAH ==========
void tambahDepan(int angka)
{
    baru = (struct node *)malloc(sizeof(struct node));
    if (baru == NULL)
    {
        printf("Gagal alokasi memori!\n");
        return;
    }
    baru->angka = angka;
    baru->next = head;
    head = baru;
    count++;
}

void tambahBelakang(int angka)
{
    baru = (struct node *)malloc(sizeof(struct node));
    if (baru == NULL)
    {
        printf("Gagal alokasi memori!\n");
        return;
    }
    baru->angka = angka;
    baru->next = NULL;
    if (head == NULL)
    {
        head = baru;
    }
    else
    {
        bantu = head;
        while (bantu->next != NULL)
            bantu = bantu->next;
        bantu->next = baru;
    }
    count++;
}

void tambahTengah(int angka)
{
    if (head == NULL)
    {
        tambahDepan(angka);
        return;
    }
    baru = (struct node *)malloc(sizeof(struct node));
    if (baru == NULL)
    {
        printf("Gagal alokasi memori!\n");
        return;
    }
    baru->angka = angka;
    if (head->next == NULL)
    {
        head->next = baru;
        baru->next = NULL;
        count++;
        return;
    }
    int posisiTengah = count / 2;
    bantu = head;
    for (int i = 0; i < posisiTengah; i++)
        bantu = bantu->next;
    baru->next = bantu->next;
    bantu->next = baru;
    count++;
}

void tambahSetelahNilai(int target, int newVal)
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return;
    }
    bantu = head;
    while (bantu != NULL && bantu->angka != target)
        bantu = bantu->next;
    if (bantu == NULL)
    {
        printf("Nilai %d tidak ditemukan\n", target);
        return;
    }
    baru = (struct node *)malloc(sizeof(struct node));
    if (baru == NULL)
    {
        printf("Gagal alokasi memori!\n");
        return;
    }
    baru->angka = newVal;
    baru->next = bantu->next;
    bantu->next = baru;
    count++;
}

void tambahPadaIndeks(int indeks, int newVal)
{
    if (indeks < 0 || indeks > count)
    {
        printf("Indeks %d tidak valid\n", indeks);
        return;
    }
    if (indeks == 0)
    {
        tambahDepan(newVal);
        return;
    }
    baru = (struct node *)malloc(sizeof(struct node));
    if (baru == NULL)
    {
        printf("Gagal alokasi memori!\n");
        return;
    }
    baru->angka = newVal;
    bantu = head;
    for (int i = 0; i < indeks - 1; i++)
        bantu = bantu->next;
    baru->next = bantu->next;
    bantu->next = baru;
    count++;
}

// ========== FUNGSI-FUNGSI HAPUS ==========
void hapusDepan()
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return;
    }
    bantu = head;
    head = head->next;
    free(bantu);
    count--;
}

void hapusBelakang()
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        count--;
        return;
    }
    bantu = head;
    while (bantu->next->next != NULL)
        bantu = bantu->next;
    free(bantu->next);
    bantu->next = NULL;
    count--;
}

void hapusTengah()
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        count--;
        return;
    }
    bantu = head;
    cepat = head;
    sebelum = NULL;
    while (cepat != NULL && cepat->next != NULL)
    {
        sebelum = bantu;
        bantu = bantu->next;
        cepat = cepat->next->next;
    }
    sebelum->next = bantu->next;
    free(bantu);
    count--;
}

void hapusByValue(int nilai)
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return;
    }
    if (head->angka == nilai)
    {
        hapusDepan();
        return;
    }
    bantu = head;
    while (bantu != NULL && bantu->angka != nilai)
    {
        sebelum = bantu;
        bantu = bantu->next;
    }
    if (bantu == NULL)
    {
        printf("Nilai %d tidak ditemukan\n", nilai);
        return;
    }
    sebelum->next = bantu->next;
    free(bantu);
    count--;
}

void hapusByIndex(int indeks)
{
    if (indeks < 0 || indeks >= count)
    {
        printf("Indeks %d tidak valid\n", indeks);
        return;
    }
    if (indeks == 0)
    {
        hapusDepan();
        return;
    }
    bantu = head;
    for (int i = 0; i < indeks; i++)
    {
        sebelum = bantu;
        bantu = bantu->next;
    }
    sebelum->next = bantu->next;
    free(bantu);
    count--;
}

// ========== FUNGSI-FUNGSI PEMBANTU ==========
void tampilkanList()
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }
    bantu = head;
    printf("Isi list: ");
    while (bantu != NULL)
    {
        printf("|%d|->", bantu->angka);
        bantu = bantu->next;
    }
    printf("NULL\n");
}

void cari(int data)
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return;
    }
    bantu = head;
    int indeks = 0, ditemukan = 0;
    while (bantu != NULL)
    {
        if (bantu->angka == data)
        {
            printf("Data %d ditemukan pada indeks %d\n", data, indeks);
            ditemukan++;
        }
        bantu = bantu->next;
        indeks++;
    }
    if (ditemukan == 0)
        printf("Data %d tidak ditemukan\n", data);
}

void updateByValue(int oldVal, int newVal)
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return;
    }
    bantu = head;
    while (bantu != NULL)
    {
        if (bantu->angka == oldVal)
        {
            bantu->angka = newVal;
            printf("Nilai %d diubah menjadi %d\n", oldVal, newVal);
            return;
        }
        bantu = bantu->next;
    }
    printf("Data %d tidak ditemukan\n", oldVal);
}

void updateByIndex(int indeks, int newVal)
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return;
    }
    if (indeks < 0 || indeks >= count)
    {
        printf("Indeks %d tidak valid\n", indeks);
        return;
    }
    bantu = head;
    for (int i = 0; i < indeks; i++)
        bantu = bantu->next;
    bantu->angka = newVal;
    printf("Nilai pada indeks %d diubah menjadi %d\n", indeks, newVal);
}

void cekMax()
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return;
    }
    int max = head->angka;
    bantu = head;
    while (bantu != NULL)
    {
        if (bantu->angka > max)
            max = bantu->angka;
        bantu = bantu->next;
    }
    printf("Nilai maksimum: %d\n", max);
}

void cekMin()
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return;
    }
    int min = head->angka;
    bantu = head;
    while (bantu != NULL)
    {
        if (bantu->angka < min)
            min = bantu->angka;
        bantu = bantu->next;
    }
    printf("Nilai minimum: %d\n", min);
}

void cekAverage()
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return;
    }
    int sum = 0;
    bantu = head;
    while (bantu != NULL)
    {
        sum += bantu->angka;
        bantu = bantu->next;
    }
    printf("Rata-rata: %.2f\n", (float)sum / count);
}

void cekSum()
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return;
    }
    int sum = 0;
    bantu = head;
    while (bantu != NULL)
    {
        sum += bantu->angka;
        bantu = bantu->next;
    }
    printf("Jumlah total: %d\n", sum);
}

void tampilkanMenu()
{
    system("cls");
    printf("====================================\n");
    printf("   LINKED LIST - MANAJEMEN DATA\n");
    printf("====================================\n");
    printf("1. Tambah Depan\n");
    printf("2. Tambah Belakang\n");
    printf("3. Tambah Tengah\n");
    printf("4. Tambah Setelah Nilai\n");
    printf("5. Tambah Pada Indeks\n");
    printf("6. Hapus Depan\n");
    printf("7. Hapus Belakang\n");
    printf("8. Hapus Tengah\n");
    printf("9. Hapus Berdasarkan Nilai\n");
    printf("10. Hapus Berdasarkan Indeks\n");
    printf("11. Update Berdasarkan Nilai\n");
    printf("12. Update Berdasarkan Indeks\n");
    printf("13. Cari Data\n");
    printf("14. Cek Nilai Maksimum\n");
    printf("15. Cek Nilai Minimum\n");
    printf("16. Cek Rata-rata\n");
    printf("17. Cek Jumlah Total\n");
    printf("18. Tampilkan List\n");
    printf("19. Keluar\n");
    printf("====================================\n");
    printf("Pilih: ");
}

// ========== FUNGSI MAIN ==========
int main()
{
    int pilihan, angka, target, indeks, oldVal, newVal;

    do
    {
        tampilkanMenu();
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Masukkan angka: ");
            scanf("%d", &angka);
            tambahDepan(angka);
            break;
        case 2:
            printf("Masukkan angka: ");
            scanf("%d", &angka);
            tambahBelakang(angka);
            break;
        case 3:
            printf("Masukkan angka: ");
            scanf("%d", &angka);
            tambahTengah(angka);
            break;
        case 4:
            tampilkanList();
            printf("Masukkan nilai target: ");
            scanf("%d", &target);
            printf("Masukkan nilai baru: ");
            scanf("%d", &newVal);
            tambahSetelahNilai(target, newVal);
            getchar();
            getchar();
            break;
        case 5:
            tampilkanList();
            printf("Masukkan indeks: ");
            scanf("%d", &indeks);
            printf("Masukkan nilai baru: ");
            scanf("%d", &newVal);
            tambahPadaIndeks(indeks, newVal);
            getchar();
            getchar();
            break;
        case 6:
            hapusDepan();
            break;
        case 7:
            hapusBelakang();
            break;
        case 8:
            hapusTengah();
            break;
        case 9:
            tampilkanList();
            printf("Masukkan nilai yang ingin dihapus: ");
            scanf("%d", &angka);
            hapusByValue(angka);
            getchar();
            getchar();
            break;
        case 10:
            tampilkanList();
            printf("Masukkan indeks yang ingin dihapus: ");
            scanf("%d", &indeks);
            hapusByIndex(indeks);
            getchar();
            getchar();
            break;
        case 11:
            tampilkanList();
            printf("Masukkan nilai yang ingin diupdate: ");
            scanf("%d", &oldVal);
            printf("Masukkan nilai baru: ");
            scanf("%d", &newVal);
            updateByValue(oldVal, newVal);
            getchar();
            getchar();
            break;
        case 12:
            tampilkanList();
            printf("Masukkan indeks yang ingin diupdate: ");
            scanf("%d", &indeks);
            printf("Masukkan nilai baru: ");
            scanf("%d", &newVal);
            updateByIndex(indeks, newVal);
            getchar();
            getchar();
            break;
        case 13:
            tampilkanList();
            printf("Masukkan nilai yang dicari: ");
            scanf("%d", &angka);
            cari(angka);
            getchar();
            getchar();
            break;
        case 14:
            cekMax();
            getchar();
            getchar();
            break;
        case 15:
            cekMin();
            getchar();
            getchar();
            break;
        case 16:
            cekAverage();
            getchar();
            getchar();
            break;
        case 17:
            cekSum();
            getchar();
            getchar();
            break;
        case 18:
            tampilkanList();
            getchar();
            getchar();
            break;
        case 19:
            printf("Keluar dari program...\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
            getchar();
            getchar();
        }
    } while (pilihan != 19);

    return 0;
}
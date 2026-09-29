#include <stdio.h>

int main()
{
    int nilai = 85;
    int *ptr = &nilai;

    printf("Nilai awal: %d\n", nilai);

    *ptr = 100; // mengubah nilai variabel asli lewat pointer

    printf("Nilai setelah diubah: %d\n", nilai);
    return 0;
}
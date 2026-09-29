#include <stdio.h>

int main()
{
    int b = 2;
    int *b2 = &b; // b2 menyimpan alamat b (b2 menunjuk ke b)

    printf("Sebelum b diubah: *b2 = %d\n", *b2);
    b = 3; // b diubah
    printf("Setelah b diubah: *b2 = %d\n", *b2);
    return 0;
}
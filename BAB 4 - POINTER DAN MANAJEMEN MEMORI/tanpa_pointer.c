#include <stdio.h>

int main()
{
    int a = 2;
    int a2 = a; // a2 menyalin nilai a

    printf("Sebelum a diubah: a2 = %d\n", a2);
    a = 3; // a diubah
    printf("Setelah a diubah: a2 = %d\n", a2);
    return 0;
}
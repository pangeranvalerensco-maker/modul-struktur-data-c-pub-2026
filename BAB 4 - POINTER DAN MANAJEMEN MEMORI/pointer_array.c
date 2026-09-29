#include <stdio.h>

int main()
{
    int nilai[3] = {85, 90, 78};
    int *ptr = nilai; // ptr menunjuk ke elemen pertama (nilai[0])

    printf("nilai[0] = %d\n", nilai[0]);
    printf("*ptr     = %d\n", *ptr);
    printf("ptr[0]   = %d\n", ptr[0]); // pointer bisa pakai kurung siku

    printf("*(ptr+1) = %d\n", *(ptr + 1)); // sama dengan nilai[1]
    printf("*(ptr+2) = %d\n", *(ptr + 2)); // sama dengan nilai[2]

    printf("alamat nilai %p\n", &nilai);
    printf("alamat nilai[0] %p\n", &nilai[0]);
    printf("alamat nilai[1] %p\n", &nilai[1]);
    printf("alamat nilai[2] %p\n", &nilai[2]);

    return 0;
}
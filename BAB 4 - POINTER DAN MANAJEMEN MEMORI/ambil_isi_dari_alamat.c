#include <stdio.h>
int main() {
    int *pu;    // pointer ke int 
    int nu;     // variabel int
    int u = 2022; // variabel int

    pu = &u;    // int* ke int*
    nu = *pu;  // mengambil nilai dari alamat yang ditunjuk pu

    printf("Alamat dari u = %p\n", &u);
    printf("Isi pu = %p\n", pu);
    printf("Isi u = %d\n", u);
    printf("Nilai yang ditunjuk oleh pu = %d\n", *pu);
    printf("Nilai nu = %d\n", nu);

    return 0;
}
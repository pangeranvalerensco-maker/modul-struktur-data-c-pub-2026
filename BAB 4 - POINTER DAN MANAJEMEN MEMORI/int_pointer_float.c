#include <stdio.h>

void main() {
    float *pu;   // pointer ke float (sudah sesuai)
    float nu;    // variabel float
    float u = 2022;  // variabel float

    pu = &u;     // ✅ tipe cocok: float* ke float*
    nu = *pu;    // mengambil nilai dari alamat yang ditunjuk pu

    printf("Alamat dari u = %p\n", &u);
    printf("Isi pu = %p\n", pu);
    printf("Isi u = %f\n", u);
    printf("Nilai yang ditunjuk oleh pu = %f\n", *pu);
    printf("Nilai nu = %f\n", nu);
}
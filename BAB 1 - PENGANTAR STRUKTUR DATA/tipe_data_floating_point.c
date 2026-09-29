#include <stdio.h>

int main() {

    // float: digunakan untuk nilai pecahan 
    // dengan ketelitian standar
    float suhuTubuh = 36.5;
    printf("Suhu tubuh manusia: %.1f derajat\n\n", suhuTubuh);

    // double: digunakan untuk nilai pecahan 
    // dengan ketelitian lebih tinggi
    double nilaiPi = 3.141592;
    printf("Nilai PI: %.6lf\n\n", nilaiPi);

    return 0;
}
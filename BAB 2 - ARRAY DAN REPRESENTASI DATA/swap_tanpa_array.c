#include <stdio.h>

int main(){
    int a = 10;
    int b = 20;
    int temp; // gelas kosong

    // Proses swap
    temp = a; // 1. simpan nilai a ke temp (temp = 10)
    a = b;    // 2. isi a dengan nilai b (a = 20)
    b = temp; // 3. isi b dengan nilai temp (b = 10)

    printf("a = %d, b = %d\n", a, b); // Output: a = 20, b = 10
    
    return 0;
}
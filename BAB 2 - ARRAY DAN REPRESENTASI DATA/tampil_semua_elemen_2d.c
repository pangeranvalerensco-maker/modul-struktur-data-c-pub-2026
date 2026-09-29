#include <stdio.h>

int main() {
    int nilai[3][2] = {{85, 90}, {78, 82}, {92, 88}};

    for(int i = 0; i < 3; i++) {        // loop baris
        for(int j = 0; j < 2; j++) {    // loop kolom
            printf("nilai[%d][%d] = %d\n", i, j, nilai[i][j]);
        }
    }
    return 0;
}
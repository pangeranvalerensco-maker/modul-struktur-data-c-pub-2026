#include <stdio.h>

int main()
{
    // int data[2][3][4]; // 2 lantai × 3 baris × 4 kolom = 24 elemen

    int data[2][3][4] = {
        {
            // lantai 0
            {1, 2, 3, 4},   // baris 0
            {5, 6, 7, 8},   // baris 1
            {9, 10, 11, 12} // baris 2
        },
        {// lantai 1
         {13, 14, 15, 16},
         {17, 18, 19, 20},
         {21, 22, 23, 24}}};

    for (int i = 0; i < 2; i++)
    { // lantai
        for (int j = 0; j < 3; j++)
        { // baris
            for (int k = 0; k < 4; k++)
            { // kolom
                printf("%d ", data[i][j][k]);
            }
            printf("\n");
        }
        printf("---\n");
    }

}
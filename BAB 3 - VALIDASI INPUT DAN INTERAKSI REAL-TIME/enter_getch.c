#include <stdio.h>
#include <conio.h>

int main()
{
    char tombol;

    printf("Ketik sesuatu: ");
    while (1)
    {
        tombol = getch();
        if (tombol == 13)
            break;            // Enter 13 -> selesai
        printf("%c", tombol); // tampilkan karakter
    }
    printf("\nSelesai.\n");
    return 0;
    int tombol;
    printf("\a"); // speaker berbunyi sekali
}

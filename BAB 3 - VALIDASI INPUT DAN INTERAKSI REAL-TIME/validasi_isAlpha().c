void inputHuruf(char *buffer, int maxPanjang, int izinkanSpasi)
{
    int idx = 0;
    char tombol;
    while (1)
    {
        tombol = getch();
        if (isalpha(tombol))
        {
            if (idx < maxPanjang - 1)
            {
                // Kapitalisasi otomatis (tetap gunakan toupper/tolower)
                if (idx == 0 || (idx > 0 && buffer[idx - 1] == ' '))
                {
                    tombol = toupper(tombol);
                }
                else
                {
                    tombol = tolower(tombol);
                }
                buffer[idx++] = tombol;
                printf("%c", tombol);
            }
            else
            {
                printf("\a");
            }
        }
        else if (izinkanSpasi && isspace(tombol) && tombol == ' ' && idx > 0 && buffer[idx - 1] != ' ')
        {
            // Hanya spasi biasa, bukan tab atau newline
            if (idx < maxPanjang - 1)
            {
                buffer[idx++] = tombol;
                printf("%c", tombol);
            }
            else
            {
                printf("\a");
            }
        }
        else if (tombol == 8 && idx > 0)
        { /* backspace */
        }
        else if (tombol == 13 && idx > 0)
        { /* enter */
        }
        else
        {
            printf("\a");
        }
    }
}
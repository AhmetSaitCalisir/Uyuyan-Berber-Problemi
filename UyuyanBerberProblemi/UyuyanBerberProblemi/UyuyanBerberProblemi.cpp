#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
char Gelen;
char Musteri[5] = { 'b','b','b','b','b' };
int MusteriSayisi = 0;
bool Uyumuyor = true;
DWORD WINAPI Berber(LPVOID lpParam)
{
    while (true)
    {
        if (Musteri[0] == 'd')
        {
            MusteriSayisi++;
            printf("%i. musterinin saci kesiliyor\n", MusteriSayisi);
            Sleep(5000);
            printf("%i. musterinin sac kesimi bitti\n", MusteriSayisi);
            Musteri[0] = Musteri[1];
            Musteri[1] = Musteri[2];
            Musteri[2] = Musteri[3];
            Musteri[3] = Musteri[4];
            Musteri[4] = 'b';
            Uyumuyor = true;
        }
        if (Musteri[0] == 'b' && Uyumuyor)
        {
            printf("Berber uyuyor\n");
            Uyumuyor = false;
        }
    }
    return 0;
}
DWORD WINAPI MusteriTakip(LPVOID lpPAram)
{
    while (true)
    {
        while (Musteri[0] == 'b')
        {
            Musteri[0] = Musteri[1];
            Musteri[1] = Musteri[2];
            Musteri[2] = Musteri[3];
            Musteri[3] = Musteri[4];
            Musteri[4] = 'b';
        }
    }
    return 0;
}
int main()
{
    printf("Berber dukkanina hos geldiniz.\nCikmak icin space\nMusteri eklemek icin m tusuna basiniz\n");
    HANDLE hThread;
    DWORD ThreadID;
    hThread = CreateThread(NULL, 0, MusteriTakip, NULL, 0, &ThreadID);
    if (hThread == NULL)
    {
        printf("HATA\n");
    }
    hThread = CreateThread(NULL, 0, Berber, NULL, 0, &ThreadID);
    if (hThread == NULL)
    {
        printf("HATA\n");
    }

    while (true)
    {
        Gelen = getchar();
        if (Gelen == ' ')
        {
            printf("Cikis yapiliyor\n");
            exit(0);
        }
        if (Gelen == 'm')
        {
            if (Musteri[0] == 'b')
            {
                printf("Birinci Koltuga Oturabilirsiniz\n");
                Musteri[0] = 'd';
            }
            else if (Musteri[1] == 'b')
            {
                printf("Ikinci Koltuga Oturabilirsiniz\n");
                Musteri[1] = 'd';
            }
            else if (Musteri[2] == 'b')
            {
                printf("Ucuncu Koltuga Oturabilirsiniz\n");
                Musteri[2] = 'd';
            }
            else if (Musteri[3] == 'b')
            {
                printf("Dorduncu Koltuga Oturabilirsiniz\n");
                Musteri[3] = 'd';
            }
            else if (Musteri[4] == 'b')
            {
                printf("Besinci Koltuga Oturabilirsiniz\n");
                Musteri[4] = 'd';
            }
            else
            {
                printf("Maalesef tum koltuklar dolu \n");
            }
        }
    }
}

#include <stdio.h>
#include <stdlib.h>


int aracDizi[10][4];
int UcretDizi[10];
int main()
{
    int aracPlaka,aracGirisSaati,aracCikisSaati,aracTipi,islemNo,sayac=0,i=0;
    do
    {
        printf("\n\n---MENU---\n\n");
        printf("Otoparka Aracinizi Eklemek Icin ---> 1'e Basiniz\n");
        printf("Otoparktaki Araclari Listelemek Icin ---> 2'ye Basiniz\n");
        printf("Otoparktaki Aracinizin Ucreti Gormek Icin ---> 3'e Basiniz\n");
        printf("Otoparktaki Araclardan Odenecek Maksimum Ve Minimum Ucreti Ogrenmek Icin---> 4'e Basiniz\n");
        printf("Cikis Icin---> 5'e Basiniz\n");
        printf("\n\n---GIRIS BILGILERI---\n\n");
        printf("Islem Numarisini Seciniz :\t");
        scanf("%d",&islemNo);

        switch (islemNo)
        { case 1:
           {
             if(i >= 10)
              {
                printf("\nOtopark kapasitesi dolmustur...");
                break;
              }
             else
              {
               printf("Arac Tipleri:\n");
               printf("Araciniz Motorsiklet Tipindeyse -> 1'e Basiniz\n");
               printf("Araciniz Otomobil/Taksi Tipindeyse -> 2'ye Basiniz\n");
               printf("Araciniz Diger Tiplerdense -> 3'e Basiniz\n");
               do
                {
                  printf("\nArac Tipini Seciniz :\t\n");
                  scanf("%d",&aracTipi);

                  switch  (aracTipi)
                   {
                     case 1:
                      {
                        aracDizi[i][0] = aracTipi;
                        printf("Motorsiklet Tipini Sectiniz...\n");
                        break;
                      }
                     case 2:
                      {
                        aracDizi[i][0] = aracTipi;
                        printf("Otomobil/Taksi Tipini Sectiniz... \n");
                        break;
                      }
                     case 3:
                      {
                        aracDizi[i][0] = aracTipi;
                        printf("Diger Tipini Sectiniz... \n");
                        break;
                      }
                     default :
                      {
                        printf("Tanimlanmamis Arac Tipi Girdiniz...\n");
                      }
                   }
                }  while(aracTipi < 1 || aracTipi > 3);

             printf("\nAracinizin Plakasini Giriniz : \t\n");
             scanf("%d", &aracPlaka);
             aracDizi[i][1] = aracPlaka;
          do
          {
            sayac++;
            if (sayac>1)
            {
                printf("Aracin Giris Saati ve/veya Cikis Saati Hatali Olmustur...");
            }
            printf("\nAracinizin Otoparka Giris Saatini Giriniz : \t\n");
            scanf("%d", &aracGirisSaati);
            aracDizi[i][2] = aracGirisSaati;
            printf("\nAracinizin Otoparktan Cikis Saatini Giriniz : \t\n");
            scanf("%d", &aracCikisSaati);
            aracDizi[i][3] = aracCikisSaati;
          } while (aracCikisSaati<aracGirisSaati || aracCikisSaati>24 || aracGirisSaati>24 || aracCikisSaati<0 || aracGirisSaati<0);
          sayac=0;

           UcretHesapla(aracDizi,aracPlaka);

           printf("\nArac Bilgileriniz Basariyla Kaydedildi...\n");
           i++;
          }
          break;
         }
        case 2:
         {
           AracListele();
           break;
         }
        case 3:
         {
           int plaka = 0;
           printf("\nUcretini Gormek Istediginiz Aracin Plakasini Giriniz :\t");
           scanf("%d", &plaka);
           printf("\n%d Plakali Aracin Odeyecegi Tutar : %d" ,plaka, UcretHesapla(aracDizi,plaka));
           break;
         }
        case 4:
         {
           printf("\nOtoparktaki Minimum Ucret : %d", MinUcretBul(UcretDizi));
           printf("\nOtoparktaki Maksimum Ucret : %d", MaksUcretBul(UcretDizi));
           break;
         }
        case 5:
         {
           break;
         }
        default :
           printf("\nTanimlanmamis Islem Numarasi Sectiniz..\n");
       }
     }while(islemNo!=5);
    return 0;
}
void  AracListele()
{
  int i = 0 ;
  for(i =0; i<10; i++)
   {
     if(aracDizi[i][0] != 0)
      {
        printf("%d. Aracin Tipi : %d \n", i+1, aracDizi[i][0]);
        printf("%d. Aracin Plakasi : %d \n", i+1, aracDizi[i][1]);
        printf("%d. Aracin Giris saati: %d \n", i+1, aracDizi[i][2]);
        printf("%d. Aracin Cikis saati : %d \n", i+1, aracDizi[i][3]);
      }
    }
}
int UcretHesapla(int arabadizi[], int plaka)
{
   int ucret=0 , i , j=0;
   for(i =0; i<10; i++)
    {
      if(aracDizi[i][1] == plaka)
       {
          j = 1;
          if(aracDizi[i][0] == 1)
           {
             ucret += (5+((aracDizi[i][3]-aracDizi[i][2])*1));
           }
          else if(aracDizi[i][0] == 2)
           {
             ucret += (5+((aracDizi[i][3]-aracDizi[i][2])*2));
           }
          else  if(aracDizi[i][0] == 3)
           {
             ucret += (5+((aracDizi[i][3]-aracDizi[i][2])*3));
           }
          UcretDizi[i]=ucret;
       }
     }
   if(j == 0)
     {
       printf("\nAranan Plakaya Sahip Arac Bulunamadi...");
     }
   return ucret;
}
int MaksUcretBul(int UcretDizi[])
{
   int i=0 , maksimum = UcretDizi[0];
   for(i=0; i<10;i++)
    {
       if (maksimum<UcretDizi[i])
       {
           maksimum=UcretDizi[i];
       }
    }
   return maksimum;
}
int MinUcretBul(int UcretDizi[])
{
   int i=0 , minimum = UcretDizi[0];
   for(i=0; i<10;i++)
    {
       if (minimum>UcretDizi[i]&&UcretDizi[i]!=0)
       {
           minimum=UcretDizi[i];
       }
    }
   return minimum;
}

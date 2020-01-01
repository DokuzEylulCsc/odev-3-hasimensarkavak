#include <iostream>
#include<fstream>

// Haþim Ensar KAVAK 2018280027

using namespace std;
int main()
{
    ifstream oku("input.txt");
    int soruSayisi;
    oku >> soruSayisi;
    cout <<"Soru sayisi "<< soruSayisi<<" olarak alindi."<< endl;
    string cvp;
    oku >> cvp;
    int sayac = cvp.length();
    char cvpa[soruSayisi];
    int i = 0, j = 0;
    while (i < sayac)          //Cevap anahtarindaki "," lerden kurtulmak için yaptim.
    {
        cvpa[j] = cvp[i];
        i += 2;
        j++;
    }

    cout << "Cevap Anahtari: ";
    for (int a = 0; a < soruSayisi; a++)
    {
        cout << cvpa[a];
    }
    cout << endl;
    cout << "Ogrencilerin Bos Cevaplarinda (input.txt de) 0 Yazili "<<endl; // input.txt de bos birakilan sorulara "0" yazdim.
    int ogrSayisi = 0;
    string ogrNo[100];
    string ogrCvp[100];
  
    while (oku) //input.txt de 1. sütunu ogrNo dizine 2. sütunu ogrCvp dizine attim.
    {
        oku >> ogrNo[ogrSayisi] >> ogrCvp[ogrSayisi]; 
        ogrSayisi++;
    }
   

    int puan[ogrSayisi-1] = {0};    //ogrSayisi while da fazladan 1 arttığı için -1 yapıp kullandım.
    int dogru[ogrSayisi-1] = {0};
    int yanlis[ogrSayisi-1]= { 0 };
    int bos[ogrSayisi-1]= { 0 };
    int x = 0;
    for (i = 0; i < ogrSayisi-1; i++) // ögrencilerin dogru yanlis bos sayilarini tuttum.
    {

        x = 0;
        for (j = 0; j < 19; j++)
        {
            if (ogrCvp[i][j] != ',')
            {
                if (cvpa[x] == ogrCvp[i][j])
                {
                    dogru[i]++;
                }
                else if (ogrCvp[i][j] == '0')
                {
                    bos[i]++;
                }
                else
                {
                    yanlis[i]++;
                }
                x++;
                j++;

            }
        }
    }

    cout << "Ogrencilerin Puanlari: (max 40 puan)"<<endl; //örnekteki gibi 40 puan üzerinden sinav.
    int q = 0;
    while (q < ogrSayisi - 1)
    {
        puan[q] = dogru[q] * 4; //dogrular +4 yanlislar -1.
        puan[q] = puan[q] + yanlis[q] * -1;

        if (puan[q] < 0)
        {
            puan[q] = 0;// negatif bir sonuç olmamasi için.
        }
        cout <<ogrNo[q]<<" "<< puan[q] << endl;
        q++;
    }
    int temp;
    string tutucu;
    for ( i = 0; i < ogrSayisi-1; i++) // siralama yaptirdim ,ögrenci numaralarinida puanlara göre siralattim.
    { 
        for ( j = i + 1; j < ogrSayisi-1; j++) 
        {
            if (puan[j] > puan[i]) 
            {
                temp = puan[i];
                tutucu = ogrNo[i];
                puan[i] = puan[j];
                ogrNo[i] = ogrNo[j];
                puan[j] = temp;
                ogrNo[j] = tutucu;
            }
        }
    }
    int enKucuk = 0;
    for (i = 0; i < ogrSayisi - 1; i++)
    {
        if (puan[i] < enKucuk) //En düsük puani buldum.
        {
            enKucuk = puan[i];
        }
    }
   
    int toplam = 0;
    int ortalama = 0;
    for (i = 0; i < ogrSayisi - 1; i++)
    {
        toplam = toplam + puan[i];
    }
    ortalama = toplam / (ogrSayisi-1);
    
    int medyan ;
    int s1= 0,s2=0,s3=0;
    if ((ogrSayisi - 1) % 2 == 0) // medyan hesaplattim.(tek sayilik dizi ve çift sayilik dizi için)
    {
        s1 = ((ogrSayisi - 1) / 2)-1;
        s2 = ((ogrSayisi - 1) / 2);
        medyan = (puan[s1] + puan[s2]) / 2;
    }
    else
    {
        s3 = ((ogrSayisi - 1) / 2);
        medyan = puan[s3];
    }
   
    int aciklik;
    aciklik = puan[0] - enKucuk;// puan[0] da en büyük puan tutuluyor
   
    oku.close();

    ofstream output("output.txt");
    i = 0;
    output << "Ögrencilerin Notlara Göre Sýrasý:" << endl;
    output << "*********************************" << endl;
    output << "    Ogrenci No   Puan"<<endl;
    while (i < ogrSayisi - 1)
    {
        output <<i+1<<".  "<< ogrNo[i] << "   " << puan[i] << endl;
        i++;
    }
    output << "*********************************" << endl;
    output << "En Dusuk Not: " << enKucuk << " ";
    output << "En Yuksek Not: " << puan[0] << " ";
    output <<"Ortalama: "<<ortalama<<" ";
    output << "Medyan: " << medyan << " ";
    output << "Aciklik: " << aciklik << " ";
    cout << endl;
    cout << "Dosyaniz Hazir....";
    cout << endl;
    output.close();
    return 0;
    


}
/*   KAYNAKLAR
    udemy Kaan Academy C++
    https://www.youtube.com/watch?v=rZLZ4hvGGvQ&list=PLK6Whnd55IH6uPjNSDd6_MCgasOgk_6Ry&index=32
    https://www.youtube.com/watch?v=917_ukjO0sg&list=PLK6Whnd55IH6uPjNSDd6_MCgasOgk_6Ry&index=42
*/


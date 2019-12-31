#include <iostream>
#include<fstream>

// Ha�im Ensar KAVAK 2018280027

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
    char cvpa[100];
    int i = 0, j = 0;
    while (i < sayac)          //Cevap anahtar�ndaki "," lerden kurtulmak i�in yapt�m.
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
    cout << "Ogrencilerin Bos Cevaplarinda (input.txt de) 0 Yazili "<<endl; // input.txt de bo� b�rak�lan sorulara "0" yazd�m.
    int ogrSayisi = 0;
    string ogrNo[100];
    string ogrCvp[100];
  
    while (oku) //input.txt de 1. s�tunu ogrNo dizine 2. s�tunu ogrCvp dizine att�m.
    {
        oku >> ogrNo[ogrSayisi] >> ogrCvp[ogrSayisi]; 
        ogrSayisi++;
    }
   

    int puan[100] = {0};
    int dogru[100] = {0};
    int yanlis[100]= { 0 };
    int bos[100]= { 0 };
    int x = 0;
    for (i = 0; i < ogrSayisi-1; i++) // ��rencilerin d��ru yanl�� bo� say�lar�n� tuttum.
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

    cout << "Ogrencilerin Puanlari: (max 40 puan)"<<endl; //�rnekteki gibi 40 puan �zerinden s�nav.
    int q = 0;
    while (q < ogrSayisi - 1)
    {
        puan[q] = dogru[q] * 4; //dogrular +4 yanl��lar -1.
        puan[q] = puan[q] + yanlis[q] * -1;

        if (puan[q] < 0)
        {
            puan[q] = 0;// negatif bir sonu� olmamas� i�in.
        }
        cout <<ogrNo[q]<<" "<< puan[q] << endl;
        q++;
    }
    int temp;
    string tutucu;
    for ( i = 0; i < ogrSayisi-1; i++) // s�ralama yapt�rd�m ,��renci numaralar�n�da puanlara g�re s�ralatt�m.
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
        if (puan[i] < enKucuk) //En d���k puan� buldum.
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
    if ((ogrSayisi - 1) % 2 == 0) // medyan hesaplatt�m.(tek say�l�k dizi ve �ift say�l�k dizi i�in)
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
    aciklik = puan[0] - enKucuk;// puan[0] da en b�y�k puan tutuluyor
   
    oku.close();

    ofstream output("output.txt");
    i = 0;
    output << "�grencilerin Notlara G�re S�ras�:" << endl;
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


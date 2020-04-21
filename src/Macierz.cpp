#include "Macierz.hh"
#include "Wektor.hh"

Wektor Macierz::operator[](int i) const{
    return Kolumna[i];
}
Wektor &Macierz::operator[](int i){
    return Kolumna[i];
}

std::istream& operator >> (std::istream &Strm, Macierz &Mac){
    for(int i=0; i<ROZMIAR; i++)
    Strm>>Mac[i];

    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac){
    for(int i=0; i<ROZMIAR; i++)
    Strm<<Mac[i]<<std::endl;
    return Strm;
}
////////////////////////////////////////////////////////////////
Macierz Macierz::Odejmowanie(Macierz Odjemna, Macierz Odjemnik){
    Macierz M4_wynik;
    for(int i=0; i<10; i++){//chyba powinnam zmienic ROZMIAR, ale na razie niech tak bedzie
        for(int j=0; j<10; j++){
        M4_wynik[i][j]=Odjemna.Kolumna[i][j]-Odjemnik.Kolumna[i][j];
        }
    }
    return  M4_wynik;
}

Macierz Macierz::Mnozenie(Macierz Czynnik1, Macierz Czynnik2){
    Macierz M7_iloczyn;
    
    for(int k=0; k<10; k++){
        for(int j=0; j<10; j++){
            for(int i=0; i<10; i++){
                for(int h=0; h<10; h++){
                    M7_iloczyn[j][k]+=Czynnik1.Kolumna[i][h]*Czynnik2.Kolumna[i][h];
                }
            }//pierwszy element
        }//linia
    }//macierz, cos myle logicznie, m7 ma byc stale a zmieniac sie indeksy czynnikow, pewnie da sie krocvej i mniej petli :D

    return  M7_iloczyn;
}
//////////////////////////////////////////////////////////////////
Macierz Macierz::Kwadrat(){//kazdy element macierzy podnosi sie do kwadratu
    Macierz Macierz_Spotegowana;
    for(int i=0; i<ROZMIAR; i++){
        for(int j=0; j<ROZMIAR; j++){
        Macierz_Spotegowana[i][j]=Kolumna[i][j]*Kolumna[i][j];
        }
    }
    return  Macierz_Spotegowana;
}

 void Macierz::Wyznacznik_Gauss(){
     Macierz kopia=*this;
     int j;
     Wyznacznik=1;
     for(int i=0; i<ROZMIAR; i++){
         j=i;
         while(kopia[i][i]==0){
             j++;
             if(j<ROZMIAR)
             std::swap(kopia[i],kopia[j]);
             else{
                 Wyznacznik=0;
                 return;
             }
         }
         for(int k=i+1; k<ROZMIAR; k++){
            kopia[k]=kopia[k]-kopia[i]*(kopia[k][i]/kopia[i][i]);
         }
         Wyznacznik=Wyznacznik*kopia[i][i];
     }
 }
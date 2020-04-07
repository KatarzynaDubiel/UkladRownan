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

Macierz Kwadrat(Wektor Skladowa){//skladowa z kolumny z macierzy - do dokonczenia
    double SpotegowanyEl;
    for(int i=0; i<ROZMIAR; i++){
        for(int i=0; i<ROZMIAR; i++){
        SpotegowanyEl=SpotegowanyEl*SpotegowanyEl;
        }
    }
}
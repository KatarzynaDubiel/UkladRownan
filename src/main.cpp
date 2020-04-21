#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;

int main(){

  cout<<endl<<" Podaj macierz, od ktorej bedziesz odejmowac: "<<endl<<endl;
  Macierz M2, M3, M4;//Macierze do odjecia i wynikowa
  cin>>M2;

  cout<<endl<<" Podaj macierz, ktora bedziesz odejmowac: "<<endl<<endl;
  cin>>M2;

  M4=Macierz::Odejmowanie(M2, M3);

  cout<<endl<<"Wynik odejmowania macierzy to: "<<endl<<endl<<M4<<endl;

////////////////////////////////////////////////////////////////////////

  cout<<endl<<" Podaj macierz, ktora chcesz pomnozyc: "<<endl<<endl;
  Macierz M5, M6, M7;//Macierze do przemnozenia i wynikowa
  cin>>M5;

  cout<<endl<<" Podaj macierz, przez ktora chcesz pomnozyc: "<<endl<<endl;
  cin>>M6;

  M7=Macierz::Mnozenie(M5, M6);

  cout<<endl<<"Wynik mnozenia macierzy to: "<<endl<<endl<<M7<<endl;

 //////////////////////////////////////////////////////////////////////

  cout<<endl<<" Podaj macierz, ktorej elementy chcesz podniesc do kwadratu: "<<endl<<endl;
  UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej
   Macierz M;//Macierz, ktorej elementy podnosimy do kwadratu
   cin>>M;
   M=M.Kwadrat();
   cout<<endl<<"Macierz z elementami podniesionymi do kwadratu:"<<endl<<endl<<M<<endl;

  cout << endl << " Start programu " <<  endl  <<  endl;
  cin>>UklRown;
  cout<<UklRown;
  switch (UklRown.oblicz_wynik()){

    case JEDNO_ROZWIAZANIE:
      cout<<"Rozwiazanie x = (x1, x2, x3):"<<endl<<endl;
      cout<<UklRown.get_Wek_wynikow()<<endl<<endl;
      cout<<"Wektor bledu Ax-b:"<<endl<<endl;
      cout<<UklRown.get_Wek_Bledow()<<endl<<endl;
      cout<<"Dlugosc wektora bledu ||Ax-b||:"<<endl<<endl;
      cout<<UklRown.get_Dl_Wek_Bledu()<<endl<<endl;
      break;

    case NIESKONCZENIE_WIELE_ROZWIAZAN:
    cout<<"NIESKONCZENIE_WIELE_RZOWIAZAN"<<endl;
    break;

    case BRAK_ROZWIAZAN:
    cout<<"Brak rozwiazan"<<endl;
    break;
  }
}

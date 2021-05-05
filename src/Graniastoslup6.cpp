#include "Graniastoslup6.hh"

using namespace std;

/*!
 * \file Graniastoslup6.cpp
 * \brief Definicja metod klasy Graniastoslup6
 */

/*!
 * \brief Wprowadza wartości współrzędnych wierzchołków i punktów 
 *        charakterystycznych graniastosłupa prawidłowego sześciokątnego.
 * 
 * Konstruktor bezparametryczny. Wprowadza wartości współrzędnych wierzchołków
 * i punktów charakterystycznych graniastosłupa prawidłowego sześciokątnego.
 *   
 * \pre brak
 * \post this musi zawierać współrzędne wierzchołków stworzonego 
 *            graniastosłupa prawidłowego sześciokątnego.
 */
Graniastoslup6::Graniastoslup6()
{
  double  Kat_st, KatSkoku_st = 4*M_PI/ILOSC_WIERZ_GRAN;
  Wektor3D wektor;

  for(int i=0;i<3;++i)
    wektor[i]=0;
  for(int wierz=0; wierz<ILOSC_WIERZ_GRAN+2;++wierz){
     _TabLok.push_back(wektor); /* rezerwowanie pamięci dla bryły */
     _TabGlob.push_back(wektor);
  }
  for(int i=0;i<=1;++i){
    Kat_st=0;
    for(int wierz=i; wierz<ILOSC_WIERZ_GRAN;wierz+=2,Kat_st+=KatSkoku_st)
      {
         _TabLok[wierz][0]=_TabGlob[wierz][0]=-PROMIEN_PODSTAWY*cos(Kat_st);
         _TabLok[wierz][1]=_TabGlob[wierz][1]=PROMIEN_PODSTAWY*sin(Kat_st);
         if(i%2) 
           _TabLok[wierz][2]=_TabGlob[wierz][2]=-0.5*GRUBOSC_ROTORA;
         else
           _TabLok[wierz][2]=_TabGlob[wierz][2]=0.5*GRUBOSC_ROTORA;
      }
  }
  _TabLok[12][2]=_TabGlob[12][2]=0.5*GRUBOSC_ROTORA;
  _TabLok[13][2]=_TabGlob[13][2]=-0.5*GRUBOSC_ROTORA;
} 

/*!
 * \brief Przesuwa podany wirnik na pozycję wzglęgem pozycji drona.
 *
 * Przesuwa podany wirnik na pozycję wzglęgem pozycji drona.
 * \param[in] Pozycja - zmienna reprezentująca pozycję drona w przestrzeni,
 * \param[in] rotor - zmienna reprezentująca numer rotora.
 * \pre brak
 * \post Wykonano przesunięcie. 
 */
void Graniastoslup6::Inicjuj(Wektor3D Pozycja, int rotor)
{
  int j=1,k=1;
  if(rotor%3) j=-1;
  if(rotor>1) k=-1;
  Przesuniecie_Dron[0]=j*10;
  Przesuniecie_Dron[1]=k*12;
  Przesuniecie_Dron[2]=7.5;

  for(unsigned int indeks=0;indeks<_TabGlob.size();indeks++){
    _TabGlob.at(indeks)=_TabGlob.at(indeks)+Przesuniecie_Dron;
    _TabGlob.at(indeks)=_TabGlob.at(indeks)+Pozycja;
  }
}

/*!
 * \brief Usuwa wierzchołki i punkty charakterystyczne graniastosłupa.
 * 
 * Destruktor bezparametryczny. Usuwa wierzchołki i punkty charakterystyczne 
 * graniastosłupa.
 *   
 * \pre brak
 * \post Zawartość obektu (graniastosłupa) musi zostać usunięta.
 */
Graniastoslup6::~Graniastoslup6()
{
  for(int wierz=0; wierz<ILOSC_WIERZ_GRAN+2;++wierz)
    {
       _TabLok.pop_back();  /* usuwanie pamięci bryły */
       _TabGlob.pop_back();
    }
}

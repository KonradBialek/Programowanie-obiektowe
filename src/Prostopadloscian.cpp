#include "Prostopadloscian.hh"

using namespace std;

/*!
 * \file Prostopadloscian.cpp
 * \brief Definicja metod klasy Prostopadloscian
 */

/*!
 * \brief Rezerwuje pamięć dla prostopadłościanu.
 * 
 * Konstruktor bezparametryczny. Rezerwuje pamięć dla prostopadłościanu.
 *   
 * \pre brak
 * \post this musi zawierać współrzędne wierzchołków stworzonego 
 *            prostopadłościanu.
 */
Prostopadloscian::Prostopadloscian()
{
  Wektor3D wektor;
  for(int i=0;i<3;++i)
    wektor[i]=0;
  for(int wierz=0; wierz<ILOSC_WIERZ+2;++wierz){
     _TabLok.push_back(wektor);  /* rezerwowanie pamięci dla bryły */
     _TabGlob.push_back(wektor);
    }
} 
/*!
 * \brief Wprowadza wartości współrzędnych wierzchołków i punktów 
 *        charakterystycznych prostopadłościanu.
 * 
 * Wprowadza wartości współrzędnych wierzchołków
 * i punktów charakterystycznych prostopadłościanu.
 *   
 * \pre brak
 * \post this musi zawierać współrzędne wierzchołków stworzonego 
 *            prostopadłościanu.
 */
void Prostopadloscian::UstalWierzcholki()
{
  for(int wierz=0; wierz<ILOSC_WIERZ;wierz++)
    {
       if(wierz>=2&&wierz<=5)
         _TabLok[wierz][0]=_TabGlob[wierz][0]=0.5*DL_KROTSZEGO_BOKU;
       else
         _TabLok[wierz][0]=_TabGlob[wierz][0]=-0.5*DL_KROTSZEGO_BOKU;
       if(wierz>=4&&wierz<=7) 
         _TabLok[wierz][1]=_TabGlob[wierz][1]=-0.5*DL_DLOZSZEGO_BOKU;
       else
         _TabLok[wierz][1]=_TabGlob[wierz][1]=0.5*DL_DLOZSZEGO_BOKU;
       if(wierz%2) 
         _TabLok[wierz][2]=_TabGlob[wierz][2]=-0.5*DL_POPRZECZNEGO_BOKU;
       else
         _TabLok[wierz][2]=_TabGlob[wierz][2]=0.5*DL_POPRZECZNEGO_BOKU;
    }
  _TabLok[8][2]=_TabGlob[8][2]=0.5*DL_POPRZECZNEGO_BOKU;
  _TabLok[9][2]=_TabGlob[9][2]=-0.5*DL_POPRZECZNEGO_BOKU;
  for(int i=0;i<3;++i)
    Przesuniecie_Dron[i]=0;
}

/*!
 * \brief Przesuwa podany korpus na pozycję wzglęgem pozycji drona.
 *
 * Przesuwa podany korpus na pozycję wzglęgem pozycji drona.
 * \param[in] Pozycja - zmienna reprezentująca pozycję drona w przestrzeni.
 * \pre brak
 * \post Wykonano przesunięcie. 
 */
void Prostopadloscian::Inicjuj(Wektor3D Pozycja)
{
  UstalWierzcholki();
  Przesuniecie_Dron[0]=0;
  Przesuniecie_Dron[1]=0;
  Przesuniecie_Dron[2]=0;

  for(unsigned int indeks=0;indeks<_TabGlob.size();indeks++){
    _TabGlob.at(indeks)=_TabGlob.at(indeks)+Przesuniecie_Dron;
    _TabGlob.at(indeks)=_TabGlob.at(indeks)+Pozycja;
  }
}

/*!
 * \brief Usuwa wierzchołki i punkty charakterystyczne prostopadłościanu.
 * 
 * Destruktor bezparametryczny. Usuwa wierzchołki i punkty charakterystyczne 
 * prostopadłościanu.
 *   
 * \pre brak
 * \post Zawartość obektu (prostopadłościanu) musi zostać usunięta.
 */
Prostopadloscian::~Prostopadloscian()
{
  for(int wierz=0; wierz<ILOSC_WIERZ+2;++wierz)
    {
       _TabLok.pop_back();  /* usuwanie pamięci bryły */
       _TabGlob.pop_back();
    }
}


#include "FabrykaObiektow.hh"

using namespace std;

/*!
 * \file FabrykaObiektow.cpp
 * \brief Definicja metod klasy FabrykaObiektow
 */

/*!
 * \brief Tworzy obiekt o wskazanym typie.
 * 
 * Tworzy obiekt o wskazanym typie.
 * \param[in] Rodzaj - oznaczenie typu obiektu.
 *
 * \pre brak
 * \post brak
 *       
 * \retval Wskaźnik dzielony na nowy obiekt.
 */
std::shared_ptr<ObiektSceny> FabrykaObiektow::StworzObiekt(RodzajObiektu Rodzaj) const
//,Wektor3D Pozycja,double dl,double szer,double wys) const
{
  shared_ptr<ObiektSceny>  WOb;       
  switch(Rodzaj){
  case RO_Dron: //return make_shared<Dron>(_domPozDr);
   { Dron *wRob = new Dron(_domPozDr);
    WOb.reset(wRob);
    return WOb;}
  case RO_PrzeszkodaPr: //return make_shared<PrzeszkodaPr>(_domPozPrz,_domDlPrz,_domSzerPrz,_domWysPrz);
  {  PrzeszkodaPr *wPrze = new PrzeszkodaPr(_domPozPrz,_domDlPrz,_domSzerPrz,_domWysPrz);
    WOb.reset(wPrze);
    return WOb;}
  default: cerr<< "BLAD"<< endl;
  }
  return nullptr;
  return WOb;
}

WskFabryki FabrykaObiektow::_WFabryka;

/*!
 * \brief Tworzy fabrykę.
 *
 * Tworzy fabrykę.
 * \pre Fabryka nie istnieje.
 * \post Stworzono Fabrykę.
 */
void WskFabryki::StworzFabryke() { if (!*this) reset(new FabrykaObiektow()); }


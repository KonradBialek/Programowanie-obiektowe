#include "PrzeszkodaPr.hh"

using namespace std;

/*!
 * \file PrzeszkodaPr.cpp
 * \brief Definicja metod klasy PrzeszkodaPr
 */

/*!
 * \brief Ustawia parametry przeszkody.
 *
 * Konstruktor parametryczny. Ustawia parametry przeszkody.
 * \param[in] PozPr - pozycja przeszkody,
 * \param[in] dl - długość przeszkody,
 * \param[in] szer - szerokość przeszkody,
 * \param[in] wys - wysokość przeszkody.
 *
 * \pre brak
 * \post Ustawiono parametry przeszkody.
 */
PrzeszkodaPr::PrzeszkodaPr(Wektor3D PozPr,double dl,double szer,double wys)
{
  Pozycja=PozPr;
  wysokosc=wys;
  szerokosc=szer;
  dlugosc=dl;
}
/*!
 * \brief Zapisuje przeszkodę.
 *
 * Zapisuje przeszkodę.
 *
 * \pre brak
 * \post Dokonano zapisu.
 *
 * \retval true - po wykonaniu zapisu.
 */
bool PrzeszkodaPr::Zapisz() const
{
  if (!_TabKorpus[0].ZapiszBryle()) return false;
  return true;
}

/*!
 * \brief Inicjuje przeszkodę.
 *
 * Inicjuje przeszkodę.
 * \param[in] i - zmienna reprezentująca numer przeszkody.
 * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem.
 *
 * \pre brak
 * \post Dokonano inicjacji.
 *
 * \retval true - po wykonaniu inicjacji.
 */
void PrzeszkodaPr::Inicjuj(int i,PzG::LaczeDoGNUPlota &Lacze)
{
  UstalPozIWym(i-3);
  UstalWierz();
  _TabKorpus[0].DodajNazwePliku(Lacze);
}

/*!
 * \brief Ustala pozycję i wymiary przeszkody.
 *
 * Ustala pozycję i wymiary przeszkody.
 * \param[in] i - zmienna reprezentująca numer przeszkody.
 *
 * \pre brak
 * \post Wprowadzono dane.
 */
void PrzeszkodaPr::UstalPozIWym(int i)
{
  if(i==0){
    Pozycja[0]=150; dlugosc=60;
    Pozycja[1]=100; szerokosc=40;
    Pozycja[2]=0;   wysokosc=100;
    }
  else if(i==1){
    Pozycja[0]=150; dlugosc=100;
    Pozycja[1]=-50; szerokosc=40;
    Pozycja[2]=0;   wysokosc=25;
    }
  else if(i==2){
    Pozycja[0]=0;   dlugosc=150;
    Pozycja[1]=125; szerokosc=50;
    Pozycja[2]=50;  wysokosc=10;
    }
}
/*!
 * \brief Ustala współrzędne wierzchołków przeszkody.
 *
 * Ustala współrzędne wierzchołków przeszkody.
 *
 * \pre brak
 * \post Wprowadzono dane.
 */
void PrzeszkodaPr::UstalWierz()
{
  for(int wierz=0; wierz<ILOSC_WIERZ;wierz++){
    if(wierz>=2&&wierz<=5)
      _TabKorpus[0][wierz][0]=0.5*dlugosc;
    else
      _TabKorpus[0][wierz][0]=-0.5*dlugosc;
    if(wierz%2)
      _TabKorpus[0][wierz][1]=0.5*szerokosc;
    else
      _TabKorpus[0][wierz][1]=-0.5*szerokosc;
    if(wierz>=4)
      _TabKorpus[0][wierz][2]=0.5*wysokosc;
    else
      _TabKorpus[0][wierz][2]=-0.5*wysokosc;
    }
  _TabKorpus[0][9][1]=0.5*szerokosc;
  _TabKorpus[0][8][1]=-0.5*szerokosc;
  for(int wierz=0; wierz<ILOSC_WIERZ+2;wierz++)
     _TabKorpus[0][wierz]=_TabKorpus[0][wierz]+Pozycja;
} 

/*!
 * \brief Sprawdza czy pozycja kontrolowanego drona znajduje się wewnątrz przeszkody.
 *
 * Sprawdza czy pozycja kontrolowanego drona znajduje się wewnątrz przeszkody.
 * 
 * \param[in] Pozycja - pozycja konrolowanego drona,
 * \param[in] Min - wierzchołek o najmniejszych wartościach 
 *                  współrzędnych spośród wierzchołków przeszkody.
 * \param[in] Max - wierzchołek o największych wartościach 
 *                  współrzędnych spośród wierzchołków przeszkody.
 * \param[in] AproksymPrzeszk - wektor poszerzający przeszkodę o odpowiednie
 *                              wartości.
 * \pre AproksymPrzeszk musi mieć nieujemne wartości składowych.
 * \post brak
 *
 * \retval true - gdy wektor pozycji jest wewnątrz powiększonej przeszkody,
 * \retval false - w przeciwnym wypadku.
 */
bool PrzeszkodaPr::CzyWewnatrz(Wektor3D Pozycja,Wektor3D Min,Wektor3D Max,Wektor3D AproksymPrzeszk) const
{
  Min=Min-AproksymPrzeszk;
  Max=Max+AproksymPrzeszk;
  Pozycja[2]+=AproksymPrzeszk[2]/3;
  if(Min<=Pozycja&&Pozycja<=Max) return true;
  else return false;
}

/*!
 * \brief Sprawdza czy kontrolowany dron koliduje z tą przeszkodą.
 *
 * Sprawdza czy kontrolowany dron koliduje z tą przeszkodą.
 * 
 * \param[in] BiezacyDron - kontrolowany dron.
 * \pre brak
 * \post brak
 *
 * \retval true - gdy nastąpiła kolizja,
 * \retval false - w przeciwnym wypadku.
 */
bool PrzeszkodaPr::CzyKolizja(const Dron &BiezacyDron) const
{
  Wektor3D AproksymPrzeszk;
  AproksymPrzeszk[0]=AproksymPrzeszk[1]=BiezacyDron.Wez_promien();
  AproksymPrzeszk[2]=(BiezacyDron.Wez_wysokosc())/2;

  if(CzyWewnatrz(BiezacyDron.Wez_Wektor_Pozycji(),_TabKorpus[0][0],
                 _TabKorpus[0][5],AproksymPrzeszk))
    return true;
  else
    return false;

}

/*!
 * \brief Usuwa nazwę pliku przeszkody z gnuplota.
 *
 * Usuwa nazwę pliku przeszkody z gnuplota.
 * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem.
 *
 * \pre Parametr Lacze musi się odwoływać do odpowiedniej zmiennej.
 * \post Usunięto nazwę pliku przeszkody z gnuplota.
 */
void PrzeszkodaPr::UsunPrzeszkode(PzG::LaczeDoGNUPlota &Lacze)
{
  for(int korpus=0; korpus<ILOSC_KORPUS; korpus++)
    _TabKorpus[korpus].UsunNazwePliku(Lacze);
}

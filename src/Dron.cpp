#include "Dron.hh"

using namespace std;

/*!
 * \file Dron.cpp
 * \brief Definicja metod klasy Dron
 */

/*!
 * \brief Ustawia pozycję drona.
 *
 * Konstruktor parametryczny. Ustawia pozycję drona.
 * \param[in] PozDr - pozycja drona.
 *
 * \pre brak
 * \post Ustawiono pozycję drona.
 */
Dron::Dron(Wektor3D PozDr)
{
  Pozycja=PozDr;
}


/*!
 * \brief Oblicza współrzędne punktów korpusu drona obróconego o 
 *        podany kąt.
 *
 * Oblicza współrzędne punktów korpusu drona obróconego o podany kąt.
 * Dla dodatniego kąta obraca się w lewo, dla ujemnego - w prawo.
 * \param[in] Macierz_obr - macierz obrotu służąca do obrotu figury.
 * \pre Parametr Macierz_obr musi zawierać wczesniej przypisane dane, ktore 
 *      mozna wykorzystac do obliczeń.
 * \post Wykonano obrót. 
 */
void Dron::Obrot(Macierz3x3 Macierz_obr)
{
  Macierz3x3 Macierz_wir;

  Macierz_wir('z',0.0);
  _TabKorpus[0].Obrot(Macierz_wir,Macierz_obr,Pozycja);
}

/*!
 * \brief Oblicza współrzędne punktów wirników obróconych o podane kąty -
 *        wokół osi drona i własnych.
 *
 * Oblicza współrzędne punktów wirników obróconych o podane kąty -
 * wokół osi drona i własnych.
 * Dla dodatniego kąta obraca się w lewo, dla ujemnego - w prawo.
 * \param[in] obrot - informacja czy wywołano obrót, czy przesunięcie,
 * \param[in] krok_wir - zmienna reprezentująca krok obrotu wirnika,
 * \param[in] nr_klatki - zmienna reprezentująca numer klatki,
 * \param[in] kier_obr - zmienna reprezentująca kierunek obrotu,
 * \param[in] Macierz_obr - macierz obrotu służąca do obrotu figury.
 * \pre Parametr Macierz_obr musi zawierać wczesniej przypisane dane, ktore 
 *      mozna wykorzystac do obliczeń.
 * \post Wykonano obrót. 
 */
void Dron::Obrot_wirnikow(bool obrot, double krok_wir,double nr_klatki,int kier_obr, Macierz3x3 Macierz_obr)
{
  Macierz3x3 Macierz_wir;
  double kat_obrotu;
  for(int i=0; i<ILOSC_ROTOROW; ++i)
    {
      kat_obrotu=nr_klatki*pow(-1,i)*krok_wir*(obrot?(1-kier_obr*(pow(-1,i)*0.5)):1);
      Macierz_wir('z',kat_obrotu);
      _TabRotor[i].Obrot(Macierz_wir,Macierz_obr,Pozycja);
    }
}

/*!
 * \brief Oblicza współrzędne punktów graniastosłupa prostego obróconego o 
 *        podany kąt względem oryginału za pomocą macierzy obrotu.
 *
 * Oblicza współrzędne punktów graniastosłupa prostego obróconego o podany
 * kąt względem oryginału za pomocą macierzy obrotu.
 * \param[in] kat_stopnie - zmienna reprezentująca kąt obrotu w stopniach.
 *
 * \pre brak
 * \post stworzono macierz obrotu.
 * \retval Macierz_obr - macierz obrotu.
 */
Macierz3x3 Dron::Obrot_stopnie(double kat_stopnie)
{
  double                kat_radiany;
  Macierz3x3            Macierz_obr;

  kat_radiany=kat_stopnie*M_PI/180;  /* przetwarzanie kąta obrotu */
  kat_orientacjiz+=kat_radiany;
  Macierz_obr('z', kat_orientacjiz);   /* tworzenie macierzy obrotu */
  return Macierz_obr;
}

/*!
 * \brief Oblicza współrzędne pozycji drona przesuniętego o 
 *        podaną drogę i kąt wznoszenia.
 *
 * Oblicza współrzędne pozycji drona przesuniętego o 
 * podaną drogę i kąt wznoszenia.
 * \param[in] droga - zmienna reprezentująca drogę,
 * \param[in] kat_wznoszenia - zmienna reprezentująca kąt wznoszenia w
 *                             stopniach.
 *
 * \pre brak
 * \post Wykonano przesunięcie pozycji.
 */
Wektor3D Dron::PrzesunPoz(double droga, double kat_wznoszenia)
{
  double kat=kat_wznoszenia*M_PI/180; /* przetwarzanie kąta wznoszenia */

  Wektor3D Przesuw;
  if(droga<0) _Sciezka.UsunPunkt();
  Przesuw[0]=droga*cos(kat)*cos(kat_orientacjiz);
  Przesuw[1]=droga*cos(kat)*sin(kat_orientacjiz);
  Przesuw[2]=droga*sin(kat);
  Pozycja=Pozycja+Przesuw;
  if(droga>0) _Sciezka.DodajPunkt(Pozycja);
  return Przesuw;
}

/*!
 * \brief Oblicza współrzędne punktów drona przesuniętego o 
 *        podaną drogę i kąt wznoszenia.
 *
 * Oblicza współrzędne punktów drona przesuniętego o 
 * podaną drogę i kąt wznoszenia.
 * \param[in] Przesuw - wektor przesunięcia drona.
 *
 * \pre brak
 * \post Wykonano przesunięcie drona.
 */
void Dron::Przesun(Wektor3D Przesuw)
{
  for(int i=0;i<ILOSC_KORPUS; ++i)
    _TabKorpus[i].Przesun(Przesuw);
  for(int i=0;i<ILOSC_ROTOROW; ++i)
    _TabRotor[i].Przesun(Przesuw);
}

/*!
 * \brief Inicjuje budowę drona.
 *
 * Inicjuje kąt obrotu wokół osi z i budowę drona.
 * \pre brak
 * \post Wykonano inicjację. 
 */
void Dron::Inicjuj(int i,PzG::LaczeDoGNUPlota &Lacze)
{
  ++i; kat_orientacjiz=0;
  _Sciezka.DodajNazwePliku(Lacze);
  _Sciezka.DodajPunkt(Pozycja);
  for(int korpus=0; korpus<ILOSC_KORPUS; korpus++){
    _TabKorpus[korpus].DodajNazwePliku(Lacze);
    _TabKorpus[korpus].Inicjuj(Pozycja);}
  for(int rotor=0; rotor<ILOSC_ROTOROW; rotor++){
    _TabRotor[rotor].DodajNazwePliku(Lacze);
    _TabRotor[rotor].Inicjuj(Pozycja,rotor);}
  promien=AproksymujDronaXY();
  wysokosc=AproksymujDronaZ();
}

/*!
 * \brief Zapis wspolrzednych elementów drona (graniastosłupów prostych) do 
 *        pliku.
 *
 * Zapis wspolrzednych elementów drona (graniastosłupów prostych) do 
 * pliku, z ktorego dane odczyta program gnuplot i narysuje je w swoim oknie 
 * graficznym.
 *
 * \post Zapisano drona.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool Dron::Zapisz() const
{
  if (!_TabKorpus[0].ZapiszBryle()) return false;
  for(int i=0; i<4; i++)
    if (!_TabRotor[i].ZapiszBryle()) return false;
  if (!_Sciezka.Zapisz()) return false;
  return true;
}

/*!
 * \brief Oblicza współrzędne punktów drona wyskalowanego za pomocą podanego
 *        współczynnika.
 *
 * Oblicza współrzędne punktów drona wyskalowanego za pomocą podanego
 * współczynnika.
 * \param[in] skala - zmienna reprezentująca skalę.
 *
 * \pre brak
 * \post Wykonano przeskalowanie.
 */
void Dron::SkalujDrona(double skala)
{
  for(int i=0; i<ILOSC_ROTOROW; ++i){
    _TabRotor[i].Zmien_Przesuniecie()=((_TabRotor[i].Wez_Przesuniecie()
                                              -Pozycja)*skala)+Pozycja;
    _TabRotor[i].SkalujBryle(skala,Pozycja);
  }
  for(int i=0; i<ILOSC_KORPUS; ++i)
    _TabKorpus[i].SkalujBryle(skala,Pozycja);

  Zapisz();
}

/*!
 * \brief Wyznacza promień walca powstałego z aproksymacji drona.
 *
 * Wyznacza promień walca powstałego z aproksymacji drona.
 * 
 * \pre brak
 * \post brak
 *
 * \retval promien - promień powstałego walca.
 */
double Dron::AproksymujDronaXY() const
{
  double promien=0,promien_rotora=0;

  promien+=pow(_TabKorpus[0](0)[0],2);
  promien+=pow(_TabKorpus[0](0)[1],2);
  promien = sqrt(promien);

  promien_rotora+=pow(_TabRotor[0](0)[0],2);
  promien_rotora+=pow(_TabRotor[0](0)[1],2);
  promien_rotora = sqrt(promien_rotora);

  promien+=promien_rotora;
  return promien;
}

/*!
 * \brief Wyznacza wysokość walca powstałego z aproksymacji drona.
 *
 * Wyznacza wysokość walca powstałego z aproksymacji drona.
 * 
 * \pre brak
 * \post brak
 *
 * \retval wysokosc - wysokość powstałego walca.
 */
double Dron::AproksymujDronaZ() const
{
  double wysokosc=0;
  wysokosc+=_TabRotor[0][12][2];
  wysokosc-=_TabKorpus[0][9][2];
  return fabs(wysokosc);
}

/*!
 * \brief Sprawdza czy pozycja kontrolowanego drona znajduje się odpowiednio 
 *        blisko pozycji drugiego drona, aby nastąpiła kolizja.
 *
 * Sprawdza czy pozycja kontrolowanego drona znajduje się odpowiednio 
 * blisko pozycji drugiego drona, aby nastąpiła kolizja.
 * 
 * \param[in] PozycjaBD - pozycja konrolowanego drona,
 * \param[in] AproksymDrona1 - wektor zawierający informacje o promieniu i wysokości kontrolowanego drona,
 * \param[in] AproksymDrona2 - wektor zawierający informacje o promieniu i wysokości tego drona,
 * \pre AproksymDrona1 musi mieć nieujemne wartości składowych.
 * \pre AproksymDrona1 musi mieć nieujemne wartości składowych.
 * \post brak
 *
 * \retval true - gdy wektory pozycji dronów są zbyt blisko siebie,
 * \retval false - w przeciwnym wypadku.
 */
bool Dron::CzyZaBlisko(Wektor3D PozycjaBD,Wektor3D AproksymDrona1,Wektor3D AproksymDrona2) const
{
  double odlegloscXY=0,suma_promieni=AproksymDrona1[0]+AproksymDrona2[0];
  double odlegloscZ=0,roznica_wysokosci=0;
  Wektor3D Roznica;
  PozycjaBD[2]+=AproksymDrona1[2]/6;
  roznica_wysokosci=AproksymDrona1[2];
  Roznica=Pozycja-PozycjaBD;
  odlegloscZ=fabs(Roznica[2]);
  Roznica[2]=0;
  odlegloscXY=Roznica.dlugosc();
  if(odlegloscXY<=suma_promieni&&odlegloscZ<=roznica_wysokosci) return true;
  else return false;
}

/*!
 * \brief Sprawdza czy kontrolowany dron koliduje z tym dronem.
 *
 * Sprawdza czy kontrolowany dron koliduje z tym dronem.
 *
 * \param[in] BiezDron - kontrolowany dron.
 * \pre brak
 * \post brak
 *
 * \retval true - gdy nastąpiła kolizja,
 * \retval false - w przeciwnym wypadku.
 */
bool Dron::CzyKolizja(const Dron &BiezDron) const
{
  Wektor3D AproksymDrona1,AproksymDrona2;

  AproksymDrona1[0]=AproksymDrona1[1]=BiezDron.Wez_promien();
  AproksymDrona1[2]=BiezDron.Wez_wysokosc();
  AproksymDrona2[0]=AproksymDrona2[1]=promien;
  AproksymDrona2[2]=wysokosc;

  if(CzyZaBlisko(BiezDron.Wez_Wektor_Pozycji(),AproksymDrona1,AproksymDrona2))
    return true; 
  else
    return false;
}

/*!
 * \brief Usuwa nazwy plików drona z gnuplota.
 *
 * Usuwa nazwy plików drona z gnuplota.
 * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem.
 *
 * \pre Parametr Lacze musi się odwoływać do odpowiedniej zmiennej.
 * \post Usunięto nazwy plików drona z gnuplota.
 */
void Dron::UsunDrona(PzG::LaczeDoGNUPlota &Lacze)
{
  _Sciezka.UsunNazwePliku(Lacze);
  for(int korpus=0; korpus<ILOSC_KORPUS; korpus++)
    _TabKorpus[korpus].UsunNazwePliku(Lacze);
  for(int rotor=0; rotor<ILOSC_ROTOROW; rotor++)
    _TabRotor[rotor].UsunNazwePliku(Lacze);
}

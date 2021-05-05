#include "Graniastoslup_prosty.hh"

using namespace std;

/*!
 * \file Graniastoslup_prosty.cpp
 * \brief Definicja metod klasy Graniastoslup_prosty
 */

int Graniastoslup_prosty::_Ilosc;

/*!
 * \brief Zapis wspolrzednych zbioru punktow prostopadloscianu do pliku
 *
 * Zapis wspolrzednych zbioru punktow prostopadloscianu do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 *
 * \pre brak
 * \post brak.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool Graniastoslup_prosty::ZapiszBryle() const
{
  std::ofstream  StrmWyj(_NazwaPliku.c_str());

  if (!StrmWyj.is_open()) {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << _NazwaPliku.c_str() << "\"" 
	 << std::endl << ":(  nie powiodla sie." << std::endl;
    return false;
  }
  
  StrmWyj << _TabGlob;
  return !StrmWyj.fail();
}

/*!
 * \brief Oblicza współrzędne punktów bryły wyskalowanej za pomocą podanego
 *        współczynnika.
 *
 * Oblicza współrzędne punktów bryły wyskalowanej za pomocą podanego
 * współczynnika.
 * \param[in] skala - zmienna reprezentująca skalę,
 * \param[in] Pozycja - zmienna reprezentująca wektor pozycji drona.
 *
 * \pre brak
 * \post Wykonano przeskalowanie.
 */
void Graniastoslup_prosty::SkalujBryle(double skala, Wektor3D &Pozycja)
{
  for(unsigned int i=0; i<_TabGlob.size(); ++i)
    {
      _TabGlob.at(i)=((_TabGlob.at(i)-Pozycja)*skala)+Pozycja;
      _TabLok.at(i)=_TabLok.at(i)*skala;
    }
}


/*!
 * \brief Oblicza współrzędne punktów graniastosłupa prostego obróconego o 
 *        podany kąt.
 *
 * Oblicza współrzędne punktów graniastosłupa prostego obróconego o podany kąt.
 * \param[in] Macierz_wir - macierz obrotu służąca do obrotu wirnika,
 * \param[in] Macierz_obr - macierz obrotu służąca do obrotu figury,
 * \param[in] Przesuniecie - wektor przesunięcia.
 * \pre Parametr Macierz_wir musi zawierać wczesniej przypisane dane, ktore 
 *      mozna wykorzystac do obliczeń.
 * \pre Parametr Macierz_obr musi zawierać wczesniej przypisane dane, ktore 
 *      mozna wykorzystac do obliczeń.
 * \pre Parametr Przesuniecie musi zawierać wczesniej przypisane dane, ktore 
 *      mozna wykorzystac do obliczeń.
 * \post Wykonano obrót. 
 */
void Graniastoslup_prosty::Obrot(Macierz3x3 Macierz_wir, Macierz3x3 Macierz_obr, Wektor3D &Przesuniecie)
{
  for(unsigned int indeks=0;indeks<_TabGlob.size();indeks++){
    _TabGlob.at(indeks)=(Macierz_wir*_TabLok.at(indeks))+Przesuniecie_Dron;
    _TabGlob.at(indeks)=(Macierz_obr*_TabGlob.at(indeks))+Przesuniecie;
  }
}

/*!
 * \brief Oblicza współrzędne punktów graniastosłupa prostego przesuniętego o 
 *        podany wektor.
 *
 * Oblicza współrzędne punktów graniastosłupa prostego przesuniętego o podany 
 * wektor.
 * \param[in] Przesuw - zmienna reprezentująca wektor przesunięcia.
 *
 * \pre Parametr Przesuw musi zawierać wczesniej przypisane dane, ktore 
 *      mozna wykorzystac do obliczeń.
 * \post Wykonano przesunięcie. 
 */
void Graniastoslup_prosty::Przesun(Wektor3D &Przesuw)
{
  for(unsigned int Ind=0;Ind<_TabGlob.size();Ind++)
    _TabGlob.at(Ind)=_TabGlob.at(Ind)+Przesuw;
}

/*
 * \brief Tworzy nazwę pliku bryły.
 *
 * Konstruktor bezparametryczny. Tworzy nazwę pliku bryły.
 * \pre Podfolder \e dat/fig1/ musi istnieć. 
 * \post Uworzono nazwę pliku bryły.
 */
Graniastoslup_prosty::Graniastoslup_prosty():_ID(++_Ilosc)
{
  ostringstream StrumNap;
  StrumNap << "dat/fig1/Graniastoslup_prosty" << _ID << ".dat";
  _NazwaPliku=StrumNap.str();
}


/*!
 * \brief Wyświetla współrzędne punktów bryły na wyjściu lub do pliku.
 * 
 * Wyświetla współrzędne punktów bryły na wyjściu lub do pliku.
 * \param[in] Strm - strumień danych wyjściowych,
 * \param[in] _TabGlob - tablica wektorów zawierająca współrzędne punktów do
 *                        wyświetlenia na wyjściu.
 *   
 * \pre Parametr _TabGlob musi zawierać wczesniej przypisane dane.
 * \post Wyświetlono współrzędne punktów bryły.
 * \retval Strm - współrzędne punktów bryły jako strumień danych 
 *                wyjściowych.
 */ 
std::ofstream& operator << ( std::ofstream       &Strm, 
                            const std::vector< Wektor3D > &_TabGlob
			    )
{
  Strm << _TabGlob.at(_TabGlob.size()-2);
  for(unsigned int i=0;i<_TabGlob.size()-2;i++)
    {
      Strm << _TabGlob.at(i);
      if(i%2)
        Strm << _TabGlob.back() << endl << _TabGlob.at(_TabGlob.size()-2);
    }
  Strm << _TabGlob.front() << _TabGlob.at(1)<< _TabGlob.back();
  Strm << endl;
  return Strm;
}

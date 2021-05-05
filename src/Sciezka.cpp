#include "Sciezka.hh"

using namespace std;

/*!
 * \file Sciezka.cpp
 * \brief Definicja metod klasy Sciezka
 */

/*!
 * \brief Zapis wspolrzednych zbioru punktow ścieżki do pliku
 *
 * Zapis wspolrzednych zbioru punktow ścieżki do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 *
 * \pre brak
 * \post brak.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool Sciezka::Zapisz() const
{
  std::ofstream  StrmWyj(_NazwaPliku.c_str());

  if (!StrmWyj.is_open()) {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << _NazwaPliku.c_str() << "\"" 
	 << std::endl << ":(  nie powiodla sie." << std::endl;
    return false;
  }
  
  StrmWyj << _ListaPunktow;
  return !StrmWyj.fail();
}

/*!
 * \brief Wyświetla współrzędne punktów ścieżki na wyjściu lub do pliku.
 * 
 * Wyświetla współrzędne punktów ścieżki na wyjściu lub do pliku.
 * \param[in] Strm - strumień danych wyjściowych,
 * \param[in] _ListaPunktow - tablica wektorów zawierająca współrzędne punktów do
 *                        wyświetlenia na wyjściu.
 *   
 * \pre Parametr _ListaPunktow musi zawierać wczesniej przypisane dane.
 * \post Wyświetlono współrzędne punktów ścieżki.
 * \retval Strm - współrzędne punktów ścieżki jako strumień danych 
 *                wyjściowych.
 */ 
std::ofstream& operator << ( std::ofstream       &Strm, 
                             const std::list< Wektor3D > &_ListaPunktow
			    )
{
  std::list<Wektor3D>::const_iterator it;
  for(it=_ListaPunktow.begin(); it!=_ListaPunktow.end(); ++it)
    Strm << *it;
  Strm << endl;
  return Strm;
}

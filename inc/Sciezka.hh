#ifndef SCIEZKA_HH
#define SCIEZKA_HH

#include "Graniastoslup_prosty.hh"


/*!  
 *  \file Sciezka.hh
 *  \brief Definicja klasy Sciezka
 *
 *  Plik zawiera definicję klasy Sciezka.
 */

/*!
 * \brief Klasa Sciezka modeluje pojęcie ścieżki.
 *
 *  Klasa Sciezka modeluje pojęcie ścieżki jako 
 *  zbioru wierzchołków bryły. Pozwala na wierzchołków do bryły.
 *  Klasa zawiera definicję bryły jako wieloelementowej tablicy, której 
 *  elementy odpowiedają elementom bryły.
 *  Metody klasy:
 *      Wektor3D  operator() (unsigned int Wie) const,
 *      Wektor3D& operator() (unsigned int Wie),       
 *      Wektor3D  operator[] (unsigned int Wie) const,
 *      Wektor3D& operator[] (unsigned int Wie),
 *      Wektor3D  Wez_Przesuniecie() const,
 *      Wektor3D& Zmien_Przesuniecie(),
 *      bool ZapiszBryle(const char*  sNazwaPliku),
 *      void SkalujBryle(double skala, Wektor3D Pozycja),
 *      void Obrot(Macierz3x3 Macierz_obr),
 *      void Przesun(Wektor3D Przesuw),
 *      void DodajPunkt(Wektor3D Pozycja),
 *      void UsunPunkt(Wektor3D Pozycja),
 *      bool Zapisz() const,
 *      void Wyczysc().
 */ 

class Sciezka: public Graniastoslup_prosty{
  /*! \brief ścieżka bryły */
  std::list<Wektor3D> _ListaPunktow;
public:
  /*! 
   * \brief Usuwa punkt ze ścieżki.
   *
   * Usuwa punkt ze ścieżki.
   * \pre brak
   * \post brak
   */
  void DodajPunkt(Wektor3D Pozycja)
  {_ListaPunktow.push_back(Pozycja);
   Zapisz();}

  /*!
   * \brief Dodaje punkt do ścieżki.
   *
   * Dodaje punkt do ścieżki.
   * \pre brak
   * \post brak
   */
  void UsunPunkt()
  {_ListaPunktow.pop_back();
   Zapisz();}

  /*
   * Zapis wspolrzednych zbioru punktow ścieżki do pliku, z ktorego
   * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
   */
  bool Zapisz() const;

  /*!
   * \brief Usuwa listę punktów ścieżki.
   *
   * Usuwa listę punktów ścieżki.
   * \pre brak
   * \post brak
   */
  void Wyczysc(){_ListaPunktow.clear();
                 Zapisz();}
};

std::ofstream& operator << ( std::ofstream       &Strm, 
                            const std::list< Wektor3D > &_ListaPunktow
			    );
#endif

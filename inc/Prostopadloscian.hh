#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Graniastoslup_prosty.hh"

#define ILOSC_WIERZ    8
#define DL_KROTSZEGO_BOKU      20
#define DL_DLOZSZEGO_BOKU      24
#define DL_POPRZECZNEGO_BOKU   10

/*!  
 *  \file Prostopadloscian.hh
 *  \brief Definicja klasy Prostopadloscian
 *
 *  Plik zawiera definicję klasy Prostopadloscian.
 */

/*!
 * \brief Klasa Prostopadloscian modeluje pojęcie prostopadłościanu.
 *
 *  Klasa Prostopadloscian modeluje pojęcie prostopadłościanu jako 
 *  zbioru ośmiu wierzchołków bryły. Pozwala na przemieszczanie i obrót bryły
 *  Klasa zawiera definicję bryły jako wieloelementowej tablicy, której 
 *  elementy odpowiedają elementom bryły.
 *  Metody klasy:
 *      Wektor3D  operator() (unsigned int Wie) const,
 *      Wektor3D& operator() (unsigned int Wie),       
 *      Wektor3D operator[] (unsigned int Wie) const,
 *      Wektor3D operator[] (unsigned int Wie),
 *      Wektor3D  Wez_Przesuniecie() const,
 *      Wektor3D& Zmien_Przesuniecie(),
 *      bool ZapiszBryle(const char*  sNazwaPliku),
 *      void SkalujBryle(double skala, Wektor3D Pozycja),
 *      void Obrot(Macierz3x3 Macierz_obr),
 *      void Przesun(Wektor3D Przesuw),
 *      Prostopadloscian(),
 *      ~Prostopadloscian().
 */
class Prostopadloscian: public Graniastoslup_prosty{
public:
  /*
   * Rezerwuje pamięć dla prostopadłościanu.
   */
  Prostopadloscian();

  /*
   * Wprowadza wartości współrzędnych wierzchołków
   * i punktów charakterystycznych prostopadłościanu.
   */
  void UstalWierzcholki();
  /*
   * Ustawia korpusy na pozycjach.
   */
  void Inicjuj(Wektor3D Pozycja);

  /*
   * Usuwa wierzchołki i punkty charakterystyczne prostopadłościanu.
   */
  ~Prostopadloscian();
};

#endif

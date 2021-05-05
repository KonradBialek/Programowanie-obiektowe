#ifndef GRANIASTOSLUP6_HH
#define GRANIASTOSLUP6_HH

#include "Graniastoslup_prosty.hh"

#define ILOSC_WIERZ_GRAN                  12
#define PROMIEN_PODSTAWY                  10
#define GRUBOSC_ROTORA                    5.0

/*!  
 *  \file Graniastoslup6.hh
 *  \brief Definicja klasy Graniastoslup6
 *
 *  Plik zawiera definicję klasy Graniastoslup6.
 */

/*!
 * \brief Klasa Graniastoslup6 modeluje pojęcie granistosłupa prawidłowego 
 *        sześciokątnego.
 *
 *  Klasa Graniastoslup6 modeluje pojęcie granistosłupa prawidłowego 
 *  sześciokątnego jako zbioru dwunastu wierzchołków bryły. Pozwala na 
 *  przemieszczanie i obrót bryły. 
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
 *      Graniastoslup6(),
 *      void Inicjuj(int rotor),
 *      ~Graniastoslup6();
 */
class Graniastoslup6: public Graniastoslup_prosty{
public:
  /*
   * Wprowadza wartości współrzędnych wierzchołków
   * i punktów charakterystycznych granistosłupa prawidłowego sześciokątnego.
   */
  Graniastoslup6();
  
  /*
   * Ustawia rotory na pozycjach.
   */
  void Inicjuj(Wektor3D Pozycja,int rotor);

  /*
   * Usuwa wierzchołki i punkty charakterystyczne graniastosłupa.
   */
  ~Graniastoslup6();
};

#endif

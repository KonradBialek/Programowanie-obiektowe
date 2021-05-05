#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH


#include "Wektor.hh"

/*!  
 *  \file Wektor3D.hh
 *  \brief Instancja Wektor<3> Wektor3D szablonu Wektor
 *
 *  Plik zawiera definicję instancji Wektor<3> Wektor3D szablonu Wektor.
 */

/*!
 * \brief Klasa Wektor3D jest instancją szablonu Wektor<>
 *
 *  Klasa Wektor3D modeluje pojęcie wektora jako punktu o podanych 
 *  współrzędnych, boku figury oraz jako przesunięcia figury w odpowiednim
 *  kierunku i na odpowiednią odległość.
 *  Klasa zawiera definicję wektora jako trzyelementowej tablicy, której 
 *  elementy odpowiedają współrzędnym punktu, boku lub przesunięcia.
 *  Metody klasy:
 *      static int WezIlosc(),
 *      static int WezIloscOgolem(),
 *      double& operator [] (int ind),       
 *      double  operator [] (int ind) const,
 *      Wektor3D operator + (const Wektor3D Przesuniecie) const,
 *      Wektor3D operator - (const Wektor3D Przesuniecie) const,
 *      double dlugosc() const,
 *      Wektor3D(),
 *      ~Wektor3D().
 */
typedef Wektor<3> Wektor3D;


#endif

#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH

#include "Macierz.hh"

/*!  
 *  \file Macierz3x3.hh
 *  \brief Instancja Macierz<3> Macierz3x3 szablonu Macierz
 *
 *  Plik zawiera definicję instancji Macierz<3> Macierz3x3 szablonu Macierz.
 */

/*!
 * \brief Klasa Macierz3x3 jest instancją szablonu Macierz<>
 *
 *  Klasa Macierz3x3 modeluje pojęcie macierzy jako tablicy dziewięciu 
 *  wartości służącej do pomnożenia przez wektor i wyznaczenia obrazu tego  
 *  wektora obróconego wokół początku układu współrzędnych o określony kąt
 *  oraz mnożenia dwóch macierzy.
 *  Klasa zawiera definicję macierzy jako dwuwymiarowej tablicy o wymiarach 
 *  3x3, której elementy odpowiedają elementom macierzy.
 *  Metody klasy:
 *      double  operator() (int Wie, int Kol) const,
 *      double& operator() (int Wie, int Kol),
 *      void operator() (double kat),
 *      Wektor3D operator * (const Wektor2D& Wek_org) const.
 *      Macierz3x3 operator * (const Macierz3x3& Mac_skl) const; 
 *      Macierz();
 *      Macierz3x3 Macierz<3>::operator() (char os, double kat);
 */
typedef Macierz<3>  Macierz3x3;

#endif

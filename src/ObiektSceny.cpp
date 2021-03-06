#include "ObiektSceny.hh"

using namespace std;

/*!
 * \file ObiektSceny.cpp
 * \brief Definicja metod klasy ObiektSceny
 */

int ObiektSceny::_IloscSc;
int ObiektSceny::_IloscOgolemSc;


/*!
 * \brief Kopiuje obiekt sceny i zwiększa wartości zmiennych ilości istniejących 
 *        obiektów sceny i ilości stworzonych obiektów sceny o 1 każdą.
 * 
 * Konstruktor kopiujący. Kopiuje obiekt sceny i zwiększa wartości zmiennych ilości 
 * istniejących obiektów sceny i ilości stworzonych obiektów sceny o 1 każdą.
 *   
 * \param[in] Ob - obiekt sceny do skopiowania.
 * \pre Parametr W musi się odwoływać do odpowiedniej zmiennej.
 * \post Wartości zmiennych ilości istniejących obiektów sceny i ilości 
 *       stworzonych obiektów sceny muszą zostać zwiększone o 1.
 */
ObiektSceny::ObiektSceny(const ObiektSceny &Ob)
{
  *this=Ob;
  ++_IloscSc; ++_IloscOgolemSc;
}


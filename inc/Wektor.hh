#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

/*! 
 *  \file Wektor.hh
 *  \brief Definicja szablonu Wektor
 *
 *  Plik zawiera definicję szablonu Wektor.
 */

/*! 
 *  \brief Szablon Wektor modeluje pojęcie wektora.
 *
 *  Szablon Wektor<Wymiar> modeluje pojęcie wektora jako punktu o podanych 
 *  współrzędnych, boku figury oraz jako przesunięcia figury w odpowiednim
 *  kierunku i na odpowiednią odległość.
 *  Szablon zawiera definicję wektora jako wieloelementowej tablicy, której 
 *  elementy odpowiedają współrzędnym punktu, boku lub przesunięcia.
 *  Metody szablonu:
 *      static int WezIlosc(),
 *      static int WezIloscOgolem(),
 *      double& operator [] (int ind),       
 *      double  operator [] (int ind) const,
 *      Wektor<Wymiar> operator + (const Wektor<Wymiar> Przesuniecie) const,
 *      Wektor<Wymiar> operator - (const Wektor<Wymiar> Przesuniecie) const,
 *      Wektor<Wymiar> operator * (double czynnik) const,
 *      double dlugosc() const,
 *      Wektor(),
 *      Wektor(const Wektor<Wymiar> &Wek),
 *      Wektor<Wymiar>& operator= (const Wektor<Wymiar> &Wek),
 *      ~Wektor().
 */

template <int Wymiar>
class Wektor {
    /*! \brief wektor punktu lub boku */
  double _Wsp[Wymiar]; 
    /*! \brief ilość istniejących wektorów */
  static int _Ilosc;
    /*! \brief ilość stworzonych wektorów */
  static int _IloscOgolem;
public:

  /*!
   * \brief Realizuje odczyt wartości pola statycznego ilości istniejących 
   *        wektorów.
   *
   * Realizuje odczyt wartości pola statycznego ilości istniejących wektorów.
   * \pre brak
   * \post brak
   * \retval Wartość wskazywanego pola.
   */
  static int WezIlosc() {return _Ilosc;}

  /*!
   * \brief Realizuje odczyt wartości pola statycznego ilości stworzonych 
   *        wektorów.
   *
   * Realizuje odczyt wartości pola statycznego ilości stworzonych wektorów.
   * \pre brak
   * \post brak
   * \retval Wartość wskazywanego pola.
   */
  static int WezIloscOgolem() {return _IloscOgolem;}

  /*!
   * \brief Realizuje zapis wartości do pola wektora o wskazanym indeksie.
   *
   * Realizuje zapis wartości do pola wektora o wskazanym indeksie.
   * \param[in] ind - indeks wskazujący na pole wektora.
   * \pre Parametr indeks jest mniejszy od wymiaru.
   * \post brak
   * \retval Referencję do wskazywanego pola.
   */
  double& operator [] (int ind)       {assert(0<=ind&&ind<Wymiar);
                                       return _Wsp[ind];
                                      }

  /*!
   * \brief Realizuje odczyt wartości pola wektora o wskazanym indeksie.
   *
   * Realizuje odczyt wartości pola wektora o wskazanym indeksie.
   * \param[in] ind - indeks wskazujący na pole wektora.
   * \pre Parametr indeks jest mniejszy od wymiaru.
   * \post brak
   * \retval Wartość wskazywanego pola.
   */
  double  operator [] (int ind) const {assert(0<=ind&&ind<Wymiar);
                                       return _Wsp[ind];
                                      }

  /*
   * Realizuje dodawanie wektora do innego wektora.
   */
  inline
  Wektor<Wymiar> operator + (const Wektor<Wymiar> Przesuniecie) const;

  /*
   * Realizuje odejmowanie wektora od innego wektora.
   */
  inline
  Wektor<Wymiar> operator - (const Wektor<Wymiar> Przesuniecie) const;

  /*
   * Realizuje mnożenie dwóch wektorów.
   */
  inline
  Wektor<Wymiar> operator * (double czynnik) const;

  /*
   * Realizuje porównywanie dwóch wektorów.
   */
  inline
  bool operator <= (const Wektor<Wymiar> Wektor) const;

  /*
   * Oblicza długość wektora jako boku figury.
   */
  inline
  double dlugosc() const;
  
  /*!
   * \brief Zwiększa wartości zmiennych ilości istniejących wektorów i ilości
   *        stworzonych wektorów o 1 każdą.
   * 
   * Konstruktor bezparametryczny. Zwiększa wartości zmiennych ilości 
   * istniejących wektorów i ilości stworzonych wektorów o 1 każdą.
   *   
   * \pre brak
   * \post Wartości zmiennych ilości istniejących wektorów i ilości 
   *         stworzonych wektorów muszą zostać zwiększone o 1.
   */
  inline
  Wektor() {++_Ilosc; ++_IloscOgolem;}

  /*
   * Kopiuje wektor i zwiększa wartości zmiennych ilości 
   * istniejących wektorów i ilości stworzonych wektorów o 1 każdą.
   */
  inline
  Wektor(const Wektor<Wymiar> &Wek);

  /*!
   * \brief Zmniejsza wartość zmiennej ilości istniejących wektorów o 1.
   * 
   * Destruktor bezparametryczny. Zmniejsza wartość zmiennej ilości 
   * istniejących wektorów o 1.
   *   
   * \pre brak
   * \post Wartość zmiennej ilości istniejących wektorów musi zostać 
   *       zmniejszona o 1.
   */
  inline
  ~Wektor() {--_Ilosc;}
  
};

template<int Wymiar>
int Wektor<Wymiar>::_Ilosc;
template<int Wymiar>
int Wektor<Wymiar>::_IloscOgolem;

/*!
 * \brief Kopiuje wektor i zwiększa wartości zmiennych ilości istniejących 
 *        wektorów i ilości stworzonych wektorów o 1 każdą.
 * 
 * Konstruktor kopiujący. Kopiuje wektor i zwiększa wartości zmiennych ilości 
 * istniejących wektorów i ilości stworzonych wektorów o 1 każdą.
 *   
 * \param[in] Wek - wektor do skopiowania.
 * \pre Parametr W musi się odwoływać do odpowiedniej zmiennej.
 * \post Wartości zmiennych ilości istniejących wektorów i ilości 
 *       stworzonych wektorów muszą zostać zwiększone o 1.
 */
template<int Wymiar>
inline
Wektor<Wymiar>::Wektor(const Wektor<Wymiar> &Wek)
{
  for(int i=0; i<Wymiar; ++i)
    _Wsp[i] = Wek[i];
  ++_Ilosc; ++_IloscOgolem;
}

/*!
 * \brief Realizuje dodanie wektora punktu i wektora przesunięcia.
 *
 * Realizuje dodanie wektora punktu i wektora przesunięcia.
 * \param[in] Przesuniecie - wektor przesunięcia.
 * \pre brak
 * \post brak
 * \retval Sumę dwóch argumentów przekazanych jako parametry.
 */
template<int Wymiar>
inline
Wektor<Wymiar> Wektor<Wymiar>::operator + (const Wektor<Wymiar> Przesuniecie) const
{
  Wektor<Wymiar> Wek_wyn;
  for(int indeks=0;indeks<Wymiar;indeks++)
    Wek_wyn[indeks]=_Wsp[indeks]+Przesuniecie[indeks];
  return Wek_wyn;
}

/*!
 * \brief Realizuje odejmowanie dwóch wektorów.
 *
 * Realizuje odejmowanie dwóch wektorów.
 * \param[in] Wek_2 - drugi argument (odjemnik).
 * \pre brak
 * \post brak
 * \retval Różnicę dwóch argumentów przekazanych jako parametry.
 */
template<int Wymiar>
inline
Wektor<Wymiar> Wektor<Wymiar>::operator - (const Wektor<Wymiar> Wek_2) const
{
  Wektor<Wymiar> Wek_wyn;
  for(int indeks=0;indeks<Wymiar;indeks++)
    Wek_wyn[indeks]=_Wsp[indeks]-Wek_2[indeks];
  return Wek_wyn;
}

/*!
 * \brief Realizuje mnożenie dwóch wektorów.
 *
 * Realizuje mnożenie dwóch wektorów.
 * \param[in] czynnik - drugi argument (mnożnik).
 * \pre brak
 * \post brak
 * \retval Iloczyn dwóch argumentów przekazanych jako parametry.
 */
template<int Wymiar>
inline
Wektor<Wymiar> Wektor<Wymiar>::operator * (double czynnik) const
{
  Wektor<Wymiar> Wek_wyn;
  for(int indeks=0;indeks<Wymiar;indeks++)
    Wek_wyn[indeks]=_Wsp[indeks]*czynnik;
  return Wek_wyn;
}

/*!
 * \brief Realizuje porównywanie dwóch wektorów.
 *
 * Realizuje porównywanie dwóch wektorów.
 * \param[in] Wektor - drugi argument porównania.
 * \pre brak
 * \post brak
 * \retval true - gdy badany wektor jest mniejszy od drugiego argumentu,
 * \retval false - w przeciwnym wypadku.
 */
template<int Wymiar>
inline
bool Wektor<Wymiar>::operator <= (const Wektor<Wymiar> Wektor) const
{
  int wsk=0;
  for(int indeks=0;indeks<Wymiar;indeks++)
    wsk+=(_Wsp[indeks]<=Wektor[indeks]?1:0);
  if(wsk==Wymiar) return true;
  else return false;
}

/*!
 * \brief Oblicza długość wektora jako boku figury.
 *
 * Oblicza długość wektora jako boku figury.
 *
 * \pre brak
 * \post brak
 * \retval Wynik - długość podanego wektora.
 */
template<int Wymiar>
inline
double Wektor<Wymiar>::dlugosc() const 
{
  double Wynik=0;
  for(int i=0; i<Wymiar;i++)
    Wynik+=pow(_Wsp[i],2);
  Wynik = sqrt(Wynik);
  return Wynik;
}

/*!
 * \brief Wczytuje podane na wejściu współrzędne punktu figury.
 *
 * Wczytuje podane na wejściu współrzędne punktu figury.
 * \param[in] Strm - strumień danych wejściowych,
 * \param[in] Wsp - referencja do obiektu zawierającego współrzędne punktu do
 *            wyświetlenia na wyjściu.
 *   
 * \pre Parametr Wsp musi zawierać wczesniej przypisane dane.
 * \post brak
 * \retval Strm - współrzędne punktu jako strumień danych wyjściowych.
 */
template<int Wymiar>
inline
std::istream& operator >> (std::istream &Strm, Wektor<Wymiar> &Wsp)
{ 
  for(int indeks=0;indeks<Wymiar;indeks++)
    {
      Strm >> Wsp[indeks];
      if(Strm.fail())
	return Strm;
    }
  return Strm;
}

/*!
 * \brief Wyświetla współrzędne punktu figury na wyjściu.
 *
 * Wyświetla współrzędne punktu figury na wyjściu.
 * \param[in] Strm - strumień danych wyjściowych,
 * \param[in] Wsp - obiekt zawierający współrzędne punktu do wyświetlenia na 
 *                  wyjściu.
 *   
 * \pre Parametr Wektor musi zawierać wczesniej przypisane dane.
 * \post brak
 * \retval Strm - współrzędne punktu jako strumień danych wyjściowych.
 */
template<int Wymiar>
inline
std::ostream& operator << (std::ostream &Strm,const Wektor<Wymiar> &Wsp)
{
  for(int indeks=0;indeks<Wymiar;indeks++)
    Strm<<std::setw(16)<< std::fixed << std::setprecision(10) << Wsp[indeks];
  Strm << std::endl;
  return Strm;
}

#endif

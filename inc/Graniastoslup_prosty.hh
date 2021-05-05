#ifndef GRANIASTOSLUP_PROSTY_HH
#define GRANIASTOSLUP_PROSTY_HH

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "lacze_do_gnuplota.hh"
#include <fstream>
#include <sstream>


/*!  
 *  \file Graniastoslup_prosty.hh
 *  \brief Definicja klasy Graniastoslup_prosty
 *
 *  Plik zawiera definicję klasy Graniastoslup_prosty.
 */

/*!
 * \brief Klasa Graniastoslup_prosty modeluje pojęcie graniastosłupa prostego.
 *
 *  Klasa Graniastoslup_prosty modeluje pojęcie graniastosłupa prostego jako 
 *  zbioru wierzchołków bryły. Pozwala na przemieszczanie bryły i sprawdzenie 
 *  czy zachowała kształt. 
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
 *      void Przesun(Wektor3D Przesuw).
 */
class Graniastoslup_prosty {
protected:
  /*! \brief zbiór oryginalnych wierzchołków bryły */
  std::vector< Wektor3D > _TabLok; 
  /*! \brief zbiór nowych wierzchołków bryły */
  std::vector< Wektor3D > _TabGlob; 
  /*! \brief pozycja elementu drona względem jego środka */
  Wektor3D Przesuniecie_Dron;
  /*! \brief numer identyfikacyjny bryły */
  int _ID=0;
  /*! \brief ilość brył */
  static int _Ilosc;
  /*! \brief nazwa bryły */
  std::string _NazwaPliku;
 public:
  /*!
   * \brief Realizuje odczyt wektora - pola graniastosłupa prostego wskazanego
   *        przez podaną liczbę.
   * 
   * Realizuje odczyt wektora - pola graniastosłupa prostego wskazanego przez 
   * podaną liczbę.
   * \param[in] Wie - liczba oznaczająca odpowiedni wektor (punkt 
   *                                                graniastosłupa prostego).
   *
   * \pre Parametr Wie musi być mniejszy od ilości wierzchołków.
   * \post brak
   *       
   * \retval _TabLok.at(Wie) - referencja do wektora (punktu graniastosłupa
   *                            prostego) wskazywanego przez liczbę.
   */
  Wektor3D  operator() (unsigned int Wie) const {assert(Wie<_TabLok.size());
                                                 return _TabLok.at(Wie);
                                                }

  /*!
   * \brief Realizuje zmianę wartości wektora - pola graniastosłupa prostego 
   *        wskazanego przez podaną liczbę.
   * 
   * Realizuje zmianę wartości wektora - pola graniastosłupa prostego 
   * wskazanego przez podaną liczbę.
   * \param[in] Wie - liczba oznaczająca odpowiedni wektor (punkt 
   *                                                graniastosłupa prostego).
   *
   * \pre Parametr Wie musi być mniejszy od ilości wierzchołków.
   * \post brak
   *       
   * \retval _TabLok.at(Wie) - wektora (punkt graniastosłupa
   *                            prostego) wskazywany przez liczbę.
   */
  Wektor3D& operator() (unsigned int Wie)       {assert(Wie<_TabLok.size());
                                                 return _TabLok.at(Wie);
                                                }

  /*!
   * \brief Realizuje odczyt wektora - pola nowego graniastosłupa prostego 
   *        wskazanego przez podaną liczbę.
   *
   * Realizuje odczyt wektora - pola nowego graniastosłupa prostego wskazanego
   * przez podaną liczbę.
   * \param[in] Wie - liczba oznaczająca odpowiedni wektor (punkt 
   *                                                graniastosłupa prostego).
   *
   * \pre Parametr Wierzch musi być mniejszy od ilości wierzchołków.
   * \post brak
   *       
   * \retval _TabGlob.at(Wie) - referencja do wektora (punktu nowego 
   *                       graniastosłupa prostego) wskazywanego przez liczbę.
   */
  Wektor3D  operator[] (unsigned int Wie) const {assert(Wie<_TabGlob.size());
                                                 return _TabGlob.at(Wie);
                                                }

  /*!
   * \brief Realizuje zmianę wartości wektora - pola nowego graniastosłupa prostego 
   *        wskazanego przez podaną liczbę.
   *
   * Realizuje zmianę wartości wektora - pola nowego graniastosłupa prostego wskazanego
   * przez podaną liczbę.
   * \param[in] Wie - liczba oznaczająca odpowiedni wektor (punkt 
   *                                                graniastosłupa prostego).
   *
   * \pre Parametr Wierzch musi być mniejszy od ilości wierzchołków.
   * \post brak
   *       
   * \retval _TabGlob.at(Wie) - wektora (punktu nowego 
   *                       graniastosłupa prostego) wskazywanego przez liczbę.
   */
  Wektor3D& operator[] (unsigned int Wie)       {assert(Wie<_TabGlob.size());
                                                 return _TabGlob.at(Wie);
                                                }

  /*!
   * \brief Realizuje odczyt wektora - przesunięcia bryły względem pozycji 
   *        drona.
   *
   * Realizuje odczyt wektora - przesunięcia bryły względem pozycji drona.
   *
   * \pre brak
   * \post brak
   *       
   * \retval Przesuniecie_Dron - referencja do wektora (przesunięcia bryły 
   *                             względem pozycji drona).
   */
  Wektor3D  Wez_Przesuniecie() const {return Przesuniecie_Dron;}

  /*!
   * \brief Realizuje zmianę wartości wektora - przesunięcia bryły względem 
   *        pozycji drona.
   *
   * Realizuje zmianę wartości wektora - przesunięcia bryły względem pozycji drona.
   *
   * \pre brak
   * \post brak
   *       
   * \retval Przesuniecie_Dron - wektor (przesunięcie bryły 
   *                             względem pozycji drona).
   */
  Wektor3D& Zmien_Przesuniecie()       {return Przesuniecie_Dron;}
  
  /*
   * Zapis wspolrzednych zbioru punktow prostopadloscianu do pliku, z ktorego
   * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
   */
  bool ZapiszBryle() const;

  /*
   * Oblicza współrzędne punktów bryły wyskalowanej za pomocą podanego
   * współczynnika.
   */
  void SkalujBryle(double skala, Wektor3D &Pozycja);

  /*
   * Wykonuje pojedynczy obrót bryły zgodnie z otrzymanymi danymi.
   */
  void Obrot(Macierz3x3 Macierz_wir, Macierz3x3 Macierz_obr, Wektor3D &Przesuniecie);

  /*
   * Oblicza współrzędne punktów graniastosłupa prostego przesuniętego o podany 
   * wektor.
   */
  void Przesun(Wektor3D &Przesuw);

  /*
   * Konstruktor bezparametryczny. Tworzy nazwę pliku bryły.
   */
  Graniastoslup_prosty();

  /*!
   * \brief Dodaje nazwę pliku do łącza gnuplota.
   *
   * Dodaje nazwę pliku do łącza gnuplota.
   * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem.
   *
   * \pre Parametr Lacze musi się odwoływać do odpowiedniej zmiennej.
   * \post Dodano nazwę pliku do łącza.
   */
  void DodajNazwePliku(PzG::LaczeDoGNUPlota &Lacze)
  {Lacze.DodajNazwePliku(_NazwaPliku.c_str());}

  /*!
   * \brief Usuwa nazwę pliku z łącza gnuplota.
   *
   * Usuwa nazwę pliku z łącza gnuplota.
   * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem.
   *
   * \pre Parametr Lacze musi się odwoływać do odpowiedniej zmiennej.
   * \post Usunięto nazwę pliku z łącza.
   */
  void UsunNazwePliku(PzG::LaczeDoGNUPlota &Lacze)
  {Lacze.UsunNazwePliku(_NazwaPliku.c_str());}

};

/*
 * Wyświetla współrzędne punktów prostopadłościanu na wyjściu.
 */
std::ofstream& operator << ( std::ofstream       &Strm, 
                            const std::vector< Wektor3D > &_TabGlob
			    );

#endif


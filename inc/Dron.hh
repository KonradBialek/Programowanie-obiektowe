#ifndef DRON_HH
#define DRON_HH

#include "ObiektSceny.hh"
#define ILOSC_ROTOROW 4

/*!  
 *  \file Dron.hh
 *  \brief Definicja klasy Dron
 *
 *  Plik zawiera definicję klasy Dron.
 */

/*!
 * \brief Klasa Dron modeluje pojęcie dronu.
 *
 *  Klasa Dron modeluje pojęcie dronu jako zbioru
 *  prostopadłościanów i graniastosłupów prawidłowych sześciokątnych. Pozwala  
 *  na pobieranie i modyfikowanie pól swoich obiektów, ich obracanie, 
 *  przesuwanie, inicjowanie, zapisanie oraz skalowanie.
 *  Klasa zawiera definicję drona jako dwóch wieloelementowych tablic, których 
 *  elementy odpowiedają odpowiednim elementom drona, zmiennej reprezentującej 
 *  pozycję drona w przestrzeni i zmiennej reprezentującej kąt obrotu drona 
 *  wzgdędem osi \e z.
 *  Metody klasy:
 *      Prostopadloscian  operator[] (int Pr) const,
 *      Prostopadloscian& operator[] (int Pr),
 *      Wektor3D Wez_Wektor_Pozycji() const,
 *      Graniastoslup6  operator() (int Gr) const, 
 *      Graniastoslup6& operator() (int Gr),
 *      void Obrot(Macierz3x3 Macierz_obr),
 *      void Obrot_wirnikow(bool obrot, double krok_wir,double nr_klatki,
                                   int kier_obr, Macierz3x3 Macierz_obr),
 *      Macierz3x3 Obrot_stopnie(char os, double kat_stopnie),
 *      void Przesun(double droga, double kat_wznoszenia),
 *      void SkalujDrona(double skala),
 *      virtual void Inicjuj(int i),
 *      virtual bool Zapisz(int i) const.
 */
class Dron: public ObiektSceny{
  /*! \brief zbiór prostopadłościanów */
  Prostopadloscian _TabKorpus[ILOSC_KORPUS];
  /*! \brief zbiór graniastosłupów */
  Graniastoslup6 _TabRotor[ILOSC_ROTOROW];
  /*! \brief ścieżka drona */
  Sciezka _Sciezka;
  /*! \brief promień aproksymacji drona */
  double promien;
  /*! \brief wysokość aproksymacji drona */
  double wysokosc;

  friend FabrykaObiektow;
  /*
   * \brief Ustawia pozycję drona. 
   */
  Dron(Wektor3D PozDr);
public:
  /*! \brief Destruktor wirtualny */
  virtual ~Dron(){}
  /*!
   * \brief Realizuje odczyt promienia drona.
   *
   * Realizuje odczyt promienia drona.
   *
   * \pre brak
   * \post brak
   *       
   * \retval promien - kopia zmiennej promienia drona.
   */
  double  Wez_promien() const {return promien;}

  /*!
   * \brief Realizuje odczyt wysokości drona.
   *
   * Realizuje odczyt wysokości drona.
   *
   * \pre brak
   * \post brak
   *       
   * \retval wysokosc - kopia zmiennej wysokości drona.
   */
  double  Wez_wysokosc() const {return wysokosc;}

  /*!
   * \brief Realizuje odczyt wartości pola prostopadłościanu sceny o 
   *        wskazanym indeksie.
   *
   * Realizuje odczyt wartości pola prostopadłościanu sceny o wskazanym
   * indeksie.
   * \param[in] Pr - indeks wskazujący na pole sceny.
   * \pre Parametr indeks jest mniejszy od ilości prostopadłośćianów.
   * \post brak
   * \retval Kopię wskazywanego pola.
   */
  inline 
  Prostopadloscian  operator[] (int Pr) const {assert(0<=Pr&&Pr<ILOSC_KORPUS);
                                               return _TabKorpus[Pr];
                                              } 

  /*!
   * \brief Realizuje zapis wartości do pola prostopadłościanu sceny o 
   *        wskazanym indeksie.
   *
   * Realizuje zapis wartości do pola prostopadłościanu sceny o wskazanym
   * indeksie.
   * \param[in] Pr - indeks wskazujący na pole sceny - prostopadłościan.
   * \pre Parametr Pr jest mniejszy od ilości prostopadłośćianów.
   * \post brak
   * \retval Referencję do wskazywanego pola.
   */
  inline
  Prostopadloscian& operator[] (int Pr)       {assert(0<=Pr&&Pr<ILOSC_KORPUS);
                                               return _TabKorpus[Pr];
                                              }
  /*!
   * \brief Realizuje odczyt wartości pola prostopadłościanu sceny o 
   *        wskazanym indeksie.
   *
   * Realizuje odczyt wartości pola prostopadłościanu sceny o wskazanym
   * indeksie.
   * \param[in] Gr - indeks wskazujący na pole sceny.
   * \pre Parametr Gr jest mniejszy od ilości prostopadłośćianów.
   * \post brak
   * \retval Kopię wskazywanego pola.
   */
  inline 
  Graniastoslup6  operator() (int Gr) const {assert(0<=Gr&&Gr<ILOSC_ROTOROW);
                                               return _TabRotor[Gr];
                                              } 

  /*!
   * \brief Realizuje zapis wartości do pola prostopadłościanu sceny o 
   *        wskazanym indeksie.
   *
   * Realizuje zapis wartości do pola prostopadłościanu sceny o wskazanym
   * indeksie.
   * \param[in] Gr - indeks wskazujący na pole sceny - prostopadłościan.
   * \pre Parametr Gr jest mniejszy od ilości prostopadłośćianów.
   * \post brak
   * \retval Referencję do wskazywanego pola.
   */
  inline
  Graniastoslup6& operator() (int Gr)       {assert(0<=Gr&&Gr<ILOSC_ROTOROW);
                                               return _TabRotor[Gr];
                                              }

  /*
   * Oblicza współrzędne punktów drona obróconego o podany kąt.
   */
  void Obrot(Macierz3x3 Macierz_obr);

  /*
   * Oblicza współrzędne punktów wirników obróconych o podane kąty - wokół osi
   * drona i własnych.
   */
  void Obrot_wirnikow(bool obrot, double krok_wir,double nr_klatki,
                              int kier_obr, Macierz3x3 Macierz_obr);

  /*
   * Oblicza współrzędne punktów graniastosłupa prostego obróconego o podany
   * kąt względem oryginału za pomocą macierzy obrotu.
   */
  Macierz3x3 Obrot_stopnie(double kat_stopnie);

  /*
   * Oblicza współrzędne pozycji drona przesuniętego o 
   * podaną drogę i kąt wznoszenia.
   */
  Wektor3D PrzesunPoz(double droga, double kat_wznoszenia);

  /*
   * Oblicza współrzędne punktów drona przesuniętego o 
   * podaną drogę i kąt wznoszenia.
   */
  void Przesun(Wektor3D Przesuw);

  /*
   * Wyznacza promień walca powstałego z aproksymacji drona.
   */
  double AproksymujDronaXY() const;

  /*
   * Wyznacza wysokość walca powstałego z aproksymacji drona.
   */
  double AproksymujDronaZ() const;

  /*
   * Inicjuje kąt obrotu wokół osi z i budowę drona.
   */
  virtual void Inicjuj(int i,PzG::LaczeDoGNUPlota &Lacze);

  /*
   * Zapis wspolrzednych elementów drona (graniastosłupów prostych) do pliku.
   */
  virtual bool Zapisz() const;

  /*
   * Sprawdza czy kontrolowany dron koliduje z tym dronem.
   */
  virtual bool CzyKolizja(const Dron &BiezDron) const;
  
  /*
   * Oblicza współrzędne punktów drona wyskalowanego za pomocą podanego
   * współczynnika.
   */
  void SkalujDrona(double skala);

  /*
   * Sprawdza czy pozycja kontrolowanego drona znajduje się odpowiednio 
   * blisko pozycji drugiego drona, aby nastąpiła kolizja.
   */
  bool CzyZaBlisko(Wektor3D PozycjaBD,Wektor3D AproksymDrona1,Wektor3D AproksymDrona2) const;

  /*!
   * \brief Usuwa ścieżkę tego drona.
   *
   * Usuwa ścieżkę tego drona.
   * \pre brak
   * \post brak
   */
  void WyczyscSciezke(){_Sciezka.Wyczysc();
                        _Sciezka.DodajPunkt(Pozycja);}

  /*
   * Usuwa nazwy plików drona z gnuplota.
   */
  void UsunDrona(PzG::LaczeDoGNUPlota &Lacze);
};

#endif

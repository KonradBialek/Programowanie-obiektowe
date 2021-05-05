#ifndef PRZESZKODAPR
#define PRZESZKODAPR

#include "Dron.hh"
//#include "Fabryka.hh"

/*!  
 *  \file PrzeszkodaPr.hh
 *  \brief Definicja klasy PrzeszkodaPr
 *
 *  Plik zawiera definicję klasy PrzeszkodaPr.
 */

/*!
 * \brief Klasa PrzeszkodaPr modeluje pojęcie przeszkody prostopadłościennej.
 *
 *  Klasa PrzeszkodaPr modeluje pojęcie przeszkody prostopadłościennej jako zbioru
 *  prostopadłościanów. Pozwala na pobieranie i modyfikowanie pól swoich obiektów.
 *  Klasa zawiera definicję przeszkody prostopadłościennej jako wieloelementowej tablicy, których 
 *  elementy odpowiedają odpowiednim elementom obiektu sceny, zmiennej reprezentującej 
 *  pozycję przeszkody prostopadłościennej w przestrzeni.
 *  Metody klasy:
 *      Prostopadloscian  operator[] (int Pr) const,
 *      Prostopadloscian& operator[] (int Pr),
 *      Wektor3D Wez_Wektor_Pozycji() const,
 *      virtual void Inicjuj(int i),
 *      virtual bool Zapisz(int i) const,
 *      void UstalPozIWym(int i),
 *      void UstalWierz().
 */
class PrzeszkodaPr:public ObiektSceny{
  /*! \brief zbiór prostopadłościanów */
  Prostopadloscian _TabKorpus[ILOSC_KORPUS];
  /*! \brief wysokość przeszkody */
  double wysokosc;
  /*! \brief szerokość przeszkody */
  double szerokosc;
  /*! \brief długość przeszkody */
  double dlugosc;


  friend class FabrykaObiektow;
  /*
   * \brief Ustawia parametry przeszkody. 
   */
  PrzeszkodaPr(Wektor3D PozPr,double dl,double szer,double wys);
 public:
  /*! \brief Destruktor wirtualny */
  virtual ~PrzeszkodaPr(){}
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
  /*
   * Inicjuje budowę przeszkody.
   */
  virtual void Inicjuj(int i,PzG::LaczeDoGNUPlota &Lacze);

  /*
   * Zapis wspolrzednych elementów przeszkody prostopadłościanu do pliku.
   */
  virtual bool Zapisz() const;

  /*
   * Ustala pozycję i wymiary przeszkody.
   */
  void UstalPozIWym(int i);

  /*
   * Ustala współrzędne wierzchołków przeszkody.
   */
  void UstalWierz();

  /*
   * Sprawdza czy pozycja kontrolowanego drona znajduje się wewnątrz przeszkody.
   */
  bool CzyWewnatrz(Wektor3D Pozycja,Wektor3D Min,Wektor3D Max,Wektor3D AproksymPrzeszk) const;

  /*
   * Sprawdza czy kontrolowany dron koliduje z tą przeszkodą.
   */
  virtual bool CzyKolizja(const Dron &BiezacyDron) const;

  /*
   * Usuwa nazwę pliku przeszkody z gnuplota.
   */
  void UsunPrzeszkode(PzG::LaczeDoGNUPlota &Lacze);
};

#endif

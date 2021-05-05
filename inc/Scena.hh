#ifndef SCENA_HH
#define SCENA_HH

#include <unistd.h>

//#include "PrzeszkodaPr.hh"
#include "FabrykaObiektow.hh"

#define ILOSC_DRONOW 3
#define ILOSC_PRZESZKODPR 3
/*!  
 *  \file Scena.hh
 *  \brief Definicja klasy Scena
 *
 *  Plik zawiera definicję klasy Scena.
 */

/*!
 * \brief Klasa Scena modeluje pojęcie sceny.
 *
 *  Klasa Scena modeluje pojęcie sceny jako zbioru
 *  dronów. Pozwala na pobieranie i modyfikowanie pól swoich obiektów oraz
 *  animowanie ruchu i skalowanie drona.
 *  Klasa zawiera definicję sceny jako wieloelementowej tablicy, której 
 *  elementy odpowiedają odpowiednim dronom.
 *  Metody klasy:
 *      Dron  operator[] (int Dr) const,
 *      Dron& operator[] (int Dr),
 *      void Inicjuj(),
 *      bool AnimacjaLotu(PzG::LaczeDoGNUPlota & Lacze, double droga,
 *                               double kat_wzn, double krok_obr,double krok_wir),
 *      bool AnimacjaObrotu(PzG::LaczeDoGNUPlota & Lacze, char os, 
 *                      double kat_stopnie, double krok_lotu,double krok_wir),
 *      void SkalujDrona(PzG::LaczeDoGNUPlota & Lacze, double skala).
 */
class Scena{
  /*! \brief zbiór dronów */
  std::list<std::shared_ptr<Dron>> _ListaDr;
  /*! \brief zbiór obiektów sceny */
  std::list<std::shared_ptr<ObiektSceny>> _ListaOb;
  /*! \brief zbiór przeszkód */
  std::list<std::shared_ptr<PrzeszkodaPr>> _ListaPr;
  /*! \brief wskażnik na aktualnie wybranego drona */
  std::shared_ptr<Dron> BiezacyDron() const;
  /*! \brief wskażnik na usuwaną przeszkodę */
  std::shared_ptr<PrzeszkodaPr> BiezacaPrzeszkoda() const;
  /*! \brief numer aktualnie wybranego drona */
  int nr_drona=0;
  /*! \brief numer usuwanej przeszkody */
  int nr_przeszkody=0;
  public:

  /*!
   * \brief Realizuje zapis wartości do pola numeru aktualnie wybranego drona.
   *
   * Realizuje zapis wartości do pola numeru aktualnie wybranego drona.
   * \pre brak
   * \post brak
   * \retval Referencję do wskazywanego pola.
   */
  int& Pobierz_Nr_Drona() {return nr_drona;}
 
  /*!
   * \brief Realizuje zapis wartości do pola numeru usuwanej przeszkody.
   *
   * Realizuje zapis wartości do pola numeru usuwanej przeszkody.
   * \pre brak
   * \post brak
   * \retval Referencję do wskazywanego pola.
   */
  int& Pobierz_Nr_Przeszkody() {return nr_przeszkody;}

  /*
   * Dodaje nowego drona do list dronów i przeszkód.
   */
  shared_ptr<Dron> DodajDron();//Wektor3D Pozycja);//WskFabryki *Fabryka);

  /*
   * Dodaje nową przeszkodę do listy przeszkód.
   */
  shared_ptr<PrzeszkodaPr> DodajPrzeszkodePr();//Wektor3D Pozycja,double dl,double szer,double wys);//WskFabryki *Fabryka);

  void WyswietlWspolOb() const;
  /*
   * Wyswietla współrzędne dronów.
   */
  void WyswietlWspolDronow() const;

  void WyswietlWspolPrzeszkod() const;

  /*
   * Wyswietla współrzędne aktualnego drona.
   */
  void WyswietlAktualnegoDrona() const;

  /*
   * Wyswietla informacje o ilości obiektów sceny i wektorów.
   */
  void WyswietlIloscObiektow() const;

  /*
   * Wyświetla drona w kolejnych klatkach lotu.
   */
  bool AnimacjaLotu(PzG::LaczeDoGNUPlota & Lacze, double droga, double kat_wzn,
  double krok_obr,double krok_wir,int nr_dr);

  /*
   * Wyświetla drona w kolejnych klatkach obrotu.
   */
  bool AnimacjaObrotu(PzG::LaczeDoGNUPlota & Lacze, double kat_stopnie,
  double krok_lotu,double krok_wir,int nr_dr);

  /*
   * Sprawdza czy kontrolowany dron koliduje z innymi obiektami sceny.
   */
  bool CzyKolizjaZBD() const;

  /*
   * Konstruktor parametryczny. Zwiększa wartości zmiennych ilości 
   * istniejących obiektów sceny i ilości stworzonych obiektów sceny o 1 każdą.
   */
  Scena(PzG::LaczeDoGNUPlota &Lacze);//WskFabryki* Fabryka);

  /*
   * Destruktor bezparametryczny. Zmniejsza wartość zmiennej ilości 
   * istniejących obiektów sceny o 1.
   */
  ~Scena();

  /*!
   * \brief Usuwa ścieżkę aktualnie wybranego drona.
   *
   * Usuwa ścieżkę aktualnie wybranego drona.
   * \pre brak
   * \post brak
   */
  void WyczyscSciezke()
  {BiezacyDron()->WyczyscSciezke();
   std::cerr<<std::endl<<" Usunieto sciezke wybranego drona"<<std::endl;}
  
  void UsunDrona(PzG::LaczeDoGNUPlota &Lacze);
  void UsunPrzeszkode(PzG::LaczeDoGNUPlota &Lacze);
};

#endif

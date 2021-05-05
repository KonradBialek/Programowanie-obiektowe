#ifndef OBIEKTSCENY
#define OBIEKTSCENY

#include <memory>
#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "Sciezka.hh"
#define ILOSC_KORPUS 1

/*!  
 *  \file ObiektSceny.hh
 *  \brief Definicja klasy ObiektSceny
 *
 *  Plik zawiera definicję klasy ObiektSceny.
 */
class FabrykaObiektow;
class Dron;
/*!
 * \brief Klasa ObiektSceny modeluje pojęcie obiektu sceny.
 *
 *  Klasa ObiektSceny modeluje pojęcie obiektu sceny jako zbioru
 *  prostopadłościanów i graniastosłupów prawidłowych sześciokątnych. Pozwala  
 *  na pobieranie i modyfikowanie pól swoich obiektów.
 *  Klasa zawiera definicję obiektu sceny jako dwóch wieloelementowych tablic, których 
 *  elementy odpowiedają odpowiednim elementom obiektu sceny, zmiennej reprezentującej 
 *  pozycję obiektu sceny w przestrzeni.
 *  Metody klasy:
 *      static int WezIloscSc(),
 *      static int WezIloscOgolemSc(),
 *      ObiektSceny(),
 *      ~ObiektSceny(),
 *      Prostopadloscian  operator[] (int Pr) const,
 *      Prostopadloscian& operator[] (int Pr),
 *      Wektor3D Wez_Wektor_Pozycji() const,
 *      virtual void Inicjuj(int i),
 *      virtual bool Zapisz(int i) const.
 */
class ObiektSceny{
protected:
  /*! \brief pozycja drona w przestrzeni */
  Wektor3D Pozycja;
  /*! \brief kąt obrotu wokół osi z */
  double kat_orientacjiz;
  /*! \brief ilość istniejących obiektów sceny */
  static int _IloscSc;
  /*! \brief ilość stworzonych obiektów sceny */
  static int _IloscOgolemSc;
  public:

  /*!
   * \brief Realizuje odczyt wartości pola statycznego ilości istniejących 
   *        obiektów sceny.
   *
   * Realizuje odczyt wartości pola statycznego ilości istniejących obiektów sceny.
   * \pre brak
   * \post brak
   * \retval Wartość wskazywanego pola.
   */
  static int WezIloscSc() {return _IloscSc;}

  /*!
   * \brief Realizuje odczyt wartości pola statycznego ilości stworzonych 
   *        obiektów sceny.
   *
   * Realizuje odczyt wartości pola statycznego ilości stworzonych obiektów sceny.
   * \pre brak
   * \post brak
   * \retval Wartość wskazywanego pola.
   */
  static int WezIloscOgolemSc() {return _IloscOgolemSc;}

  /*!
   * \brief Zwiększa wartości zmiennych ilości istniejących obiektów sceny i ilości
   *        stworzonych obiektów sceny o 1 każdą.
   * 
   * Konstruktor bezparametryczny. Zwiększa wartości zmiennych ilości 
   * istniejących obiektów sceny i ilości stworzonych obiektów sceny o 1 każdą.
   *   
   * \pre brak
   * \post Wartości zmiennych ilości istniejących obiektów sceny i ilości 
   *         stworzonych obiektów sceny muszą zostać zwiększone o 1.
   */
  inline
  ObiektSceny() {++_IloscSc; ++_IloscOgolemSc;}

  /*!
   * \brief Zmniejsza wartość zmiennej ilości istniejących obiektów sceny 1.
   * 
   * Konstruktor bezparametryczny. Zmniejsza wartość zmiennej ilości 
   * istniejących obiektów sceny 1.
   *   
   * \pre brak
   * \post Wartości zzmiennej ilości istniejących obiektów sceny musi zostać 
   *       zmniejszona o 1.
   */
  inline
  virtual ~ObiektSceny() {--_IloscSc;}

  /*
   * Kopiuje obiekt sceny i zwiększa wartości zmiennych ilości 
   * istniejących obiektów sceny i ilości stworzonych obiektów sceny o 1 każdą.
   */
  ObiektSceny(const ObiektSceny &Ob);

  /*!
   * \brief Realizuje odczyt wartości pola wektora pozycji obiektu sceny.
   *
   * Realizuje odczyt wartości pola wektora pozycji obiektu sceny.
   * \pre brak
   * \post brak
   * \retval Kopię wskazywanego pola.
   */
  inline 
  Wektor3D Wez_Wektor_Pozycji() const {return Pozycja;}

  /*!
   * \brief Realizuje odczyt wartości pola kąta orientacji obiektu sceny.
   *
   * Realizuje odczyt wartości pola kąta orientacji obiektu sceny.
   * \pre brak
   * \post brak
   * \retval Kopię wskazywanego pola.
   */
  inline 
  double Wez_Kat_OrientacjiZ() const {return kat_orientacjiz;}

  /*!
   * \brief Inicjuje budowę drona lub przeszkody.
   *
   * Inicjuje budowę drona lub przeszkody.
   * \pre brak
   * \post Wykonano inicjację. 
   */
  virtual void Inicjuj(int i,PzG::LaczeDoGNUPlota &Lacze)=0;

  /*!
   * \brief Zapis wspolrzednych elementów drona lub przeszkody do 
   *        pliku.
   *
   * Zapis wspolrzednych elementów drona lub przeszkody do 
   * pliku, z ktorego dane odczyta program gnuplot i narysuje je w swoim oknie 
   * graficznym.
   *
   * \post Zapisano drona lub przeszkodę.
   * \retval true - gdy operacja zapisu powiodła się,
   * \retval false - w przypadku przeciwnym.
   */
  virtual bool Zapisz() const=0;

  /*!
   * \brief Sprawdza czy kontrolowany dron koliduje z tym obiektem.
   *
   * Sprawdza czy kontrolowany dron koliduje z tym obiektem.
   * 
   * \param[in] BiezacyDron - kontrolowany dron.
   * \pre brak
   * \post brak
   *
   * \retval true - gdy nastąpiła kolizja,
   * \retval false - w przeciwnym wypadku.
   */
  virtual bool CzyKolizja(const Dron &BiezacyDron) const=0;
};

#endif

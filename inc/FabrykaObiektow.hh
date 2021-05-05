#ifndef FABRYKAOBIEKTOW_HH
#define FABRYKAOBIEKTOW_HH

//#include "Dron.hh"
#include "PrzeszkodaPr.hh"

using namespace std; 

/*!  
 *  \file FabrykaObiektow.hh
 *  \brief Definicja klasy FabrykaObiektow
 *
 *  Plik zawiera definicję klasy FabrykaObiektow.
 */

/*!
 * \brief Typ numeracyjny wyznaczający obiekty możliwe dostworzenia.
 *
 *  Typ numeracyjny wyznaczający obiekty możliwe dostworzenia.
 *  Pozwala na stworzenie drona i przeszkody prostopadłościennej.
 */
enum RodzajObiektu{RO_Dron, RO_PrzeszkodaPr};//, RD_Sciezka};

class FabrykaObiektow;

/*!
 * \brief Klasa WskFabryki modeluje pojęcie wskaźnika na fabrykę.
 *
 *  Klasa WskFabryki modeluje pojęcie wskaźnika na fabrykę jako zbioru 
 *  metod służących do stworzenia, usuwania i korzystania z fabryki.
 */
class WskFabryki: private shared_ptr<FabrykaObiektow> {
   friend class FabrykaObiektow;
   /*
    * Tworzy fabrykę.
    */
   void StworzFabryke();

   /*!
    * \brief Usuwa fabrykę.
    *
    * Usuwa fabrykę.
    * \pre brak
    * \post Usunięto Fabrykę.
    */
   void UsunFabryke() { this->reset(static_cast<FabrykaObiektow*>(nullptr)); }
 public:
   /*!
    * \brief Operator służący do wykorzystania fabryki.
    *
    * Operator służący do wykorzystania fabryki.
    * \pre Fabryka istnieje.
    * \post brak
    * \retval Referencję do wskazywanego pola.
    */
   FabrykaObiektow* operator -> () { return &**this; }
};

/*!
 * \brief Klasa FabrykaObiektow modeluje pojęcie fabryki.
 *
 *  Klasa FabrykaObiektow modeluje pojęcie fabryki jako zbioru domyślnych danych
 *  do tworzenia drona i  przeszkody i wskaźnik na jedyny obiekt tej klasy.
 *  Klasa pozwala na modyfikację domyślnych danych i tworzenie nowych obiektów.
 */
class FabrykaObiektow {
  /*! \brief domyślna pozycja drona */
    Wektor3D _domPozDr;
  /*! \brief domyślna pozycja przeszkody */
    Wektor3D _domPozPrz;
   // double _domOrientDr=0;
  /*! \brief domyślna wysokość przeszkody */
    double _domWysPrz=50;
  /*! \brief domyślna długość przeszkody */
    double _domDlPrz=50;
  /*! \brief domyślna szerokość przeszkody */
    double _domSzerPrz=50;
  /*! \brief wskażnik na fabrykę */
    static WskFabryki   _WFabryka;
  public:
   /*!
    * \brief Realizuje zmianę wartości wektora - domyślnej pozycji drona.
    * 
    * Realizuje zmianę wartości wektora - domyślnej pozycji drona.
    *
    * \pre brak
    * \post brak
    *       
    * \retval Referencję do wskazywanego pola.
    */
    Wektor3D& ZmienPozDr()            {return _domPozDr;}
   /*!
    * \brief Realizuje zmianę wartości wektora - domyślnej pozycji przeszkody.
    * 
    * Realizuje zmianę wartości wektora - domyślnej pozycji przeszkody.
    *
    * \pre brak
    * \post brak
    *       
    * \retval Referencję do wskazywanego pola.
    */
    Wektor3D& ZmienPozPrz()           {return _domPozPrz;}
   /*!
    * \brief Realizuje zmianę wartości zmiennej - domyślnej wysokości przeszkody.
    * 
    * Realizuje zmianę wartości wektora - domyślnej wysokości przeszkody.
    *
    * \pre brak
    * \post brak
    *       
    * \retval Referencję do wskazywanego pola.
    */
    double& ZmienWysPrz()             {return _domWysPrz;}
   /*!
    * \brief Realizuje zmianę wartości zmiennej - domyślnej długości przeszkody.
    * 
    * Realizuje zmianę wartości wektora - domyślnej długości przeszkody.
    *
    * \pre brak
    * \post brak
    *       
    * \retval Referencję do wskazywanego pola.
    */
    double& ZmienDlPrz()              {return _domDlPrz;}
   /*!
    * \brief Realizuje zmianę wartości zmiennej - domyślnej szerokości przeszkody.
    * 
    * Realizuje zmianę wartości wektora - domyślnej szerokości przeszkody.
    *
    * \pre brak
    * \post brak
    *       
    * \retval Referencję do wskazywanego pola.
    */
    double& ZmienSzerPrz()            {return _domSzerPrz;}

    /*
     * Tworzy obiekt o wskazanym typie.
     */
    std::shared_ptr<ObiektSceny> StworzObiekt(RodzajObiektu Rodzaj)const;
    //,Wektor3D Pozycja,double dl=0,double szer=0,double wys=0) const;

   /*!
    * \brief Funkcja służąca do używania fabryki.
    *
    * Funkcja służąca do używania fabryki.
    * \pre Fabryka istnieje.
    * \post brak
    * \retval Wskaźnik na fabrykę.
    */
    static WskFabryki& UzyjFabryke() { return _WFabryka; }
    /*!
    * \brief Wywołuje stworzenie fabryki.
    *
    * Wywołuje stworzenie fabryki.
    * \pre Fabryka nie istnieje.
    * \post Stworzono Fabrykę.
    */
    static void StworzFabryke() {_WFabryka.StworzFabryke();}
    /*!
    * \brief Wywołuje usunięcie fabryki.
    *
    * Wywołuje usunięcie fabryki.
    * \pre brak
    * \post Usunięto Fabrykę.
    */
    static void UsunFabryke() {_WFabryka.UsunFabryke();}
    /*!
    * \brief Destruktor.
    *
    * Destruktor.
    * \pre brak
    * \post brak
    */
    ~FabrykaObiektow()             {}      

private:
    friend class WskFabryki;
    /*!
    * \brief Konstruktor.
    *
    * Konstruktor.
    * \pre brak
    * \post brak
    */
    FabrykaObiektow()              {}
    /*!
    * \brief Konstruktor kopiujący. Kopiuje fabrykę i usuwa tą kopię.
    *
    * Konstruktor kopiujący. Kopiuje fabrykę i usuwa tą kopię.
    * \param[in]   - fabryka do skopiowania.
    * \pre Fabryka istnirje.
    * \post brak
    */
    FabrykaObiektow(const FabrykaObiektow&) = delete;
};

#endif

/*    Wektor3D WezPozDr()   const       {return _domPozDr;}
    Wektor3D WezPozPrz()  const       {return _domPozPrz;}
    double WezWysPrz()    const       {return _domWysPrz;}
    double WezDlPrz()     const       {return _domDlPrz;}
    double WezSzerPrz()   const       {return _domSzerPrz;}*/

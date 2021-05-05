#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"

/*!  
 *  \file Macierz.hh
 *  \brief Definicja szablonu Macierz
 *
 *  Plik zawiera definicję szablonu Macierz.
 */

/*!
 *  \brief Szablon Macierz modeluje pojęcie macierzy. 
 *
 *  Szablon Macierz Wym modeluje pojęcie macierzy jako kwadratowej tablicy 
 *  wartości służącej do pomnożenia przez wektor i wyznaczenia obrazu tego  
 *  wektora obróconego wokół początku układu współrzędnych o określony kąt
 *  oraz mnożenia dwóch macierzy.
 *  Szablon zawiera definicję macierzy jako dwuwymiarowej tablicy o  
 *  wymiarach Wym x Wym, której elementy odpowiedają elementom macierzy.
 *  Metody szablonu:
 *      double  operator() (int Wie, int Kol) const,
 *      double& operator() (int Wie, int Kol),
 *      void operator() (char os, double kat),
 *      Wektor<Wym> operator * (const Wektor2D& Wek_org) const.
 *      Macierz<Wym> operator * (const Macierz<Wym>& Mac_skl) const; 
 *      Macierz();
 */
template<int Wym>
class Macierz {
  //! macierz obrotu
  double _TabMac[Wym][Wym]; 

public:
  /*
   * Realizuje odczyt wartości pola macierzy o wskazanych współrzędnych.
   */
  inline 
  double  operator() (int Wie, int Kol) const; 

  /*
   * Realizuje zapis wartości do pola macierzy o wskazanych współrzędnych.
   */
  inline
  double& operator() (int Wie, int Kol);

  /*
   * Realizuje wypełnienie macierzy określonymi wartościami.
   */
  inline
  void operator() (char os, double kat);

  /*
   * Realizuje mnożenie macierzy i wektora.
   */
  template<int Wymiar>
  inline
  Wektor<Wymiar> operator * (const Wektor<Wymiar>& Wek_org) const;  

  /*
   * Realizuje mnożenie dwoch macierzy.
   */
  inline
  Macierz<Wym> operator * (const Macierz<Wym>& Mac_skl) const; 

  /*
   * Realizuje wypełnienie macierzy do macierzy jednostkowej.
   */
  inline Macierz();
};

/*!
 * \brief Realizuje odczyt wartości pola macierzy o wskazanych współrzędnych.
 *
 * Realizuje odczyt wartości pola macierzy o wskazanych współrzędnych.
 * \param[in] Wie - indeks wskazujący na wiersz z wskazanym polem macierzy,
 * \param[in] Kol - indeks wskazujący na kolumnę z wskazanym polem macierzy.
 * \pre Parametr Wie jest mniejszy od ilości wierszy.
 * \pre Parametr Kol jest mniejszy od ilości kolumn.
 * \post brak
 * \retval Wartość wskazywanego pola.
 */
template<int Wym>
inline double  Macierz<Wym>::operator() (int Wie, int Kol) const
{
  assert(0<=Wie&&Wie<Wym);
  assert(0<=Kol&&Kol<Wym);
  return _TabMac[Wie][Kol];
}

/*!
 * \brief Realizuje zapis wartości do pola macierzy o wskazanych współrzędnych.
 *
 * Realizuje zapis wartości do pola macierzy o wskazanych współrzędnych.
 * \param[in] Wie - indeks wskazujący na wiersz z wskazanym polem macierzy,
 * \param[in] Kol - indeks wskazujący na kolumnę z wskazanym polem macierzy.
 * \pre Parametr Wie jest mniejszy od ilości wierszy.
 * \pre Parametr Kol jest mniejszy od ilości kolumn.
 * \retval Referencja do wskazywanego pola.
 */
template<int Wym>
inline double& Macierz<Wym>::operator() (int Wie, int Kol)
{
  assert(0<=Wie&&Wie<Wym);
  assert(0<=Kol&&Kol<Wym);
  return _TabMac[Wie][Kol];
}


/*!
 * \brief Realizuje wpisanie do każdego pola macierzy określonej wartosci.
 *
 * Realizuje wpisanie do każdego pola macierzy określonej wartosci.
 * \param[in] os  - oznaczenie osi, wokół której ma nastąpić obrót,
 * \param[in] kat - wartość kąta wyrażona w radianach wpływająca na wpisywane  
 *                  do macierzy wartości.
 * \pre brak
 * \post Podana macierz musi zawierać odpowiednie wartości zależne od podanego
 *       kąta.
 */
template<int Wym>
inline
void Macierz<Wym>::operator() (char os, double kat)
{
  int i=0,j=0;
  switch(os){
  case 'x':        /* dla osi x */
    i=1;j=2; 
    break;
  case 'y':        /* dla osi y */
    i=0;j=2;
    break;
  case 'z':        /* dla osi z */
    i=0;j=1; /* w tym dla 2D, ponieważ zawartość macierzy jest odpowiednia */
    break;
  }
  _TabMac[i][i]=_TabMac[j][j]=cos(kat);
  _TabMac[i][j]=-(_TabMac[j][i]=pow(-1,i+j-1)*sin(kat));
}

/*!
 * \brief Realizuje mnożenie macierzy i wektora.
 *
 * Realizuje mnożenie macierzy i wektora.
 * \param[in] Wek_org - drugi czynnik mnożenia.
 * \pre Parametr Wek_org musi zawierać wczesniej przypisane dane.
 * \post brak
 * \retval Iloczyn dwóch argumentów przekazanych jako parametry.
 */
template<int Wym>
template<int Wymiar>
inline
Wektor<Wymiar> Macierz<Wym>::operator * (const Wektor<Wymiar>& Wek_org) const
{
  Wektor<Wymiar> Wek_wyn;
  for(int Wiersz=0;Wiersz<Wymiar;++Wiersz)
    {
      Wek_wyn[Wiersz]=0;
      for(int Kolumna=0; Kolumna<Wymiar; ++Kolumna)
        Wek_wyn[Wiersz]+=_TabMac[Wiersz][Kolumna]*Wek_org[Kolumna];
    }
  return Wek_wyn;
}

/*!
 * \brief Realizuje mnożenie dwoch macierzy.
 *
 * Realizuje mnożenie dwoch macierzy.
 * \param[in] Mac_skl - drugi czynnik mnożenia.
 * \pre Parametr Mac_skl musi zawierać wczesniej przypisane dane.
 * \post brak
 * \retval Iloczyn dwóch argumentów przekazanych jako parametry.
 */
template<int Wym>
inline
Macierz<Wym> Macierz<Wym>::operator * (const Macierz<Wym>& Mac_skl) const
{
  Macierz<Wym> Mac_wyn;
  for(int Wiersz=0;Wiersz<Wym;++Wiersz)
    for(int Kolumna=0; Kolumna<Wym; ++Kolumna)
      {
        Mac_wyn(Wiersz,Kolumna)=0;
        for(int skladnik=0;skladnik<Wym;++skladnik)
          Mac_wyn(Wiersz,Kolumna)+=_TabMac[Wiersz][skladnik]*
                                       Mac_skl(skladnik,Kolumna);
      }
  return Mac_wyn;
}


/*!
 * \brief Realizuje wypełnienie macierzy do macierzy jednostkowej.
 *
 * Konstruktor bezparametrowy.
 * Realizuje wypełnienie macierzy do macierzy jednostkowej.
 */
template<int Wym>
inline Macierz<Wym>::Macierz()
{
  for(int i=0; i<Wym; i++)
    for(int j=0; j<Wym; j++)
      {
        if(i==j)
          _TabMac[i][j]=1;
        else
          _TabMac[i][j]=0;
      }
}

/*!
 * \brief Wyświetla elementy macierzy obrotu na wyjściu.
 *
 * Wyświetla elementy macierzy obrotu na wyjściu.
 * \param[in] Strm - strumień danych wyjściowych,
 * \param[in] Mac - referencja do obiektu zawierającego elementy macierzy do 
 *                  wyświetlenia na wyjściu.
 *   
 * \pre Parametr Mac musi zawierać wczesniej przypisane dane.
 * \post brak
 * \retval Strm - macierz obrotu jako strumień danych wyjściowych.
 */
template<int Wym>
inline
std::ostream& operator << (std::ostream &Strm, const Macierz<Wym> &Mac)
{
  for(int wiersz=0;wiersz<Wym;wiersz++)
    {
      for(int kolumna=0;kolumna<Wym;kolumna++)
        Strm << std::setw(16) << std::fixed << std::setprecision(10) << 
                                                    Mac(wiersz,kolumna);
      Strm << std::endl;
    }
  return Strm;
}


#endif

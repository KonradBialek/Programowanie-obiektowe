#include "Scena.hh"

using namespace std;

/*!
 * \file Scena.cpp
 * \brief Definicja metod klasy Scena
 */

/*!
 * \brief Wyswietla informacje o ilości obiektów sceny i wektorów.
 *
 * Wyswietla informacje o ilości obiektów sceny i wektorów.
 *
 * \pre brak
 * \post Wyswietlono współrzędne informacje o ilości obiektów sceny i wektorów.
 */
void Scena::WyswietlIloscObiektow() const 
{
  cout << endl << "Laczna ilosc stworzonych obiektow klasy ObiektSceny: ";
  cout << ObiektSceny::WezIloscOgolemSc() << endl;
  cout << "      Ilosc istniejacych obiektow klasy ObiektSceny: ";
  cout << ObiektSceny::WezIloscSc() << endl; 

  cout << endl << "Laczna ilosc stworzonych obiektow klasy Wektor3D: ";
  cout << Wektor<3>::WezIloscOgolem() << endl;
  cout << "      Ilosc istniejacych obiektow klasy Wektor3D: ";
  cout << Wektor<3>::WezIlosc() << endl;
}

/*!
 * \brief Realizuje zapis wartości do pola drona sceny o 
 *        wskazanym indeksie.
 *
 * Realizuje zapis wartości do pola drona sceny o wskazanym
 * indeksie.
 * \pre brak
 * \post brak
 * \retval Referencję do wskazywanego pola.
 */
shared_ptr<Dron> Scena::BiezacyDron() const    
{ 
  int nr_dr=nr_drona;
  std::list<std::shared_ptr<Dron>>::const_iterator it;
  for(it=_ListaDr.begin(); it!=_ListaDr.end(); ++it, --nr_dr)
    if(nr_dr==0) return *it;
  return nullptr;
} 

/*!
 * \brief Realizuje zapis wartości do pola przeszkody sceny o 
 *        wskazanym indeksie.
 *
 * Realizuje zapis wartości do pola przeszkody sceny o wskazanym
 * indeksie.
 * \pre brak
 * \post brak
 * \retval Referencję do wskazywanego pola.
 */
shared_ptr<PrzeszkodaPr> Scena::BiezacaPrzeszkoda() const    
{ 
  int nr_pr=nr_przeszkody;
  std::list<std::shared_ptr<PrzeszkodaPr>>::const_iterator it;
  for(it=_ListaPr.begin(); it!=_ListaPr.end(); ++it, --nr_pr)
    if(nr_pr==0) return *it;
  return nullptr;
} 

/*!
 * \brief Wyswietla współrzędne obiektów.
 *
 * Wyswietla współrzędne obiektów.
 *
 * \pre brak
 * \post Wyswietlono współrzędne obiektów.
 */
void Scena::WyswietlWspolOb() const
{
  int j=0;
  list<shared_ptr<ObiektSceny>>::const_iterator i;
  cout << endl;
  cout << "      0. - zaniechaj zmiany selekcji" << endl<<endl;
  cout << " Spis dronow i ich wspolrzednych (x, y, z):" << endl << endl;
  cout << "  nr drona |                    wspolrzedne" << endl;
  cout << " ------------------------------------------------------------" << endl;
  for(i=_ListaOb.begin(); i!=_ListaOb.end(); ++i,++j)
  cout << "     " << j+1 << "     |" << (*i)->Wez_Wektor_Pozycji();
  cout << endl;
}
/*!
 * \brief Wyswietla współrzędne dronów.
 *
 * Wyswietla współrzędne dronów.
 *
 * \pre Istnieje conajmniej jeden dron.
 * \post Wyswietlono współrzędne dronów.
 */
void Scena::WyswietlWspolDronow() const
{
  int j=0;
  list<shared_ptr<Dron>>::const_iterator i;
  cout << endl;
  cout << "      0. - zaniechaj zmiany selekcji" << endl<<endl;
  cout << " Spis dronow i ich wspolrzednych (x, y, z):" << endl << endl;
  cout << "  nr drona |                    wspolrzedne" << endl;
  cout << " ------------------------------------------------------------" << endl;
  for(i=_ListaDr.begin(); i!=_ListaDr.end(); ++i,++j)
  cout << "     " << j+1 << "     |" << (*i)->Wez_Wektor_Pozycji();
  cout << endl;
}

/*!
 * \brief Wyswietla współrzędne przeszkód.
 *
 * Wyswietla współrzędne przeszkód.
 *
 * \pre brak
 * \post Wyswietlono współrzędne przeszkód.
 */
void Scena::WyswietlWspolPrzeszkod() const
{
  int j=0;
  list<shared_ptr<PrzeszkodaPr>>::const_iterator i;
  cout << endl;
  cout << "      0. - zaniechaj wyboru przeszkody" << endl<<endl;
  cout << " Spis przeszkod i ich wspolrzednych (x, y, z):" << endl << endl;
  cout << "  nr przeszkody |                    wspolrzedne" << endl;
  cout << " ------------------------------------------------------------" << endl;
  for(i=_ListaPr.begin(); i!=_ListaPr.end(); ++i,++j)
  cout << "       " << j+1 << "        |" << (*i)->Wez_Wektor_Pozycji();
  cout << endl;
}

/*!
 * \brief Wyswietla współrzędne aktualnego drona.
 *
 * Wyswietla współrzędne aktualnego drona.
 *
 * \pre Istnieje wybrany dron.
 * \post Wyswietlono współrzędne aktualnego drona.
 */
void Scena::WyswietlAktualnegoDrona() const
{
  cout <<endl;
  cout << "Aktualnie wyselekcjonowanym dronem jest:" << endl << "Dron ";
  cout << nr_drona+1 << ". Wspolrzedne: ";
  cout << (*BiezacyDron()).Wez_Wektor_Pozycji();
}

/*!
 * \brief Animuje lot drona.
 *
 * Wyświetla drona w kolejnych klatkach lotu.
 * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem,
 * \param[in] droga - zmienna reprezentująca drogę,
 * \param[in] kat_wzn - zmienna reprezentująca kąt wznoszenia,
 * \param[in] krok_lotu - zmienna reprezentująca krok lotu drona,
 * \param[in] krok_wir - zmienna reprezentująca krok obrotu wirnika,
 * \param[in] nr_dr - zmienna reprezentująca numer drona.
 *
 * \pre Parametr Lacze musi się odwoływać do odpowiedniej zmiennej.
 * \post Wykonano animację lotu drona.
 *
 * \retval true - po wykonaniu animacji.
 */
bool Scena::AnimacjaLotu(PzG::LaczeDoGNUPlota& Lacze, double droga,double kat_wzn,
double krok_lotu,double krok_wir,int nr_dr)
{
  int ilosc_klatek=fabs(droga)/krok_lotu, kier_obr=0;
  double resztka=fabs(droga)-ilosc_klatek*krok_lotu;
  Macierz3x3 Macierz_obr;
  Wektor3D Przesuw;
  nr_drona=nr_dr;
  Macierz_obr=BiezacyDron()->Obrot_stopnie(BiezacyDron()->Wez_Kat_OrientacjiZ()); 
  BiezacyDron();
  for(int nr_klatki=1; nr_klatki<=ilosc_klatek; ++nr_klatki)
    {
      BiezacyDron()->Obrot_wirnikow(0,krok_wir,nr_klatki,kier_obr,Macierz_obr);
      Przesuw=BiezacyDron()->PrzesunPoz(krok_lotu*droga/fabs(droga),kat_wzn);
      if(CzyKolizjaZBD()){
        BiezacyDron()->PrzesunPoz(-krok_lotu*droga/fabs(droga), kat_wzn);
        return true;
        }
      BiezacyDron()->Przesun(Przesuw);
      BiezacyDron()->Zapisz();
      Lacze.Rysuj();
      usleep(200000);
    }
  if(resztka!=0)
    {
      BiezacyDron()->Obrot_wirnikow(0,krok_wir,ilosc_klatek+1,kier_obr,Macierz_obr);
      Przesuw=BiezacyDron()->PrzesunPoz(resztka*droga/fabs(droga),kat_wzn);
      if(CzyKolizjaZBD()) {
        BiezacyDron()->PrzesunPoz(-resztka*droga/fabs(droga), kat_wzn);
        return true;
        }
      BiezacyDron()->Przesun(Przesuw);
      BiezacyDron()->Zapisz();
      Lacze.Rysuj();
      usleep(200000);
    }
  return false;
}

/*!
 * \brief Animuje obrot drona.
 *
 * Wyświetla drona w kolejnych klatkach obrotu.
 * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem,
 * \param[in] kat_stopnie - zmienna reprezentująca pełen kąt obrotu,
 * \param[in] krok_obr - zmienna reprezentująca krok obrotu drona,
 * \param[in] krok_wir - zmienna reprezentująca krok obrotu wirnika,
 * \param[in] nr_dr - zmienna reprezentująca numer drona.
 *
 * \pre Parametr Lacze musi się odwoływać do odpowiedniej zmiennej.
 * \post Wykonano animację obrotu drona.
 *
 * \retval true - po wykonaniu animacji.
 */
bool Scena::AnimacjaObrotu(PzG::LaczeDoGNUPlota & Lacze, double kat_stopnie,
double krok_obr,double krok_wir,int nr_dr)
{
  int ilosc_klatek=fabs(kat_stopnie)/krok_obr;
  double resztka=fabs(kat_stopnie)-ilosc_klatek*krok_obr;
  int kier_obr=kat_stopnie/fabs(kat_stopnie);
  Macierz3x3 Macierz_obr;

  nr_drona=nr_dr;
  for(int nr_klatki=1; nr_klatki<=ilosc_klatek; ++nr_klatki)
    {
      Macierz_obr=BiezacyDron()->Obrot_stopnie(krok_obr*kier_obr);
      BiezacyDron()->Obrot(Macierz_obr);
      BiezacyDron()->Obrot_wirnikow(1,krok_wir,nr_klatki,kier_obr, Macierz_obr);
      BiezacyDron()->Zapisz();
      Lacze.Rysuj();
      usleep(200000);
    }
  if(resztka!=0)
    {
      Macierz_obr=BiezacyDron()->Obrot_stopnie(resztka*kier_obr);
      BiezacyDron()->Obrot(Macierz_obr);
      BiezacyDron()->Obrot_wirnikow(1,krok_wir,ilosc_klatek+1,kier_obr, Macierz_obr);
      BiezacyDron()->Zapisz();
      Lacze.Rysuj();
      usleep(200000);
    }
  return false;
}

/*!
 * \brief Tworzy fabrykę. Tworzy i inicjuje sytuację początkową.
 * 
 * Konstruktor parametryczny. Tworzy fabrykę. Tworzy i inicjuje sytuacj
 * początkową.
 *   
 * \pre brak
 * \post Zainicjoeano sytuację początkową.
 */
Scena::Scena(PzG::LaczeDoGNUPlota &Lacze)//WskFabryki* FabrykaObiektow)
{
  Wektor3D Pozycja;
  int j=0;
  //double wys=0,szer=0,dl=0;
  FabrykaObiektow::StworzFabryke();
  for(int k=0; k<ILOSC_DRONOW;++k){
    Pozycja[0]=50-50*k;
    Pozycja[1]=100-100*k;
    Pozycja[2]=25-25*k;
    FabrykaObiektow::UzyjFabryke()->ZmienPozDr()=Pozycja;
    DodajDron();}//Pozycja);}//FabrykaObiektow);
  for(int i=0; i<ILOSC_PRZESZKODPR;++i)
    DodajPrzeszkodePr();//Pozycja,wys,szer,dl);//FabrykaObiektow);

  for(std::list<std::shared_ptr<ObiektSceny>>::iterator i=_ListaOb.begin(); i!=_ListaOb.end(); ++i, j++){
   (*i)->Inicjuj(j,Lacze);
   (*i)->Zapisz();}
}

/*!
 * \brief Dodaje nowego drona do list dronów i obiektów.
 *
 * Dodaje nowego drona do list dronów i obiektów.
 *
 * \pre brak
 * \post Dodano drona do list.
 */
shared_ptr<Dron> Scena::DodajDron()//Wektor3D Pozycja)//WskFabryki* FabrykaObiektow)
{
  shared_ptr<Dron> WDr=static_pointer_cast<Dron>(FabrykaObiektow::UzyjFabryke()->StworzObiekt(RO_Dron));//,Pozycja));
  _ListaDr.push_back(WDr);
  _ListaOb.push_back(WDr);
  return WDr;
}

/*!
 * \brief Dodaje nową przeszkodę do list przeszkód i obiektów.
 *
 * Dodaje nową przeszkodę do list przeszkód i obiektów.
 *
 * \pre brak
 * \post Dodano przeszkodę do list.
 */
shared_ptr<PrzeszkodaPr> Scena::DodajPrzeszkodePr()//Wektor3D Pozycja,double dl,double szer,double wys)//WskFabryki *FabrykaObiektow)
{
  shared_ptr<ObiektSceny> Wsk=FabrykaObiektow::UzyjFabryke()->StworzObiekt(RO_PrzeszkodaPr);//,Pozycja);//,dl,szer,wys);
  shared_ptr<PrzeszkodaPr> WPr=static_pointer_cast<PrzeszkodaPr>(Wsk);
  _ListaPr.push_back(WPr);
  _ListaOb.push_back(WPr);
  return WPr;
}

/*!
 * \brief Usuwa obiekty sceny i fabrykę.
 * 
 * Destruktor bezparametryczny. Usuwa obiekty sceny i fabrykę.
 *   
 * \pre brak
 * \post Usunięto obiekty sceny i fabrykę.
 */
Scena::~Scena()
{
 // for(int i=0; i<ILOSC_DRONOW;++i){
  _ListaDr.clear();
  //}
  _ListaPr.clear();
 // for(int i=0; i<ILOSC_DRONOW+ILOSC_PRZESZKODPR;++i){
  _ListaOb.clear();
//  }
  FabrykaObiektow::UsunFabryke();
  //WyswietlWspolDronow();
  //WyswietlWspolPrzeszkod();
  //WyswietlWspolOb();
  WyswietlIloscObiektow(); 
  cout << endl;
}


/*!
 * \brief Sprawdza czy kontrolowany dron koliduje z innymi obiektami sceny.
 *
 * Sprawdza czy kontrolowany dron koliduje z innymi obiektami sceny.
 *
 * \pre brak
 * \post brak
 *
 * \retval true - gdy nastąpiła kolizja,
 * \retval false - w przeciwnym wypadku.
 */
bool Scena::CzyKolizjaZBD() const
{
  for(const shared_ptr<ObiektSceny> &WOb: _ListaOb){
    if(WOb==BiezacyDron()) continue;
    if(WOb->CzyKolizja(*BiezacyDron())) return true;
    }
  return false;
}

/*!
 * \brief Usuwa kontrolowanego drona.
 *
 * Usuwa kontrolowanego drona.
 * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem,
 *
 * \pre Usuwany dron istnieje.
 * \post Usunięto drona.
 */
void Scena::UsunDrona(PzG::LaczeDoGNUPlota &Lacze)
{
  BiezacyDron()->UsunDrona(Lacze);
  _ListaOb.remove(BiezacyDron());
  _ListaDr.remove(BiezacyDron());
  BiezacyDron().reset();
}

/*!
 * \brief Usuwa wskazaną przeszkodę.
 *
 * Usuwa wskazaną przeszkodę.
 * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem,
 *
 * \pre Usuwana przeszkoda istnieje.
 * \post Usunięto przeszkodę.
 */
void Scena::UsunPrzeszkode(PzG::LaczeDoGNUPlota &Lacze)
{
  BiezacaPrzeszkoda()->UsunPrzeszkode(Lacze);
  _ListaOb.remove(BiezacaPrzeszkoda());
  _ListaPr.remove(BiezacaPrzeszkoda());
  BiezacaPrzeszkoda().reset();
}

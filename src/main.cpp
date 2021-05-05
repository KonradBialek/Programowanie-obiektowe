#include "Scena.hh"

using namespace std;

/*!
 * \brief Pyta użytkownika czy usunąć drona, pobiera decyzję z klawiatury
 *        i zwraca informację czy ją pobrano.
 *
 * Pyta użytkownika czy usunąć drona, pobiera decyzję z klawiatury
 * i zwraca informację czy ją pobrano.
 *
 * \pre brak
 * \post Pobrano decyzję.
 * \retval true - gdy decyzja jest pozytywna,
 * \retval false - gdy decyzja jest negatywna.
 */
bool CzyUsunac(Scena &Sc, int ilosc_dronow)
{
  char decyzja;
  if(ilosc_dronow<=1) {
    cerr<<" Pozostal jeden dron. Nie mozna go usunac."<<endl;
    return false;
  }
  Sc.WyswietlAktualnegoDrona();
  cout <<endl << " Czy na pewno usunac tego drona? (t/n)> ";
  cin>>decyzja;
  while(cin.fail()||(decyzja!='t'&&decyzja!='n'))
    {
       cin.clear(); cin.ignore( 1000, '\n' );
       cout << " Nieznana lub niepoprawna decyzja. Wprowadz decyzje jeszcze raz."
            << endl;
       cin >> decyzja;
    }
  return decyzja=='t'?true:false;
}

/*!
 * \brief Pyta użytkownika czy usunąć przeszkodę, pobiera decyzję z klawiatury
 *        i zwraca informację czy ją pobrano.
 *
 * Pyta użytkownika czy usunąć przeszkodę, pobiera decyzję z klawiatury
 * i zwraca informację czy ją pobrano.
 *
 * \post Pobrano decyzję.
 * \retval true - gdy decyzja jest pozytywna,
 * \retval false - gdy decyzja jest negatywna.
 */
bool CzyUsunac()
{
  char decyzja;
  cout << endl << " Czy na pewno usunac ta przeszkode? (t/n)> ";
  cin>>decyzja;
  while(cin.fail()||(decyzja!='t'&&decyzja!='n'))
    {
       cin.clear(); cin.ignore( 1000, '\n' );
       cout << " Nieznana lub niepoprawna decyzja. Wprowadz decyzje jeszcze raz."
            << endl;
       cin >> decyzja;
    }
  return decyzja=='t'?true:false;
}

/*!
 * \brief Pyta użytkownika o pozycję tworzonej przeszkody lub drona, pobiera ją z klawiatury
 *        i zwraca informację czy ją pobrano.
 *
 * Pyta użytkownika o pozycję tworzonej przeszkody lub drona, pobiera je z klawiatury
 * i zwraca informację czy ją pobrano.
 *
 * \post Pobrano pozycję.
 * \retval true - gdy pozycja została poprawnie pobrana.
 */
bool PobierzPozycje(bool typ)//,Wektor3D &Pozycja)
{
  Wektor3D Pozycja;
  cout << endl << "Podaj docelowe wspolrzedne "<<(typ?"srodka przeszkody":"drona")<<": x y z > ";
  cin >> Pozycja;
  while(cin.fail())
    {
       cin.clear(); cin.ignore( 1000, '\n' );
       cout << " Nieznane lub niepoprawne wartosci. Wprowadz wspolrzedne drona jeszcze raz."
            << endl;
       cin >> Pozycja;
    }
  typ?
  FabrykaObiektow::UzyjFabryke()->ZmienPozPrz()=Pozycja:
  FabrykaObiektow::UzyjFabryke()->ZmienPozDr()=Pozycja;
  return true;
}

/*!
 * \brief Pyta użytkownika o wymiary tworzonej przeszkody, pobiera je z klawiatury
 *        i zwraca informację czy je pobrano.
 *
 * Pyta użytkownika o wymiary tworzonej przeszkody, pobiera je z klawiatury
 * i zwraca informację czy je pobrano.
 *
 * \post Pobrano wymiary.
 * \retval true - gdy wymiary zostaną poprawnie pobrane.
 */
bool PobierzWymiary()//double &dl,double &szer,double &wys)
{
  double wys, szer, dl;
  cout << "Podaj wymiary przeszkody wzdluz osi OX, OY, OZ "<<endl;
  cout << "wymiar_x wymiar_y wymiar_z > ";
  cin >> dl >> szer >> wys;
  while(cin.fail()||dl<=0||szer<=0||wys<=0)
    {
       cin.clear(); cin.ignore( 1000, '\n' );
       cout << " Nieznane lub niepoprawne wartosci. Wprowadz wspolrzedne drona jeszcze raz."
            << endl;
       cin >> dl >> szer >> wys;
    }
  FabrykaObiektow::UzyjFabryke()->ZmienDlPrz()=dl;
  FabrykaObiektow::UzyjFabryke()->ZmienSzerPrz()=szer;
  FabrykaObiektow::UzyjFabryke()->ZmienWysPrz()=wys;
  return true;
}
/*!
 * \brief Pyta użytkownika o numer drona do kontroli, pobiera go z klawiatury
 *        i zwraca informację czy go pobrano.
 *
 * Pyta użytkownika o numer drona do kontroli, pobiera je z klawiatury
 * i zwraca informację czy go pobrano.
 * \param[in] nr_dr - referencja do zmiennej reprezentującej numer drona,
 * \param[in] ilosc_dronow - zmienna reprezentująca liczbę dronów.
 *
 * \pre Parametr nr_dr musi się odwoływać do odpowiedniej zmiennej,
 * \post Pobrano nr_dr.
 * \retval true - gdy nr_dr zostanie poprawnie pobrany.
 */
bool PobierzNrDrona(int &nr_dr,int ilosc_dronow)
{
  cout << " Podaj numer drona lub 0 > ";
  cin >> nr_dr;
  while(cin.fail()||nr_dr<0||nr_dr>ilosc_dronow)
    {
       cin.clear(); cin.ignore( 1000, '\n' );
       cout << " Nieznana lub niepoprawna wartosc. Wprowadz numer drona jeszcze raz."
            << endl;
       cin >> nr_dr;
    }
  if(nr_dr==0) return false;
  nr_dr--;
  return true;
}

/*!
 * \brief Pyta użytkownika o numer przeszkody do usunięcia, pobiera go z klawiatury
 *        i zwraca informację czy go pobrano.
 *
 * Pyta użytkownika o numer przeszkody do usunięcia, pobiera go z klawiatury
 * i zwraca informację czy go pobrano.
 * \param[in] nr_pr - referencja do zmiennej reprezentującej numer przeszkody,
 * \param[in] ilosc_przeszkod - zmienna reprezentująca liczbę przeszkód.
 *
 * \pre Parametr nr_pr musi się odwoływać do odpowiedniej zmiennej,
 * \post Pobrano nr_pr.
 * \retval true - gdy nr_pr zostanie poprawnie pobrany.
 */
bool PobierzNrPrzeszkody(int &nr_pr,int ilosc_przeszkod)
{
  cout << " Podaj numer przeszkody lub 0 > ";
  cin >> nr_pr;
  while(cin.fail()||nr_pr<0||nr_pr>ilosc_przeszkod)
    {
       cin.clear(); cin.ignore( 1000, '\n' );
       cout << " Nieznana lub niepoprawna wartosc. Wprowadz numer drona jeszcze raz."
            << endl;
       cin >> nr_pr;
    }
  if(nr_pr==0) return false;
  nr_pr--;
  return true;
}


/*!
 * \brief Dodaje drona, inicjuje go i zapisuje.
 *
 * Dodaje drona, inicjuje go i zapisuje.
 *
 * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem,
 * \param[in] Sc - referencja do obiektu reprezentującego scenę,
 * \param[in] ilosc_dronow - zmienna reprezentująca liczbę dronów,
 * \param[in] Dr - wskaźnik na drona.
 * \pre brak
 * \post Dodano drona.
 */
void DDrona(PzG::LaczeDoGNUPlota &Lacze, Scena &Sc, int &ilosc_dronow,shared_ptr<Dron> &Dr)
{
  PobierzPozycje(0);//,Pozycja);
  Dr=Sc.DodajDron();//Pozycja);
  Dr->Inicjuj(3,Lacze);
  Dr->Zapisz(); ++ilosc_dronow;
}

/*!
 * \brief Dodaje przeszkodę, inicjuje ją i zapisuje.
 *
 * Dodaje przeszkodę, inicjuje ją i zapisuje.
 *
 * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem,
 * \param[in] Sc - referencja do obiektu reprezentującego scenę,
 * \param[in] ilosc_przeszkod - zmienna reprezentująca liczbę przeszkód,
 * \param[in] Pr - wskaźnik na przeszkodę.
 * \pre brak
 * \post Dodano przeszkodę.
 */
void DPrzeszkode(PzG::LaczeDoGNUPlota &Lacze, Scena &Sc, int &ilosc_przeszkod,shared_ptr<PrzeszkodaPr> &Pr)
{
  PobierzPozycje(1);//,Pozycja); 
  PobierzWymiary();//dl,szer,wys);
  Pr=Sc.DodajPrzeszkodePr();//Pozycja,dl,szer,wys);
  Pr->Inicjuj(6,Lacze);
  Pr->Zapisz(); ++ilosc_przeszkod;
}

/*!
 * \brief Usuwa drona.
 *
 * Usuwa drona.
 *
 * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem,
 * \param[in] Sc - referencja do obiektu reprezentującego scenę,
 * \param[in] ilosc_dronow - zmienna reprezentująca liczbę dronów,
 * \param[in] nr_dr - zmienna reprezentująca numer drona.
 * \pre Dron istnieje.
 * \post Usunięto drona.
 */
void UDrona(PzG::LaczeDoGNUPlota &Lacze, Scena &Sc, int &ilosc_dronow,int &nr_dr)
{
  if(CzyUsunac(Sc,ilosc_dronow)){
    Sc.UsunDrona(Lacze);
    Sc.Pobierz_Nr_Drona()=nr_dr=0; --ilosc_dronow;
    cout << endl << " Drona usunieto."<< endl;
    Sc.WyswietlAktualnegoDrona();}
}

/*!
 * \brief Usuwa przeszkodę.
 *
 * Usuwa przeszkodę.
 *
 * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem,
 * \param[in] Sc - referencja do obiektu reprezentującego scenę,
 * \param[in] ilosc_przeszkod - zmienna reprezentująca liczbę przeszkód,
 * \param[in] nr_pr - zmienna reprezentująca numer przeszkody.
 * \pre Przeszkoda istnieje.
 * \post Usunięto przeszkodę.
 */
void UPrzeszkode(PzG::LaczeDoGNUPlota &Lacze, Scena &Sc, int &ilosc_przeszkod,int &nr_pr)
{
  if(ilosc_przeszkod>0);
  else {cout << " Brak przeszkod."<< endl; return;}
  Sc.WyswietlWspolPrzeszkod();
  if(PobierzNrPrzeszkody(nr_pr,ilosc_przeszkod)){
    Sc.Pobierz_Nr_Przeszkody()=nr_pr;
    if(CzyUsunac()){ Sc.UsunPrzeszkode(Lacze);
      Sc.Pobierz_Nr_Przeszkody()=nr_pr=0;
      cout << endl << " Przeszkode usunieto."<< endl; --ilosc_przeszkod;
      }
    }
}

/*!
 * \brief Pyta użytkownika o dodatnią wartość skali powiększenia drona 
 *        (wartość mniejsza od 1 - pomniejszenia), pobiera je z klawiatury
 *        i zwraca informację czy ją pobrano.
 *
 * Pyta użytkownika o dodatnią wartość skali powiększenia drona 
 * (wartość mniejsza od 1 - pomniejszenia), pobiera je z klawiatury
 * i zwraca informację czy ją pobrano.
 * \param[in] skala - referencja do zmiennej reprezentującej numer drona.
 *
 * \pre Parametr skala musi się odwoływać do odpowiedniej zmiennej,
 * \post Pobrano skala.
 * \retval true - gdy skala zostanie poprawnie pobrany.
 */
bool PobierzSkale(double &skala)
{
  cout << " Podaj dodatnia wartosc skali wzgledem obecnych wymiarow drona: ";
  cin >> skala;
  while(cin.fail()||skala<=0)
    {
       cin.clear(); cin.ignore( 1000, '\n' );
       cout << " Nieznana lub niedodatnia wartosc. Wprowadz skale jeszcze raz."
            << endl;
       cin >> skala;
    }
  return true;
}

/*!
 * \brief Pyta użytkownika o długość elementarnego kroku w trakcie lotu drona
 *        w trakcie obrotu drona lub obrotu wirników (w zależności od 
 *        wywołania), pobiera je z klawiatury i zwraca informację czy je pobrano.
 *
 * Pyta użytkownika o długość elementarnego kroku w trakcie lotu drona
 * w trakcie obrotu drona lub obrotu wirników (w zależności od 
 * wywołania), pobiera je z klawiatury i zwraca informację czy je pobrano.
 * \param[in] krok - referencja do zmiennej reprezentującej krok,
 * \param[in] typ - zmienna reprezentująca typ pobieranych danych.
 *
 * \pre Parametr krok musi się odwoływać do odpowiedniej zmiennej,
 * \post Pobrano krok.
 * \retval true - gdy krok zostanie poprawnie pobrany.
 */
bool PobierzKrok(double &krok, int typ)
{
  cout << " Podaj dodatnia długosc elementarnego kroku "<< 
  (typ==2?"obrotu wirnikow: ":
  (typ==0?"w trakcie lotu drona: ":"w trakcie obrotu drona: "));
  cin >> krok;
  while(cin.fail()||krok<=0)
    {
       cin.clear(); cin.ignore( 1000, '\n' );
       cout << " Nieznana lub niedodatnia wartosc. Wprowadz wartosc jeszcze raz."
            << endl;
       cin >> krok;
    }
  return true;
}

/*!
 * \brief Pyta użytkownika o długość drogi i kąt wznoszenia/opadania, pobiera je z 
 *        klawiatury i zwraca informację czy je pobrano.
 *
 * Pyta użytkownika o długość drogi i kąt wznoszenia/opadania, pobiera je z 
 * klawiatury i zwraca informację czy je pobrano.
 * \param[in] droga - referencja do zmiennej reprezentującej drogę,
 * \param[in] kat_wzn - referencja do zmiennej reprezentującej kąt 
 *                      wznoszenia/opadania.
 *
 * \pre Parametr droga musi się odwoływać do odpowiedniej zmiennej,
 * \pre Parametr kat musi się odwoływać do odpowiedniej zmiennej.
 * \post Pobrano drogę i kąt.
 * \retval true - gdy droga i kąt zostaną poprawnie pobrane.
 */
bool PobierzDrogeIKat(double &droga, double &kat_wzn)
{
  cout << endl << endl;
  cout << " Podaj dodatnia dlugosc drogi przelotu i kat wznoszenia (+)/ opadania (-).";
  cout << endl;
  cout << "            Dlugosc drogi: ";
  cin >> droga;
  while(cin.fail()||droga<=0)
    {
      cin.clear();
      cin.ignore( 1000, '\n' );
      cout << " Nieznana lub niedodatnia wartosc. Wprowadz wspolrzedne jeszcze raz."
           << endl;
      cin >> droga;
    }
  cout << " Kat wznoszenia [stopnie] (z otwartego obustronnie przedzialu od "
       << "-90 do 90): ";
  cin >> kat_wzn;
  while(cin.fail()||kat_wzn>=90||kat_wzn<=-90)
    {
      cin.clear();
      cin.ignore( 1000, '\n' );
      cout << " Nieznana lub nieprawidlowa wartosc. Wprowadz kat jeszcze raz."
           << endl;
      cin >> kat_wzn;
    }
  return true;
}

/*!
 * \brief Pyta użytkownika okąt obrotu wyrażony w stopniach, pobiera 
 *        go z klawiatury i zwraca informację czy pobrano kąt obrotu.
 *
 * Pyta użytkownika okąt obrotu wyrażony w stopniach, pobiera 
 * go z klawiatury i zwraca informację czy pobrano kąt obrotu.
 * \param[in] kat_obrotu - zmienna reprezenująca kąt obrotu.
 *
 * \pre Parametr kat_obrotu musi się odwoływać do odpowiedniej zmiennej.
 * \post Pobrano kąt obrotu.
 * \retval true - gdy kąt obrotu zostaną poprawnie pobrane.
 */
bool PobierzKatObrotu(double &kat_obrotu)
{
  cout << " Podaj kat obrotu w stopniach: ";
  cin >> kat_obrotu;
  while(cin.fail()){
      cin.clear(); cin.ignore( 1000, '\n' );
      cout << "Nieznana wartosc. Wprowadz kat jeszcze raz." << endl;
      cin >> kat_obrotu;
  }
  return true;
}

/*!
 * \brief Wyświetla liczbę wektorów i menu programu.
 *
 * Wyświetla liczbę wektorów i menu programu.
 * \pre brak
 * \post Wyświetlono liczbę wektorów i menu.
 */
void WyswietlMenu()
{
  cout << endl;
  cout << " D - dodaj drona" << endl;
  cout << " P - dodaj przeszkode" << endl;
  cout << " U - usun wyselekcjonowanego drona" << endl;
  cout << " R - usun przeszkode" << endl;
  cout << " o - obrot drona" << endl;
  cout << " j - lot na wprost" << endl;
  cout << " s - selekcja drona" << endl;
  cout << " u - usun sciezke drona" << endl;
  cout << " m - wyswietl ponownie menu" << endl << endl;
  cout << " k - zakoncz dzialanie programu" << endl;
}

/*!
 * \brief Uruchamia odpowiednie części programu w zależnności od wybranej opcji.
 *
 * Uruchamia odpowiednie części programu w zależnności od wybranej opcji.
 * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem,
 * \param[in] Sc - referencja do obiektu reprezentującego scenę,
 * \param[in] wybor - zmienna reprezentująca wybraną opcję,
 * \param[in] nr_dr - zmienna reprezentująca numer drona,
 * \param[in] ilosc_dronow - zmienna reprezentująca liczbę dronów,
 * \param[in] nr_pr - zmienna reprezentująca numer przeszkody,
 * \param[in] ilosc_przeszkod - zmienna reprezentująca liczbę przeszkód.
 *
 * \pre Parametr Lacze musi się odwoływać do odpowiedniej zmiennej,
 * \pre Parametr Sc musi się odwoływać do odpowiedniej zmiennej.
 * \post Wywołano odpowiednią opcję.
 */
void WyborOpcji(PzG::LaczeDoGNUPlota &Lacze,Scena &Sc,char wybor,int &nr_dr,int &ilosc_dronow, int &nr_pr, int &ilosc_przeszkod)
{
  double                droga, kat_wzn, krok_lotu, krok_obr, krok_wir;
  double                kat_stopnie=0;//, wys, szer, dl;
  Wektor3D              Pozycja;
  shared_ptr<Dron> Dr;
  shared_ptr<PrzeszkodaPr> Pr;

  switch(wybor){
  case 'D':
    DDrona(Lacze,Sc,ilosc_dronow,Dr);
    break;
  case 'P':
    DPrzeszkode(Lacze,Sc,ilosc_przeszkod,Pr);
    break;
  case 'U':
    UDrona(Lacze,Sc,ilosc_dronow,nr_dr);
    break;
  case 'R':
    UPrzeszkode(Lacze,Sc,ilosc_przeszkod,nr_pr);
    break;
  case 'o':  /* obrót o kąt */
    Sc.WyswietlAktualnegoDrona();
    if(PobierzKatObrotu(kat_stopnie)&&PobierzKrok(krok_obr,1)
                                    &&PobierzKrok(krok_wir,2))
      if(Sc.AnimacjaObrotu(Lacze,kat_stopnie, krok_obr, krok_wir,nr_dr))
        cout <<endl<< " Wykryta została kolizja!!! Lot zostal przerwany."<<endl;
    break;
  case 'j':  /* przesunięcie o drogę i kąt */
    Sc.WyswietlAktualnegoDrona();
    if(PobierzDrogeIKat(droga, kat_wzn)&&PobierzKrok(krok_lotu,0)
                                    &&PobierzKrok(krok_wir,2))
      if(Sc.AnimacjaLotu(Lacze,droga,kat_wzn,krok_lotu,krok_wir,nr_dr))
        cout <<endl<< "Wykryta została kolizja!!! Lot zostal przerwany."<<endl;
    break;
  case 's':
    Sc.WyswietlAktualnegoDrona();
    Sc.WyswietlWspolDronow();
    if(PobierzNrDrona(nr_dr,ilosc_dronow))
      Sc.Pobierz_Nr_Drona()=nr_dr;
    break;
  case 'u':
    Sc.WyczyscSciezke();
    Lacze.Rysuj();
  case 'm':  /* wyświetlenie menu */
    WyswietlMenu();
  case 'k':  /* zakończenie programu */
    break;
  default:   /* nierozpoznana opcja */
    cout << " Nieznana opcja. Wybierz jeszcze raz." << endl;
    cin.clear();
    cin.ignore( 1000, '\n' );
  }
}

/*!
 * \brief Wyświetla drona i pyta użytkownika o kolejne opcje do wywołania, 
 *        zapisuje punkty drona i dla zapisanych wywołuje program gnuplot.
 *
 * Wyświetla drona i pyta użytkownika o kolejne opcje do wywołania, 
 * zapisuje punkty drona i dla zapisanych wywołuje program gnuplot.
 * \param[in] Lacze - referencja do klasy łączącej program z gnuplotem,
 * \param[in] Sc - referencja do obiektu reprezentującego scenę,
 *
 * \pre Parametr Lacze musi się odwoływać do odpowiedniej zmiennej.
 * \pre Parametr Sc musi się odwoływać do odpowiedniej zmiennej.
 * \post brak
 *
 * \retval true - gdy nastąpił błąd zapisu współrzędnych prostopadłościanu do pliku,
 * \retval false - w przeciwnym wypadku.
 */
bool ObslugaUzytkownika(PzG::LaczeDoGNUPlota &Lacze, Scena &Sc)
{
  char                  wybor='s';
  int                   nr_dr=0,ilosc_dronow=ILOSC_DRONOW, nr_pr=0,ilosc_przeszkod=ILOSC_PRZESZKODPR;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

  Sc.WyswietlIloscObiektow(); 
  Sc.WyswietlAktualnegoDrona();
  WyswietlMenu();
  while(wybor!='k')
    {
      cout << endl << " Twoj wybor (m - wyswietl menu)> ";
      cin >> wybor;
      WyborOpcji(Lacze, Sc, wybor,nr_dr,ilosc_dronow, nr_pr,ilosc_przeszkod);

      if(wybor=='o'||wybor=='j'||wybor=='s'||wybor=='D'||wybor=='P'||wybor=='U'||wybor=='R'){ 
        cout << endl;
        Sc.WyswietlIloscObiektow();
       // Sc.WyswietlAktualnegoDrona();
      }
      if(wybor=='D'||wybor=='P'||wybor=='U'||wybor=='R'){ 
        Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
      }
    }
  cout << endl << " Koniec dzialania programu." << endl << endl;
  return false;
}

/*!
 * \file main.cpp
 * \brief Moduł główny
 */

/*!
 * \brief Funkcja główna.
 *
 * Funkcja główna.
 * \pre brak
 * \post brak
 *
 * \retval true - gdy program został przerwany,
 * \retval false - gdy program zakończył się poprawnie.
 */
int main()
{
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata
  Scena                 Sc(Lacze);  // To tylko przykladowe definicje zmiennej

  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(-190, 250);
  Lacze.UstawZakresY(-160, 250);
  Lacze.UstawZakresZ(-120, 200);

  Lacze.UstawRotacjeXZ(64,65); // Tutaj ustawiany jest widok

  return ObslugaUzytkownika(Lacze, Sc);
}

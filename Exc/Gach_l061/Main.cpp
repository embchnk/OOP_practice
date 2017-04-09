// Nazwa pliku wykonywalnego: Statki

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// UWAGA!!!
// Kazda z linii znajdujaca sie w blokach BLAD powinna powodowac blad
// kompilacji. Za kazda linie, ktora niepowoduje bledu kompilacji
// ocena za zadanie jest zmniejszana o 1 punkt.

// Prosze dopisac klasy potrzebne do poprawnego dzialania programu

// Klasy Kliper, LodzPodwodna, Motorowka i Szkuner sa czesciowo
// zaimplementowane. W ich kodzie mozna wszystko zmieniac. Jezeli
// bedzie Panstwu to mozna napisac caly kod tych klas od poczatku
// samodzielnie. Nie trzeba korzystac z przygotwanych fragmentow.

// W zadaniu mozna korzystac z elementow bilbioteki standardowej
// zwlaszcza klasy std::string, ktora jest dostepna w pliku o nazwie
// "string".

// Pliku Main.cpp nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie RuchomeObrazki. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// wgrac do UPEL w postaci archiwum spakowanego tarem przy uzyciu polecenia:
// tar czf lab6.tar.gz *

#include<iostream>
#include<string>

#include"Main.h"

// #define BLAD_PIERWSZY
// #define BLAD_DRUGI
// #define BLAD_TRZECI
int main ()
{
	LodzPodwodna u96;
	u96.UstawNazwe ("U-96");
	u96.UstawWypornosc (145);
	u96.UstawPoziomOleju (0.98);
	u96.UstawMaksymalneZanurzenie (453);

	Motorowka malaMotorowka;
	malaMotorowka.UstawNazwe ("mala motorowka");
	malaMotorowka.UstawWypornosc (32);
	malaMotorowka.UstawPoziomOleju (0.64);
	malaMotorowka.UstawIloscPasazerow (5);
	
	Szkuner iAmAlone;
	iAmAlone.UstawNazwe ("I'm alone");
	iAmAlone.UstawWypornosc (213);
	iAmAlone.ZagleStaw ();

	Kliper cuttySark;
	cuttySark.UstawNazwe ("Cutty Sark");
	cuttySark.UstawWypornosc (198);
	cuttySark.ZaglePrecz ();

	Jacht darNatury;
	darNatury.UstawNazwe ("Dar Natury");
	darNatury.UstawWypornosc (67);
	darNatury.UstawPoziomOleju (0.34);
	darNatury.ZagleStaw();
#ifdef BLAD_PIERWSZY
	darNatury.UstawIloscPasazerow (5);
	darNatury.UstawMaksymalneZanurzenie (453);
#endif

	Zaglowiec* zaglowce [] = {&iAmAlone, &cuttySark, &darNatury};

#ifdef BLAD_DRUGI
	Zaglowiec* nieZaglowiec = &u96;
#endif

	StatekSilnikowy* silnikowe [] = {&u96, &malaMotorowka, &darNatury};
#ifdef BLAD_TRZECI
	StatekSilnikowy* nieSilnikowy = &cuttySark;
#endif


	const Statek* statki [] = {zaglowce[0], zaglowce[1], zaglowce[2], silnikowe[0], silnikowe[1]};

	std::cout<<"===== SILNIKOWE =====\n";
	for (unsigned int indeks = 0; indeks < sizeof(silnikowe)/sizeof(StatekSilnikowy*); indeks++)
	  silnikowe[indeks]->WypiszPoziomOleju();

	std::cout<<"\n";
	std::cout<<"===== ZAGLOWCE =====\n";
	for (unsigned int indeks = 0; indeks < sizeof(zaglowce)/sizeof(Zaglowiec*); indeks++)
		zaglowce[indeks]->WypiszStanZagli();

	std::cout<<"\n";
	std::cout<<"===== STATKI =====\n";
	for (unsigned int indeks = 0; indeks < sizeof(statki)/sizeof(Statek*); indeks++) {
	  statki[indeks]->WypiszInformacje();
	  std::cout<<"\n";
	}

  return 0;
}
/*
===== SILNIKOWE =====
Poziom oleju wynosi 0.98.
Poziom oleju wynosi 0.64.
Poziom oleju wynosi 0.34.

===== ZAGLOWCE =====
Zagle sa postawione.
Zagle sa zlozone.
Zagle sa postawione.

===== STATKI =====
nazwa: I'm alone
wypornosc: 213
zagle: postawione

nazwa: Cutty Sark
wypornosc: 198
zagle: zlozone

nazwa: Dar Natury
wypornosc: 67
zagle: postawione
olej: 0.34

nazwa: U-96
wypornosc: 145
olej: 0.98
zanurzenie: 453

nazwa: mala motorowka
wypornosc: 32
olej: 0.64
pasazerowie: 5

*/

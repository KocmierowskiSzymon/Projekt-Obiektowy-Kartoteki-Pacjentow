#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <conio.h>
#include <vector>
#include <stdlib.h>
#include "Pozegnanie.h"

using namespace std;

int wyb, wyb2, zmienna, licz, pomoc, wyb3, LK, LM;
char pytanie;
string login, haslo, loginek, imi, naz, spe;
fstream plik1, plik2, plik3;
char bufor[500];
vector <Pozegnanie> notka;

typedef struct wizyta
{
	struct wizyta *nast;
	struct wizyta *poprzedni;
	Wizyta obie_klasy;
}wizyta;

typedef struct lekarz
{
	struct lekarz *nast;
	struct lekarz *poprzedni;
	Lekarz obie_klasy;
}lekarz;

typedef struct pacjent
{
	struct pacjent *nast;
	struct pacjent *poprzedni;
	Pacjent obie_klasy;
}pacjent;

wizyta *glowa_wizyta = NULL;
wizyta *ogan_wizyta = NULL;
wizyta *wizyt = NULL;

lekarz *glowa_lekarz = NULL;
lekarz *ogon_lekarz = NULL;
lekarz *lekorz = NULL;

pacjent *glowa_pacjent = NULL;
pacjent *ogon_pacjent = NULL;
pacjent *pacjunt = NULL;

void wizyta_dodaj()
{
	wizyta *nowy = new wizyta;
	if (glowa_wizyta == NULL)
	{
		nowy->poprzedni = NULL;
		nowy->nast = NULL;
		glowa_wizyta = nowy;
		ogan_wizyta = nowy;
	}
	else
	{
		wizyt = ogan_wizyta;
		ogan_wizyta->nast = nowy;
		ogan_wizyta = nowy;
		nowy->nast = NULL;
		nowy->poprzedni = wizyt;
	}
	wizyt = nowy;
}

void wizyta_wyswietl()
{
	if (glowa_wizyta == NULL)
	{
		cout << "Nie bylo jeszcze zadnych wizyt!\n";
	}
	else
	{
		cout << "Lista wizyt:\n\n";
		wizyt = glowa_wizyta;
		for (int i = 1; i != 0; i++)
		{

			if (wizyt == NULL)
			{
				break;
			}
			else
			{
				cout << i << ")" << endl;
				wizyt->obie_klasy.wyswietl();
				wizyt = wizyt->nast;
			}
		}
	}
}

void wizyta_zapisz()
{
	if (glowa_wizyta == NULL)
	{
		remove("wizyty.txt");
	}
	else
	{
		wizyt = glowa_wizyta;
		for (int i = 1; i != 0; i++)
		{
			if (wizyt == NULL)
			{
				break;
			}
			else
			{
				plik3 << wizyt->obie_klasy.dzien << endl;
				plik3 << wizyt->obie_klasy.miesiac << endl;
				plik3 << wizyt->obie_klasy.rok << endl;
				plik3 << wizyt->obie_klasy.waga << endl;
				plik3 << wizyt->obie_klasy.wzrost << endl;
				plik3 << wizyt->obie_klasy.BMI << endl;
				plik3 << wizyt->obie_klasy.login << endl;
				for (int i = 0; i < 500; i++)
				{
					if (wizyt->obie_klasy.diagnoza[i] == 32)
					{
						wizyt->obie_klasy.diagnoza[i] = 96;
					}
				}
				plik3 << wizyt->obie_klasy.diagnoza << endl;
				for (int i = 0; i < 500; i++)
				{
					if (wizyt->obie_klasy.zalecenia[i] == 32)
					{
						wizyt->obie_klasy.zalecenia[i] = 96;
					}
				}
				plik3 << wizyt->obie_klasy.zalecenia << endl;
				wizyt = wizyt->nast;
			}
		}
	}
}

void wizyta_usun()
{
	if (glowa_wizyta == NULL)
	{
		cout << "Nie ma jeszcze zdefiniowanych wizyt!\n";
	}
	else
	{
		wizyta_wyswietl();

		cout << "Ktory numer z listy chcesz usunac?:\n";
		cout << "Wybrany numer: ";
		int zmienna;
		cin >> zmienna;
		cout << "Wybrano numer: " << zmienna << endl;
		cout << "Uwaga. Usuniecie wizyty spodowuje utracenie informacji na stale. Jestes pewien?(T lub N)" << endl;
		cin >> pytanie;
		if (pytanie == 'T' || pytanie == 't')
		{
			wizyt = glowa_wizyta;
			for (int i = 1; i < zmienna; i++)
			{
				wizyt = wizyt->nast;
			}
			if (wizyt == glowa_wizyta)
			{
				glowa_wizyta = glowa_wizyta->nast;
				if (glowa_wizyta != NULL)
					glowa_wizyta->poprzedni = NULL;

			}
			else if (wizyt == ogan_wizyta)
			{
				ogan_wizyta = ogan_wizyta->poprzedni;
			}
			else
			{
				wizyt->poprzedni->nast = wizyt->nast;
				wizyt->nast->poprzedni = wizyt->poprzedni;

			}
		}
		else if (pytanie == 'N' || pytanie == 'n')
		{
		}
		else
		{
		}
	}
}

void wizyta_pacjent_wyswietl(string loginek)
{
	if (glowa_wizyta == NULL)
	{
		cout << "Nie bylo jeszcze zadnych wizyt!\n";
	}
	else
	{
		wizyt = glowa_wizyta;
		for (int j=1;;)
		{

			if (wizyt == NULL)
			{
				if (j == 1)cout << "\nNie ma odbytych zadnych wizyt.\n";
				break;
			}
			else
			{
				if (loginek == wizyt->obie_klasy.login)
				{
					cout << j << ". ";
					wizyt->obie_klasy.wyswietl();
					cout << endl;
					j++;
				}
				wizyt = wizyt->nast;
			}
		}
	}
}

void lekarz_dodaj()
{
	lekarz *nowy = new lekarz;
	if (glowa_lekarz == NULL)
	{
		nowy->poprzedni = NULL;
		nowy->nast = NULL;
		glowa_lekarz = nowy;
		ogon_lekarz = nowy;
	}
	else
	{
		lekorz = ogon_lekarz;
		ogon_lekarz->nast = nowy;
		ogon_lekarz = nowy;
		nowy->nast = NULL;
		nowy->poprzedni = lekorz;
	}
	lekorz = nowy;
}

void lekarz_wyswietl()
{
	cout << "Lista Lekarzy:\n\n";
	lekorz = glowa_lekarz;
	for (int i = 1; i != 0; i++)
	{

		if (lekorz == NULL)
		{
			break;
		}
		else
		{
			cout << i << ". ";
			lekorz->obie_klasy.wyswietl();
			lekorz = lekorz->nast;
		}
	}
}

void lekarz_zapisz()
{
	if (glowa_lekarz != NULL)
	{
		lekorz = glowa_lekarz;
		for (int i = 1; i != 0; i++)
		{

			if (lekorz == NULL)
			{
				break;
			}
			else
			{
				plik2 << lekorz->obie_klasy.imie << endl;
				plik2 << lekorz->obie_klasy.nazwisko << endl;
				plik2 << lekorz->obie_klasy.stopien << endl;
				plik2 << lekorz->obie_klasy.specjalizacja << endl;
				lekorz = lekorz->nast;
			}
		}
	}
	else
	{
		remove("lekarze.txt");
	}
}

void usun()
{
	lekorz = glowa_lekarz;
	for (int i = 1; i < licz; i++)
	{
		lekorz = lekorz->nast;
	}
	if (lekorz == glowa_lekarz)
	{
		glowa_lekarz = glowa_lekarz->nast;
		if (glowa_lekarz != NULL)
		{
			glowa_lekarz->poprzedni = NULL;
		}
	}
	else if (lekorz == ogon_lekarz)
	{
		ogon_lekarz = ogon_lekarz->poprzedni;
	}
	else
	{
		lekorz->poprzedni->nast = lekorz->nast;
		lekorz->nast->poprzedni = lekorz->poprzedni;
	}
}

void pacjent_dodaj()
{
	pacjent *nowy = new pacjent;
	if (glowa_pacjent == NULL)
	{
		nowy->poprzedni = NULL;
		nowy->nast = NULL;
		glowa_pacjent = nowy;
		ogon_pacjent = nowy;
	}
	else
	{
		pacjunt = ogon_pacjent;
		ogon_pacjent->nast = nowy;
		ogon_pacjent = nowy;
		ogon_pacjent->nast = NULL;
		nowy->poprzedni = pacjunt;
	}
	pacjunt = nowy;
}

void pacjent_wyswietl()
{
	cout << "Lista Pacjentow:\n\n";
	pacjunt = glowa_pacjent;
	for (int i = 1; i != 0; i++)
	{
		if (pacjunt == NULL)
		{
			break;
		}
		else
		{
			cout << i << ". ";
			pacjunt->obie_klasy.wyswietl();
			pacjunt = pacjunt->nast;
		}
	}
}

void pacjent_zapisz()
{
	if (glowa_pacjent != NULL)
	{
		pacjunt = glowa_pacjent;
		for (int i = 1; i != 0; i++)
		{
			if (pacjunt == NULL)
			{
				break;
			}
			else
			{
				plik1 << pacjunt->obie_klasy.imie << endl;
				plik1 << pacjunt->obie_klasy.nazwisko << endl;
				plik1 << pacjunt->obie_klasy.plec << endl;
				plik1 << pacjunt->obie_klasy.pesel << endl;
				plik1 << pacjunt->obie_klasy.login << endl;
				plik1 << pacjunt->obie_klasy.haslo << endl;
				pacjunt = pacjunt->nast;
			}
		}
	}
	else
	{
		remove("pacjenci.txt");
	}
}

void usun(int zmienna)
{
	pacjunt = glowa_pacjent;
	for (int i = 1; i < zmienna; i++)
	{
		pacjunt = pacjunt->nast;
	}
	if (pacjunt == glowa_pacjent)
	{
		glowa_pacjent = glowa_pacjent->nast;
		if (glowa_pacjent != NULL)
			glowa_pacjent->poprzedni = NULL;

	}

	else if (pacjunt == ogon_pacjent)
	{
		ogon_pacjent = ogon_pacjent->poprzedni;
	}
	else
	{
		pacjunt->poprzedni->nast = pacjunt->nast;
		pacjunt->nast->poprzedni = pacjunt->poprzedni;
	}
}

void wizyty()
{
	int menu = 100, wyjscie = 1;
	while (wyjscie)
	{
		cout << "Menu do zarzadzania wizytami" << endl;
		cout << "Wybierz operacje." << endl;
		cout << "1.Dodaj wizyte" << endl;
		cout << "2.Usun" << endl;
		cout << "3.Wyswietl" << endl;
		cout << "4.Edytuj" << endl;
		cout << "0.Powrot do Menu Glownego" << endl;
		cout << "Wybrana operacja: ";
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case 1:
		{
			if (glowa_pacjent == NULL)
			{
				cout << "Nie ma jeszcze zdefiniowanych pacjentow!\n\n";
				break;
			}
			pacjent_wyswietl();
			wizyta:
			cout << endl << "Podaj login pacjenta ktory odbyl wizyte:";
			cin >> loginek;
			pacjunt = glowa_pacjent;
			for (;;)
			{
				if (loginek == pacjunt->obie_klasy.login)break;
				pacjunt = pacjunt->nast;
				if (pacjunt == NULL)
				{
					cout << endl << "Nie ma pacjenta o takim loginie w bazie systemu!!!" << endl;
					system("pause");
					goto wizyta;
					break;
				}
			}
			wizyta_dodaj();
			wizyt->obie_klasy.wypelnij();
			wizyt->obie_klasy.login = loginek;
			break;
		}
		case 2:
		{
			wizyta_usun();
			break;
		}
		case 3:
		{
			wizyta_wyswietl();
			system("pause");
			break;
		}
		case 4:
		{
			if (glowa_wizyta == NULL)
			{
				cout << "Nie ma jeszcze zdefiniowanych wizyt!\n";
				break;
			}
			wizyta_wyswietl();
			cout << "Ktory numer z listy chcesz edytowac?:\n\n";
			cin >> zmienna;
			wizyt = glowa_wizyta;
			for (int i = 1; i < zmienna; i++)
			{
				wizyt = wizyt->nast;
			}
			wizyt->obie_klasy.edytuj();
			break;
		}
		case 0:
		{
			wyjscie = 0;
			break;
		}
		default:
		{
			cout << "Zla wartosc.\nSprobuj ponownie...\n" << endl;
			system("pause");
			break;
		}
		}
	}
}

void lekarze()
{
	int menu = 100, wyjscie = 1;
	while (wyjscie) 
	{
		cout << "Menu do zarzadzania Lekarzami*\n\n\nWybierz porzadana opcje...\n" << endl;
		cout << "1.Dodaj lekarza" << endl;
		cout << "2.Usun lekarza" << endl;
		cout << "3.Wyswietl lekarzy" << endl;
		cout << "4.Edytuj lekarza" << endl;
		cout << "0.Powrot do Menu Glownego" << endl;
		cout << "Wybrana opcja: ";
		cin >> menu;
		cout << endl;
		system("cls");
		switch (menu)
		{

		case 1:
			lekarz_dodaj();
			lekorz->obie_klasy.wypelnij();
			break;

		case 2:
			if (glowa_lekarz == NULL)
			{
				cout << "Nie ma jeszcze zdefiniowanych lekarzy!\n\n";
				break;
			}
			lekarz_wyswietl();

			cout << "Ktory numer z listy chcesz usunac?:\n0=ANULUJ\n\n";
			cin >> licz;
			if (licz == 0)break;
			cout << "UWAGA!!!\nUsuniecie lekarza spodowuje utracenie informacji na stale\nJestes pewien?(Y/N)\n\n";
			cin >> pytanie;
			if (pytanie == 'Y')
			usun();

			break;

		case 3:
		{
			if (glowa_lekarz == NULL)
			{
				cout << "Nie ma jeszcze zdefiniowanych lekarzy!\n\n";
				break;
			}
			lekarz_wyswietl();
			system("pause");
			break;
		}
		case 4:
		{
			if (glowa_lekarz == NULL)
			{
				cout << "Nie ma jeszcze zdefiniowanych lekarzy!\n\n";
				break;
			}
			cout << "Ktory numer z listy chcesz edytowac?:\n0=ANULUJ\n\n";
			cin >> zmienna;
			if (zmienna == 0)break;
			lekorz = glowa_lekarz;
			for (int i = 1; i < zmienna; i++)
			{
				lekorz = lekorz->nast;
			}
			lekorz->obie_klasy.edytuj();
			break;
		}
		case 0:
		{
			wyjscie = 0;
			break;
		}
		default:
		{
			cout << "Zla wartosc." << endl;
			cout << "Sprobuj ponownie." << endl;
			system("pause");
			break;
		}
		}
	}

}

void zlicz_plec()
{
	LK = 0;
	LM = 0;
	pacjunt = glowa_pacjent;
	while (pacjunt != NULL)
	{
		if (pacjunt->obie_klasy.plec == 'K')
		{
			LK++;
		}
		else
		{
			LM++;
		}
		pacjunt = pacjunt->nast;
	}
}

void pacjenci()
{
	int menu = 100, wyjscie = 1;
	while (wyjscie) 
	{
		system("cls");
		cout << "Menu do zarzadzania Pacjentami\nWybierz operacje.\n" << endl;
		cout << "1.Dodaj" << endl;
		cout << "2.Usun" << endl;
		cout << "3.Wyswietl" << endl;
		cout << "4.Edytuj" << endl;
		cout << "5.Wypisz liczbe zarejestrowanych kobiet i mezczyzn" << endl;
		cout << "0.Powrot do Menu Glownego" << endl;
		cout << endl << "Wybrana opcja: ";
		cin >> menu;
		cout << endl;
		system("cls");
		switch (menu)
		{
		case 1:
		{
			pacjent_dodaj();
			pacjunt->obie_klasy.wypelnij();
			break;
		}
		case 2:
		{
			if (glowa_pacjent == NULL)
			{
				cout << "Nie ma jeszcze zdefiniowanych pacjentow!\n\n";
				break;
			}
			pacjent_wyswietl();
			cout << "Ktory numer z listy chcesz usunac?:\n\n";
			cin >> zmienna;
			k:
			cout << "UWAGA!!!\nUsuniecie lekarza spodowuje utracenie informacji na stale\nJestes pewien?(T lub N)\n\n";
			cin >> pytanie;
			if (pytanie == 'T' || pytanie == 't')
			{
				usun(zmienna);
			}
			else if (pytanie == 'N' || pytanie == 'n')
			{
			}
			else
			{
				cout << "Wprowadzono zla wartosc." << endl;
				cout << "Wprowadz wartosc raz jeszcze." << endl;
				goto k;
			}
			break;
		}
		case 3:
		{
			if (glowa_pacjent == NULL)
			{
				cout << "Nie ma jeszcze zdefiniowanych pacjentow!\n\n";
				break;
			}
			pacjent_wyswietl();
			system("pause");
			break;
		}
		case 4:
		{
			if (glowa_pacjent == NULL)
			{
				cout << "Nie ma jeszcze zdefiniowanych pacjentow!\n\n";
				break;
			}
			pacjent_wyswietl();
			cout << "Ktory numer z listy chcesz edytowac?:\n\n";
			int zmienna;
			cin >> zmienna;
			pacjunt = glowa_pacjent;
			for (int i = 1; i < zmienna; i++)
			{
				pacjunt = pacjunt->nast;
			}
			pacjunt->obie_klasy.edytuj();
			break;
		}
		case 5:
		{
			zlicz_plec();
			cout << "Liczba zarejestrowanych kobiet wynosi: " << LK << endl;
			cout << endl;
			cout << "Liczba zarejestrowanych mezczyzn wynosi: " << LM << endl;
			cout << endl;
			system("pause");
			break;
		}
		case 0:
		{
			wyjscie = 0;
			break;
		}
		default:
		{
			cout << "Zla wartosc.\nSprobuj ponownie.\n" << endl;
			system("pause");
			break;
		}
		}
	}
}

int logowanie()
{
	log:
	int dec;
	system("cls");
	cout << "Witamy w programie szpitalnym." << endl;
	cout << "Prosze wybrac jedna z opcji." << endl;
	cout << "1. Zaloguj sie" << endl;
	cout << "2. Zapomnialem hasla" << endl;
	cout << "0. Wyjdz z programu" << endl;
	cout << "Wybrana opcja: ";
	cin >> dec;
	system("cls");
	switch (dec)
	{
	case 1:
	{
	jeszcze:
		cout << "Witam" << endl << "Login:";
		cin >> login;
		cout << "Haslo:";
		cin >> haslo;
		if (login == "Admin")
		{
			while (haslo != "admin123")
			{
				cout << "Bledne haslo sproboj ponownie.\n";
				goto jeszcze;
			}
			return 1;
			}
		else
		{
			pacjunt = glowa_pacjent;
			if (pacjunt == NULL)
			{
				cout << "Twoja lista pacjentow jest pusta. Prosze zalogowac sie na administratora, aby zarejestrowac pacjentow." << endl;
				system("pause");
				goto log;
			}
			for (;;)
			{
				if (pacjunt->obie_klasy.login == login)break;
				pacjunt = pacjunt->nast;
				if (pacjunt == NULL)
				{
					cout << "\nNie ma takiego loginu.\n";
					return 3;
				}
			}

			while (haslo != pacjunt->obie_klasy.haslo)
			{
				cout << "Bledne haslo sproboj ponownie.\n";
				goto jeszcze;
			}

			return 2;		}
	}
	case 2:
	{
		return 4;
	}
	case 0:
	{
		return 0;
	}
	default:
	{
		cout << "Nie wybrano zadnej operacji. Sprobuj jeszcze raz." << endl;
		system("pause");
		goto log;
	}
	}

}

void zapisywanie_danych()
{
	remove ("pacjenci.txt");
	remove ("lekarze.txt");
	remove ("wizyty.txt");

	plik1.open("pacjenci.txt", std::ios::app);
	plik2.open("lekarze.txt", std::ios::app);
	plik3.open("wizyty.txt", std::ios::app);

	pacjent_zapisz();
	lekarz_zapisz();
	wizyta_zapisz();

	plik1.close();
	cout << "Plik pacjenci.txt zostal utworzony pomyslnie. Znajduja sie w nim wszyscy zarejestrowani pacjenci." << endl;
	plik2.close();
	cout << "Plik lekarze.txt zostal utworzony pomyslnie. Znajduja sie w nim wszyscy zarejestrowani lekarze." << endl;
	plik3.close();
	cout << "Plik wizyty.txt zostal utworzony pomyslnie. Znajduja sie w nim wszyscy zarejestrowane wizyty." << endl;
}

void wczytywanie_danych()
{
	string s1, s2, s3, s4, s5;
	int i1, i2, i3;
	float f1, f2, f3;
	char c1[500], c2[500], c3;
	plik1.open("pacjenci.txt", std::ios::in);
	if (!plik1.good())
	{
		cout << "Nie posiadasz zadnego zapisu stanu pacjentow z ostatniej sesji." << endl;
		system("pause");
	}
	else
	{
		while (!plik1.eof())
		{
			plik1 >> s1 >> s2 >> c3 >> s3 >> s4 >> s5;
			pacjent_dodaj();
			pacjunt->obie_klasy.imie = s1;
			pacjunt->obie_klasy.nazwisko = s2;
			pacjunt->obie_klasy.plec = c3;
			pacjunt->obie_klasy.pesel = s3;
			pacjunt->obie_klasy.login = s4;
			pacjunt->obie_klasy.haslo = s5;
		}
		ogon_pacjent = pacjunt->poprzedni;
		pacjunt->poprzedni->nast = NULL;
		delete pacjunt;
		plik1.close();
		cout << "Pomyslnie zaladowano plik pacjenci.txt." << endl;
		system("pause");
	}
	plik2.open("lekarze.txt", std::ios::in);
	if (!plik2.good())
	{
		cout << "Nie posiadasz zadnego zapisu stanu lekarzy z ostatniej sesji." << endl;
		system("pause");
	}
	else
	{
		while (!plik2.eof())
		{
			plik2 >> s1 >> s2 >> s3 >> s4;
			lekarz_dodaj();
			lekorz->obie_klasy.imie = s1;
			lekorz->obie_klasy.nazwisko = s2;
			lekorz->obie_klasy.stopien = s3;
			lekorz->obie_klasy.specjalizacja = s4;
		}
		ogon_lekarz = lekorz->poprzedni;
		lekorz->poprzedni->nast = NULL;
		delete lekorz;
		plik2.close();
		cout << "Pomyslnie zaladowano plik lekarze.txt." << endl;
		system("pause");
	}
	plik3.open("wizyty.txt", std::ios::in);
	if (!plik3.good())
	{
		cout << "Nie posiadasz zadnego zapisu stanu wizyt z ostatniej sesji." << endl;
		system("pause");
	}
	else
	{
		while (!plik3.eof())
		{
			plik3 >> i1 >> i2 >> i3 >> f1 >> f2 >> f3 >> s1 >> c1 >> c2;

			wizyta_dodaj();
			wizyt->obie_klasy.dzien = i1;
			wizyt->obie_klasy.miesiac = i2;
			wizyt->obie_klasy.rok = i3;
			wizyt->obie_klasy.waga = f1;
			wizyt->obie_klasy.wzrost = f2;
			wizyt->obie_klasy.BMI = f3;
			wizyt->obie_klasy.login = s1;
			for (int i = 0; i < 500; i++)
			{
				wizyt->obie_klasy.diagnoza[i] = c1[i];
				if (wizyt->obie_klasy.diagnoza[i] == 96)
				{
					wizyt->obie_klasy.diagnoza[i] = 32;
				}
			}
			for (int i = 0; i < 500; i++)
			{
				wizyt->obie_klasy.zalecenia[i] = c2[i];
				if (wizyt->obie_klasy.zalecenia[i] == 96)
				{
					wizyt->obie_klasy.zalecenia[i] = 32;
				}
			}
		}
		ogan_wizyta = wizyt->poprzedni;
		wizyt->poprzedni->nast = NULL;
		delete wizyt;
		plik3.close();
		cout << "Pomyslnie zaladowano plik wizyty.txt." << endl;
		system("pause");
	}
	cout << endl;
}

int main()
{
	int menu = 100, wyjscie = 1;
	char taknie;
	l:
	cout << "Zaladowac dane z ostatniej sesji? (T lub N)" << endl;
	cin >> taknie;
	if (taknie == 'T' || taknie =='t')
	{
		wczytywanie_danych();
	}
	else if (taknie == 'N' || taknie == 'n')
	{
	}
	else
	{
		cout << "Podano zla wartosc." << endl;
		cout << "Wprowadz wartosc raz jeszcze." << endl;
		goto l;
	}
	system("cls");
	while (wyjscie)
	{
		system("cls");
		switch (logowanie())
		{
		case 1:
		{
			int wyjscie2 = 1;
			cout << "Witamy w programie zarzadzania kartotekami szpitalnymi." << endl;
			cout << "Jestes zalogowany jako:" << login << endl;
			cout << endl;
			while (wyjscie2)
			{
				cout << "Menu" << endl;
				cout << "Prosze wybrac opcje." << endl;
				cout << "1.Zarzadzaj Wizytami" << endl;
				cout << "2.Zarzadzaj Lekarzami" << endl;
				cout << "3.Zarzadzaj Pacjentami" << endl;
				cout << "0.Wyloguj sie" << endl;
				cout << endl;
				cout << "Wskazana opcja: ";
				cin >> menu;
				system("cls");
				switch (menu)
				{
				case 1:
				{
					wizyty();
					break;
				}
				case 2:
				{
					lekarze();
					break;
				}
				case 3:
				{
					pacjenci();
					break;
				}
				case 0:
				{
					wyjscie2 = 0;
					break;
				}
				default:
				{
					cout << "Zla wartosc." << endl;
					cout << "Sprobuj ponownie." << endl;
					system("pause");
					break;
				}
				}
			}
			break;
		}
		case 2:
		{
			menu:
			cout << "Witam w przegladzie kartoteki pacjenta." << endl;
			cout << "Jestes zalogowany jako: " << login << endl;
			cout << "Status: Pacjent" << endl;
			cout << endl;
			cout << "1.Podglad historii wizyt." << endl;
			cout << "0.Wyloguj sie" << endl;
			cin >> wyb3;
			system("cls");
			switch (wyb3)
			{
			case 1:
			{
				wizyta_pacjent_wyswietl(login);
				goto menu;
				break;
			}
			case 0:
			{
				break;
			}
			default:
			{
				cout << "Zla wartosc." << endl;
				cout<<"Sprobuj ponownie." << endl;
				system("pause");
				goto menu;
				break;
			}
			break;
			}
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			cout << "Prosze zglosic sie do administracji o powtorne nadanie hasla" << endl;
			system("pause");
			break;
		}
		case 0:
		{
			zapisywanie_danych();
			Pozegnanie nara;
			notka.push_back(nara);
			notka[0].napisz();
			system("pause");
			cout << []()->int {return 0; }() << endl;
			return 0;
		}
		default:
		{
			cout << "Nie wybrano operacji." << endl;
			cout << "Prosze sprobowac ponownie." << endl;
			break;
		}
		}
	}
}

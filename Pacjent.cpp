#include "stdafx.h"
#include "Pacjent.h"

using namespace std;

Pacjent::Pacjent()
{
}

Pacjent::~Pacjent()
{
}

void Pacjent::wypelnij()
{
	cout << endl << "Podaj imie pacjenta: ";
	cin >> imie;
	cout << endl << "Podaj nazwisko pacjenta: ";
	cin >> nazwisko;
	pl:
	cout << endl << "Podaj plec pacjenta: ";
	cin >> plec;
	if (plec != 'M' && plec != 'K')
	{
		cout << "Podano bledna plec pacjenta." << endl;
		cout << "Prosze wprowadzic plec pacjenta ponownie." << endl;
		goto pl;
	}
	pes:
	cout << endl << "Podaj pesel pacjenta: ";
	cin >> pesel;
	if (pesel.length() != 11)
	{
		cout << "Wprowadzono bledna wartosc pesel. Wprowadz wartosc jeszcze raz." << endl;
		goto pes;
	}
	cout << endl << "Podaj login pacjenta: ";
	cin >> login;
	cout << endl << "Podaj haslo pacjenta: ";
	cin >> haslo;
}

void Pacjent::wyswietl()
{
	cout << endl << "Imie i nazawisko: " << imie << " " << nazwisko << endl;
	if (plec == 'M')
	{
		cout << "Plec: Mezczyzna" << endl;
	}
	else
	{
		cout << "Plec: Kobieta" << endl;
	}
	cout << "Pesel: " << pesel << endl;
	cout << "Login: " << login << endl;
	cout << "Haslo: " << haslo << endl;
}

void Pacjent::edytuj()
{
	cout << "Stare dane:" << endl;
	this->wyswietl();

	int menu = 100, wyjscie = 1;
	while (wyjscie) {
		cout << "Co chcesz edytowac?\n1.Imie\n2.Nazwisko\n3.Pesel\n4.Haslo\n0.KONIEC EDYCJI\n" << endl;

		cin >> menu;
		system("cls");
		switch (menu)
		{

		case 1:
			cout << endl << "Prosze podac imie pacjenta: ";
			cin >> imie;
			cout << endl;
			this->wyswietl();
			break;

		case 2:
			cout << endl << "Prosze podac nazwisko pacjenta: ";
			cin >> nazwisko;
			cout << endl;
			this->wyswietl();
			break;

		case 3:
			pes1:
			cout << endl << "Prosze podac pesel pacjenta: ";
			cin >> pesel;
			cout << endl;
			if (pesel.length() != 11)
			{
				cout << "Wprowadzono bledna wartosc pesel. Wprowadz wartosc jeszcze raz." << endl;
				goto pes1;
			}
			this->wyswietl();
			break;

		case 4:
			cout << endl << "Prosze podac nowe haslo pacjenta: ";
			cin >> haslo;
			cout << endl;
			this->wyswietl();
			break;

		case 0:
			wyjscie = 0;
			break;

		default:
			cout << "Zla wartosc.\nSprobuj ponownie...\n" << endl;
			system("pause");
			break;
		}
	}
}
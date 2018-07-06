#include "stdafx.h"
#include "Lekarz.h"

using namespace std;

Lekarz::Lekarz()
{
}

Lekarz::~Lekarz()
{
}

void Lekarz::wypelnij()
{
	cout << endl << "Podaj imie:";
	cin >> imie;
	cout << endl << "Podaj nazwisko:";
	cin >> nazwisko;
	cout << endl << "Podaj stopien naukowy:";
	cin >> stopien;
	cout << endl << "Podaj specjalizacje:";
	cin >> specjalizacja;
}

void Lekarz::wyswietl()
{
	cout << stopien << " " << imie << " " << nazwisko << " Specjalizacja:" << specjalizacja<<endl;
}

void Lekarz::edytuj()
{
	cout << "Stare dane:" << endl;
	this->wyswietl();

	int menu = 100, wyjscie = 1;
	while (wyjscie) {
		cout << "\nCo chcesz edytowac?\n1.Imie\n2.Nazwisko\n3.Stopien\n4.Specjalizacja\n0.KONIEC EDYCJI\n" << endl;

		cin >> menu;
		system("cls");
		switch (menu)
		{

		case 1:
			cout << endl << "Prosze podac nowe imie: ";
			cin >> imie;
			cout << endl;
			this->wyswietl();
			break;

		case 2:
			cout << endl << "Prosze podac nowe nazwisko: ";
			cin >> nazwisko;
			cout << endl;
			this->wyswietl();
			break;

		case 3:
			cout << endl << "Prosze podac nowy stopien: ";
			cin >> stopien;
			cout << endl;
			this->wyswietl();
			break;

		case 4:
			cout << endl << "Prosze podac nowa specjalizacje: ";
			cin >> specjalizacja;
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

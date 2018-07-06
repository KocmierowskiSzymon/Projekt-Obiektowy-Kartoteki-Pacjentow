#include "stdafx.h"
#include "Wizyta.h"

using namespace std;

Wizyta::Wizyta()
{
}

Wizyta::~Wizyta()
{
}

void Wizyta::wypelnij ()
{
	cout << endl << "Prosze podac dzien wizyty: ";
	cin >> dzien;
	cout << endl << "Prosze podac miesiac wizyty (wartosc od 1 do 12): ";
	cin >> miesiac;
	cout << endl << "Prosze podac rok wizyty: ";
	cin >> rok;
	cout << endl << "Prosze podac wage: ";
	cin >> waga;
	cout << endl << "Prosze podac wzrost: ";
	cin >> wzrost;
	BMI = waga / wzrost;
	cout << endl << "Prodze podac diagnoze lekarza: ";
	cin >> ws;
	cin.getline(diagnoza, 500);
	cout << endl << "Prodze podac zalecenia lekarza: ";
	cin >> ws;
	cin.getline(zalecenia, 500);
}

void Wizyta::wyswietl()
{
	cout << "Wizyta: " << rok << "/" << miesiac << "/" << dzien << endl;
	cout << "BMI: " << BMI << endl;
	cout << "Login: " << login << endl;
	cout << "Zalecenia: " << zalecenia << endl;
}

void Wizyta::edytuj()
{
	cout << "Stare dane:" << endl;
	this->wyswietl();

	int menu = 100, wyjscie = 1;
	while (wyjscie) {
		cout << "Waga:" << waga << endl << "Wzrost" << wzrost << endl;
		cout << "Co chcesz edytowac?\n1.Rok\n2.Miesiac\n3.Dzien\n4.Waga\n5.Wzrost\n0.Zakoncz edycje\n" << endl;

		cin >> menu;
		system("cls");
		switch (menu)
		{

		case 1:
			cout << endl << "Prosze podac rok wizyty: ";
			cin >> rok;
			cout << endl;
			this->wyswietl();
		
			break;

		case 2:
			cout << endl << "Prosze podac miesiac wizyty (wartosc od 1 do 12): ";
			cin >> miesiac;
			cout << endl;
			this->wyswietl();
			break;

		case 3:
			cout << endl << "Prosze podac dzien wizyty: ";
			cin >> dzien;
			cout << endl;
			this->wyswietl();
			break;

		case 4:
			cout << endl << "Prosze podac wage: ";
			cin >> waga;
			cout << endl;
			BMI = waga / wzrost;
			this->wyswietl();
			break;

		case 5:
			cout << endl << "Prosze podac wzrost: ";
			cin >> wzrost;
			cout << endl;
			BMI = waga / wzrost;
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

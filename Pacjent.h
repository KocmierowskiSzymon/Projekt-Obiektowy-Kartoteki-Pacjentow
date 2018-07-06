#pragma once

using namespace std;

class Pacjent
{
public:
	string imie;
	string nazwisko;
	char plec;
	string login;
	string haslo;
	string pesel;
	Pacjent();
	~Pacjent();
	void wypelnij();
	void wyswietl();
	void edytuj();
	friend struct pacjent;
};

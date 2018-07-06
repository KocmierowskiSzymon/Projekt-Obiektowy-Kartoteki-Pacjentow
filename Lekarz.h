#pragma once

using namespace std;

class Lekarz
{
public:
	//nazwa nazw;
	string imie;
	string nazwisko;
	string stopien;
	string specjalizacja;
	Lekarz();
	~Lekarz();
	void wypelnij();
	void wyswietl();
	void edytuj();
	friend struct nazwa;
};


#pragma once
#include "stdafx.h"

using namespace std;

class Wizyta
{
public:
	int rok;
	int dzien;
	int miesiac;
	char diagnoza[500];
	char zalecenia[500];
	string login;
	float wzrost;
	float waga;
	float BMI;

	Wizyta();
	~Wizyta();
	void wypelnij();
	void wyswietl();
	void edytuj();
	friend Pacjent;
	friend struct pacjent;

};


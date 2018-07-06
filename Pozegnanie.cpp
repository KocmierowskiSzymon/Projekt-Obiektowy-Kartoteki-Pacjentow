#include "stdafx.h"
#include "Pozegnanie.h"


Pozegnanie::Pozegnanie()
{
	papatki = "Dowidzenia!";
}


Pozegnanie::~Pozegnanie()
{
}

void Pozegnanie::napisz()
{
	cout << papatki << endl;
}
#pragma once
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include <iostream>
class Regulator
{
protected:
	float settemp;
	Pomieszczenie* room;
	Grzejnik* heater;
	bool sprawdzPowiazania();
public:
	Regulator();
	virtual void steruj(float) = 0;
	void setsettemp();
	void uruchom(float dt);

};


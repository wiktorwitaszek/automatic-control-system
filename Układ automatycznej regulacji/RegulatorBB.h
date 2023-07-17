#pragma once
#include "Regulator.h"
class RegulatorBB : public Regulator
{
public:
	RegulatorBB(Grzejnik* _heater, Pomieszczenie* _room);
	void steruj(float);
	float getSettemp();
};


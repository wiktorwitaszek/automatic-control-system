#pragma once
#include "Regulator.h"
class RegulatorPID : public Regulator
{
	float kp, ki, kd, ec, ep;
public:
	RegulatorPID(Grzejnik* _heater, Pomieszczenie* _room,float kp= 4.0,float ki= 0.02,float kd = 0.1);
	float getSettemp();
	void steruj(float dt);
};


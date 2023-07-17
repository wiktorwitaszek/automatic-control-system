#include "RegulatorPID.h"

RegulatorPID::RegulatorPID(Grzejnik* _heater, Pomieszczenie* _room, float _kp, float _ki, float _kd) : ec(0.0), ep(20) {
	room = _room;
	heater = _heater;
	kp = _kp;
	ki = _ki;
	kd = _kd;
	if (kp == 0 || ki == 0 || kd == 0) {
		throw std::invalid_argument("Brak skonfigurowanych nastaw regulatora.");
	}
}

void RegulatorPID::steruj(float dt) {
	float up, ui, ud,u,e = settemp - room->getTemperatura(), de = (e-ep)/dt;
	up = kp * e;
	ec += e;
	ui = ki * ec;
	ud = kd * de;
	ep = e;
	u = up + ui + ud;
	heater->setCurPower(u);
}

float RegulatorPID::getSettemp() {
	return settemp;
}



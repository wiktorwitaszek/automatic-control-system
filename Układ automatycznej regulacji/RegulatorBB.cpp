#include "RegulatorBB.h"

RegulatorBB::RegulatorBB(Grzejnik* _heater, Pomieszczenie* _room) {
	room = _room;
	heater = _heater;
}

void RegulatorBB::steruj(float dt) {
	if (settemp > room->getTemperatura()) {
		heater->setCurPower(1);
	}
	else {
		heater->setCurPower(0);
	}
		
}

float RegulatorBB::getSettemp() {
	return settemp;
}
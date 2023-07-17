#include "Regulator.h"

Regulator::Regulator() {
	setsettemp();
}

void Regulator::setsettemp() {
	float choose;

	while (1) {
		std::cout << "Set the temperature: ";
		std::cin >> choose;
		if (std::cin.fail() == true) {
			std::cout << "Wrong character selected!" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else {
			settemp = choose;
			
			break;
		}
	}
}

void Regulator::uruchom(float dt) {
	{
		if (!sprawdzPowiazania()) {
			throw std::invalid_argument("Brak skonfigurowanych powiazan z innymi obiektami.");
		}
		std::cout << "Regulator zostal uruchomiony." << std::endl;
	}
}

bool Regulator::sprawdzPowiazania() {
	if (room == nullptr || heater == nullptr) return false;

	else return true;
}

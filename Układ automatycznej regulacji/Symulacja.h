#pragma once
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"
#include "Regulator.h"
#include "iostream"
#include <vector>
#include <fstream>
#include <exception>

using namespace std;

class Symulacja
{
	Pomieszczenie room;
	Grzejnik heater;
	Regulator* reg;
	vector<float> templog;
	vector<float> timelog;
	vector<float> powerlog;
	void iteracja(float);
	void save(int il);
	void menu();

public:
	Symulacja();
	~Symulacja();
	void przebieg(int, float);
};


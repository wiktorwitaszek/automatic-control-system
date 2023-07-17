#include "Symulacja.h"

Symulacja::Symulacja() : room(3,5,3),heater(3000) {
	menu();
}
Symulacja::~Symulacja() {
	delete reg;
}
void Symulacja::iteracja(float dt) {
	reg->steruj(dt);
	room.dodajCieplo(heater.akt_cieplo());
	room.aktualizuj(dt);
	cout << room.getTemperatura() << endl;
}

void Symulacja::przebieg(int il, float dt) {
	
	try {
		if (il <= 0 || dt <= 0) {
			throw std::invalid_argument("Ujemne wartosci przebiegu.");
		}
		reg->uruchom(dt);
	}
	catch (const std::exception& e) {
		std::cout << "Wystapil wyjatek: " << e.what() << std::endl;
		exit(1);
	}
	templog.reserve(il);
	timelog.reserve(il);
	powerlog.reserve(il);
	for(int i = 0; i < il; i++)
	{
		iteracja(dt);	
		templog.push_back(room.getTemperatura());
		timelog.push_back(dt*i);
		powerlog.push_back(heater.akt_cieplo());
	}
	save(il);
}
void Symulacja::save(int il) {
	ofstream outputFile("dane.csv");
	if (outputFile.is_open()) { 
		outputFile << "Time;" << "Temperature;" << "Power;" << endl;
		for (int i = 0; i < il; i++)
		{
			outputFile << timelog[i] << ";" << templog[i] << ";" << powerlog[i] << endl;
		}
		
		outputFile.close();
	}
	else {
		cerr << "File cannot be opened." << endl;
	}
}

void Symulacja::menu() {
	int choose;

	while (1) {
		cout << "Wybierz regulator\n1 --> PID 2 --> BB" << endl;
		cin >> choose;
		if (cin.fail() == true || (choose != 1 && choose != 2)) {
			cout << "Wrong character selected. Please specify 1 or 2!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else {
			try {
				if (choose == 1) reg = new RegulatorPID(&heater, &room);


				else reg = new RegulatorBB(&heater, &room);
			}
			catch (const std::exception& e) {
				std::cout << "Wystapil wyjatek: " << e.what() << std::endl;
				exit(1);
			}
			
			break;
		}
	}
}
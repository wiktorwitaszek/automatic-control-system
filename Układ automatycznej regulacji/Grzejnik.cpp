#include "Grzejnik.h"

Grzejnik::Grzejnik(float moc_nom, float akt) {
	moc_nominalna = moc_nom;
	akt_moc = akt;
}

void Grzejnik::setCurPower(float m) {
	if (m > 1){
		m = 1;
	}
	else if (m < 0) {
		m = 0;
	}
	akt_moc = m;
}

float Grzejnik::akt_cieplo() {

	return akt_moc * moc_nominalna;
}

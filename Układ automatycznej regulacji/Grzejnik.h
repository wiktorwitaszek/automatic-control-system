#pragma once
class Grzejnik
{
	float akt_moc, moc_nominalna;
public:
	Grzejnik(float, float = 1);
	float akt_cieplo();
	void setCurPower(float = 1);
};


#include "Produs.h"
#include <assert.h>
#include <sstream>
#include <cstring>

using std::stringstream;

bool ComparareTipProdus(const Produs& produs1, const Produs& produs2)
{
	return produs1.GetTipProdus() < produs2.GetTipProdus();
}

bool ComparareNumeProdus(const Produs& produs1, const Produs& produs2)
{
	return produs1.GetNumeProdus() < produs2.GetNumeProdus();
}

bool ComparareProducatorProdus(const Produs& produs1, const Produs& produs2)
{
	return produs1.GetProducatorProdus() < produs2.GetProducatorProdus();
}



bool Produs::operator==(const Produs& other)const
{
	if (numeProdus == other.GetNumeProdus() && tipProdus == other.GetTipProdus() && pretProdus == other.GetPretProdus() && producatorProdus == other.GetProducatorProdus())
		return true;
	return false;
}

std:: ostream& operator<<(std::ostream& os, const Produs& produs)
{
	os << produs.GetNumeProdus() << " " << produs.GetTipProdus() << " " << produs.GetPretProdus() << " Ron " << produs.GetProducatorProdus() << '\n';
	return os;
}

void TesteProdus()
{
	Produs produs1("Nume", "Aliment", 15, "Nestle");
	Produs produs2("AltNume", "Electronice", 15, "Philips");
	Produs produsAcelasi("Nume", "Aliment", 15, "Nestle");
	assert(produs1.GetNumeProdus() == "Nume");
	assert(produs1.GetTipProdus() == "Aliment");
	assert(produs1.GetPretProdus() == 15);
	assert(produs1.GetProducatorProdus() == "Nestle");

	assert(produs1 == produsAcelasi);

	assert(!ComparareNumeProdus(produs1, produs2));
	assert(ComparareTipProdus(produs1, produs2));
	assert(ComparareProducatorProdus(produs1, produs2));

	stringstream out;
	out << produs1;
	std::string produsAfisat = out.str();
	const char* mesaj = produsAfisat.c_str();
	assert(strcmp(mesaj, "Nume Aliment 15 Ron Nestle\n") == 0);
}
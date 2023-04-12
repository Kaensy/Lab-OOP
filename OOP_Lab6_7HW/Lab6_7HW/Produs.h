#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;

class Produs {
	std::string numeProdus;
	std::string tipProdus;
	int pretProdus;
	std::string producatorProdus;

public:
	Produs(const string nume, const string tip, const int pret, const string producator)
		:numeProdus{nume},tipProdus{tip},pretProdus{pret},producatorProdus{producator}{}

	Produs(const Produs& altProdus)
		:numeProdus{altProdus.numeProdus},tipProdus{altProdus.tipProdus},pretProdus{altProdus.pretProdus},producatorProdus{altProdus.producatorProdus}{
		cout << "!!!!!!!!!!!!!!!!!!!!\n";
	}

	string GetNumeProdus() const 
	{
		return numeProdus;
	}
	
	string GetTipProdus() const
	{
		return tipProdus;
	}

	int GetPretProdus() const noexcept
	{
		return pretProdus;
	}

	string GetProducatorProdus() const
	{
		return producatorProdus;
	}

	bool operator ==(const Produs& other)const;

	friend std::ostream& operator<<(std::ostream& os, const Produs& produs);
};

bool ComparareTipProdus(const Produs& produs1, const Produs& produs2);

bool ComparareNumeProdus(const Produs& produs1, const Produs& produs2);

bool ComparareProducatorProdus(const Produs& produs1, const Produs& produs2);



void TesteProdus();
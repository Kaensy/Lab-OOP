#include "RepoProduse.h"

#include <assert.h>
#include <iostream>
#include <sstream>
#include <cstring>

using std::ostream;
using std::stringstream;

void RepoProduse::AdaugaProdusRepo(const Produs& produs)
{
	if (ExistaProdusInLista(produs))
	{
		throw RepoProduseException("Exista deja produsul");
	}
	produse.push_back(produs);
}

void RepoProduse::StergeProdusRepo(const Produs& produs)
{
	if (!ExistaProdusInLista(produs))
	{
		throw RepoProduseException("Produsul nu exista in lista");
	}
	produse.erase(produse.begin() + CautaPozitiaProdusRepo(produs));
}

bool RepoProduse::ExistaProdusInLista(const Produs& produs) const
{
	try
	{
		CautaProdusDupaNumeTipPretProducatorRepo(produs.GetNumeProdus(), produs.GetTipProdus(), produs.GetPretProdus(), produs.GetProducatorProdus());
		return true;
	}
	catch (RepoProduseException&)
	{
		return false;}
}

const Produs& RepoProduse::CautaProdusDupaNumeTipRepo(string numeProdus, string tipProdus)
{
	for (const auto& produsCurent : produse)
	{
		if (produsCurent.GetNumeProdus() == numeProdus && produsCurent.GetTipProdus() == tipProdus)
			return produsCurent;
	}
	throw RepoProduseException("Nu exista produsul");}

const Produs& RepoProduse::CautaProdusDupaNumeTipPretProducatorRepo(string numeProdus, string tipProdus, int pretProdus, string numeProducator) const
{
	Produs produsCautat(numeProdus, tipProdus, pretProdus, numeProducator);
	for (const auto& produs : produse)
	{
		if (produsCautat == produs)
		{
			return produs;
		}
	}
	throw RepoProduseException("Nu exista produsul : " + numeProdus + " de tipul : " + tipProdus + " produs de " + numeProducator);}

const int RepoProduse::CautaPozitiaProdusRepo(const Produs& produs) const
{
	int i = 0;
	for (const auto& produsCurent : produse)
	{
		if (produsCurent == produs)
		{
			return i;
		}
		i++;
	}
	throw RepoProduseException("Nu exista produsul");
}

const vector<Produs>& RepoProduse::GetAllProduse() const noexcept
{
	return produse;
}

void RepoProduse::ModificaProdusRepo(const Produs& produsDeModificat, const Produs& produsPentruModificat)
{
	if (!ExistaProdusInLista(produsDeModificat))
	{
		throw RepoProduseException("Produsul nu exista in lista");
	}
	if (ExistaProdusInLista(produsPentruModificat))
	{
		throw RepoProduseException("Produsul deja exista in lista");
	}
	produse[CautaPozitiaProdusRepo(produsDeModificat)] = produsPentruModificat;
}

ostream& operator<<(ostream& out, const RepoProduseException& exception) 
{
	out << exception.mesaj;
	return out;
}

void TesteRepo()
{
	RepoProduse repo;
	Produs produs1("Nume", "Aliment", 15, "Nestle");
	Produs produs2("AltNume", "Electronice",20, "Philips");
	Produs produsInexistent("a", "a", 29, "a");
	Produs produsAcelasi("Nume", "Aliment", 15, "Nestle");
	
	repo.AdaugaProdusRepo(produs1);
	repo.AdaugaProdusRepo(produs2);
	assert(repo.GetAllProduse().size() == 2);
	assert(repo.CautaProdusDupaNumeTipPretProducatorRepo("Nume", "Aliment", 15, "Nestle") == produs1);

	try 
	{
		repo.AdaugaProdusRepo(produsAcelasi);
		assert(false);
	}
	catch (const RepoProduseException& e)
	{	
		stringstream out;
		out << e;
		std::string const mesajExceptie = out.str();
		const char* mesaj = mesajExceptie.c_str();
		assert(strcmp(mesaj,"Exista deja produsul") == 0);
	}

	repo.StergeProdusRepo(produs1);
	assert(repo.GetAllProduse().size() == 1);
	assert(repo.GetAllProduse()[0] == produs2);

	try
	{
		repo.StergeProdusRepo(produs1);
		assert(false);
	}
	catch (const RepoProduseException&)
	{
		assert(true);
	}
	
	assert(repo.CautaProdusDupaNumeTipPretProducatorRepo("AltNume", "Electronice", 20, "Philips") == produs2);
	assert(repo.CautaProdusDupaNumeTipRepo("AltNume", "Electronice") == produs2);

	try
	{
		repo.CautaProdusDupaNumeTipPretProducatorRepo("a", "a", 29, "a");
		assert(false);
	}
	catch (const RepoProduseException&)
	{
		assert(true);
	}

	try
	{
		repo.CautaProdusDupaNumeTipRepo("a", "a");
		assert(false);
	}
	catch (const RepoProduseException&)
	{
		assert(true);
	}

	assert(repo.CautaPozitiaProdusRepo(produs2) == 0);
	try
	{
		repo.CautaPozitiaProdusRepo(produsInexistent);
		assert(false);
	}
	catch (const RepoProduseException&)
	{
		assert(true);
	}

	repo.ModificaProdusRepo(produs2, produs1);
	assert(repo.GetAllProduse()[0] == produs1);

	try
	{
		repo.ModificaProdusRepo(produs2, produs1);
		assert(false);
	}
	catch (const RepoProduseException&)
	{
		assert(true);
	}
	try
	{
		repo.ModificaProdusRepo(produs1, produs1);
		assert(false);
	}
	catch (const RepoProduseException&)
	{
		assert(true);
	}

}
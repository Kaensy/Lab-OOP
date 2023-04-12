#include "ServiceProduse.h"

#include <functional>
#include <algorithm>
#include <assert.h>

void ProduseService::AdaugaProdusService(const string& numeProdus, const string& tipProdus, const int pretProdus, const string& numeProducator)
{
	Produs produs(numeProdus, tipProdus, pretProdus, numeProducator);
	repo.AdaugaProdusRepo(produs);
}

void ProduseService::StergeProdusService(const string& numeProdus, const string& tipProdus, const int pretProdus, const string& numeProducator)
{
	Produs produs(numeProdus, tipProdus, pretProdus, numeProducator);
	repo.StergeProdusRepo(produs);
}

void ProduseService::ModificaProdusService(const string& numeProdusDeModificat, const string& tipProdusDeModificat, const int pretProdusDeModificat, const string& numeProducatorDeModificat,const string& numeProdusPentruModificat, const string& tipProdusPentruModificat, const int pretProdusPentruModificat, const string& numeProducatorPentruModificat)
{
	Produs produsDeModificat(numeProdusDeModificat, tipProdusDeModificat, pretProdusDeModificat, numeProducatorDeModificat);
	Produs produsPentruModificat(numeProdusPentruModificat, tipProdusPentruModificat, pretProdusPentruModificat, numeProducatorPentruModificat);
	repo.ModificaProdusRepo(produsDeModificat, produsPentruModificat);
}

const Produs& ProduseService::CautaProdusDupaNumeTipService(const string& numeProdus, const string& tipProdus) const
{
	return repo.CautaProdusDupaNumeTipRepo(numeProdus, tipProdus);
}

void TesteService()
{
	Produs produs1("Nume", "Aliment", 15, "Nestle");
	Produs produs2("AltNume", "Electronice", 15, "Philips");
	Produs produsAcelasi("Nume", "Aliment", 15, "Nestle");
	RepoProduse repo;
	ProduseService service(repo);
	assert(service.GetAllProduseService().size() == 0);
	service.AdaugaProdusService("Nume", "Aliment", 15, "Nestle");
	assert(service.GetAllProduseService().size() == 1);
	service.StergeProdusService("Nume", "Aliment", 15, "Nestle");
	assert(service.GetAllProduseService().size() == 0);
	
	service.AdaugaProdusService("Nume", "Aliment", 15, "Nestle");
	service.ModificaProdusService("Nume", "Aliment", 15, "Nestle", "AltNume", "Electronice", 15, "Philips");
	assert(service.GetAllProduseService()[0] == produs2);
	assert(service.CautaProdusDupaNumeTipService("AltNume", "Electronice") == produs2);
}
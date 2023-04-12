#pragma once

#include "RepoProduse.h"
#include "Produs.h"

#include <string>
#include <vector>

#include <functional>

using std::vector;
using std::function;

class ProduseService
{
	RepoProduse& repo;

public:
	ProduseService(RepoProduse& repo) noexcept : repo{repo}{}

	ProduseService(const ProduseService& ot) = delete;

	/*
	returneaza toate produsele in ordinea in care au fost adaugate
	*/
	const vector<Produs>& GetAllProduseService() noexcept
	{
		return repo.GetAllProduse();
	}

	/*
	Creeaza un produs nou pe baza paramatrilor, daca este valid il adauga in lista, daca nu arunca exceptie
	*/
	void AdaugaProdusService(const string& numeProdus, const string& tipProdus, const int pretProdus, const string& numeProducator);

	/*
	Sterge produsul cu parametrii introdusi, arunca exceptie daca acesta nu exista
	*/
	void StergeProdusService(const string& numeProdus, const string& tipProdus, const int pretProdus, const string& numeProducator);

	/*
	Creeaza 2 instante de Produs pe baza parametrilor, 
	primi 4 -> prima instanta 
	urmatori 4 -> a doua instanta
	Va cauta produsul care este identic cu prima instanta de Produs creata si o va inlocui cu a doua instanta
	Daca produsul nu este gasit va arunca exceptie
	Daca exista un produs identic cu a doua instanta de Produs creata va arunca exceptie
	*/
	void ModificaProdusService(const string& numeProdusDeModificat, const string& tipProdusDeModificat, const int pretProdusDeModificat, const string& numeProducatorDeModificat,const string& numeProdusPentruModificat, const string& tipProdusPentruModificat, const int pretProdusPentruModificat, const string& numeProducatorPentruModificat);

	/*
	Cauta produsul cu numele numeProdus si tipul tipProdus si il returneaza
	Arunca exceptie daca acesta nu exista
	*/
	const Produs& CautaProdusDupaNumeTipService(const string& numeProdus, const string& tipProdus) const;
};

void TesteService();
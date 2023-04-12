#pragma once
#include "Produs.h"
#include "VectorDinamic.h"

//#include <vector>
#include <string>
#include <ostream>

//using std::vector;
using std::string;
using std::ostream;

class RepoProduse 
{
	ListaRepo<Produs> produse;

	/*
	Verifica daca exista deja produs in repo
	*/
	bool ExistaProdusInLista(const Produs& produs) const;

public:
	RepoProduse() = default;

	RepoProduse(const RepoProduse& ot) = delete;

	/*
	Salvare produs in repo
	Intoarce exceptie daca mai exista produsul in repo
	*/
	void AdaugaProdusRepo(const Produs& produs);

	/*
	Sterge produs din repo
	Arunca exceptie daca produsul nu exista
	*/
	void StergeProdusRepo(const Produs& produs);

	/*
	Cauta produs, returneaza produsul daca il gaseste
	Arunca exceptie daca nu exista in repo
	*/
	const Produs& CautaProdusDupaNumeTipPretProducatorRepo(string numeProdus, string tipProdus, int pretProdus, string numeProducator) const;

	/*
	Cauta produs, returneaza produsul
	Arunca exceptie daca nu exista in repo
	*/
	const Produs& CautaProdusDupaNumeTipRepo(string numeProdus, string tipProdus);

	/*
	Cauta pozitia produsului, returneaza pozitia daca o gaseste
	Arunca exceptie daca nu exista in repo
	*/
	const int CautaPozitiaProdusRepo(const Produs& produs) const;

	/*
	returneaza toate produsele salvate in repo
	*/
	const ListaRepo<Produs> &GetAllProduse() const noexcept;

	/*
	Modifica produsul produsDeModificat din lista cu noul produs produsPentruModificat
	Arunca exceptie daca:
		produsDeModificat nu se afla in lista 
		produsPentruModificat se afla deja in lista
	*/
	void ModificaProdusRepo(const Produs& produsDeModificat, const Produs& produsPentruModificat);
};

class RepoProduseException
{
	string mesaj;

public:
	
	RepoProduseException(string mesaj):mesaj{mesaj}{}

	friend ostream& operator<<(ostream& out, const RepoProduseException& mesajExceptie);
};

ostream& operator<<(ostream& out, const RepoProduseException& mesajExceptie);

void TesteRepo();
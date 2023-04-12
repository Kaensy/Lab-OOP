#include "ui.h"
#include "Produs.h"

#include <iostream>
#include <string>

using std::cout;
using std::cin;

constexpr int Exit = 0;
constexpr int  Adaugare_Produs = 1;
constexpr int Stergere_Produs = 2;
constexpr int Modificare_Produs = 3;
constexpr int Afisare_Produse = 4;
constexpr int Cautare_Produs_Dupa_Nume_tip = 5;
constexpr int Sortare_Produse = 6;
constexpr int Filtrare_produse = 7;

void UI::AdaugaProdusUI()
{
	string numeProdus, tipProdus, numeProducator;
	int pretProdus;
	cout << "Nume Produs: ";
	cin >> numeProdus;
	cout << "Tip Produs: ";
	cin >> tipProdus;
	cout << "Pret Produs: ";
	cin >> pretProdus;
	cout << "Nume Producator: ";
	cin >> numeProducator;
	service.AdaugaProdusService(numeProdus, tipProdus, pretProdus, numeProducator);
	cout << "\nProdus adaugat cu succes!\n";
}

void UI::StergeProdusUI()
{
	string numeProdus, tipProdus, numeProducator;
	int pretProdus;
	cout << "Nume Produs: ";
	cin >> numeProdus;
	cout << "Tip Produs: ";
	cin >> tipProdus;
	cout << "Pret Produs: ";
	cin >> pretProdus;
	cout << "Nume Producator: ";
	cin >> numeProducator;
	service.StergeProdusService(numeProdus, tipProdus, pretProdus, numeProducator);
	cout << "\nProdus sters cu succes!\n";
}

void UI::ModificaProdusUI()
{
	string numeProdusDeModificat, tipProdusDeModificat, numeProducatorDeModificat;
	int pretProdusDeModificat;
	cout << "Produs Dorit Modificat:\n" << "Nume Produs: ";
	cin >> numeProdusDeModificat;
	cout << "Tip Produs: ";
	cin >> tipProdusDeModificat;
	cout << "Pret Produs: ";
	cin >> pretProdusDeModificat;
	cout << "Nume Producator: ";
	cin >> numeProducatorDeModificat;
	
	string numeProdusPentruModificare, tipProdusPentruModificare, numeProducatorPentruModificare;
	int pretProdusPentruModificare;
	cout << "\nParametri noi:\n" << "Nume Produs: ";
	cin >> numeProdusPentruModificare;
	cout << "Tip Produs: ";
	cin >> tipProdusPentruModificare;
	cout << "Pret Produs: ";
	cin >> pretProdusPentruModificare;
	cout << "Nume Producator: ";
	cin >> numeProducatorPentruModificare;

	service.ModificaProdusService(numeProdusDeModificat, tipProdusDeModificat, pretProdusDeModificat, numeProducatorDeModificat, numeProdusPentruModificare, tipProdusPentruModificare, pretProdusPentruModificare, numeProducatorPentruModificare);
	cout << "Produs Modificat cu succes!\n";
}

void UI::CautaProdusDupaNumeTipUI()
{
	string numeProdus, tipProdus;
	cout << "Nume produs cautat: ";
	cin >> numeProdus;
	cout << "Tip produs cautat: ";
	cin >> tipProdus;
	cout << "Produs Cautat : " << service.CautaProdusDupaNumeTipService(numeProdus, tipProdus);
}

void UI::TiparesteToateProduseleUI(const vector<Produs>& produse)
{
	cout << "Produse:\n";
	for (const auto& produs : produse)
	{
		cout << produs;
	}
}

void UI::run()
{
	while (true)
	{
		cout << "\n1.Adaugare\n2.Stergere\n3.Modificare\n4.Afisare produse\n5.Cautare produs\n6.Filtrare produse\n7.Sortare produse\n0.Exit\n\n>>>";
		int comanda;
		cin >> comanda;
		cout << '\n';
		try
		{
			switch (comanda)
			{
			case Adaugare_Produs:
				AdaugaProdusUI();
				break; 
			case Stergere_Produs:
				StergeProdusUI();
				break;
			case Modificare_Produs:
				ModificaProdusUI();
				break;
			case Afisare_Produse:
				TiparesteToateProduseleUI(service.GetAllProduseService());
				break;
			case Cautare_Produs_Dupa_Nume_tip:
				CautaProdusDupaNumeTipUI();
				break;
			case Exit:
				return;
			default:
				cout << "Comanda invalida\n";
			}
		}
		catch (const RepoProduseException& exception)
		{
			cout << exception << '\n';
		}
	}
}
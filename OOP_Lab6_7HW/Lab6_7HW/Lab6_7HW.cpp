/*
    1.Magazin
    Creați o aplicație care permite:
    gestiunea unei liste de produse. Produs: nume, tip, preț, producător
    adăugare,ștergere, modificare si afișare produse
    căutare produs
    filtrare produse după: preț, nume, producător
    sortare produse după: nume, preț, nume + tip
*/
#include "ui.h"

#include <iostream>

void AdaugaCatevaProduse(ProduseService& service)
{
    service.AdaugaProdusService("a", "Aliment", 50, "Nestle");
    service.AdaugaProdusService("c", "Bautura", 25, "CC");
    service.AdaugaProdusService("e", "Aliment", 66, "Nestle");
    service.AdaugaProdusService("d", "Entertainment", 10, "Samsung");
    service.AdaugaProdusService("b", "Electronice", 45, "SteelSeries");
}

void Teste()
{
    TesteProdus();
    TesteRepo();
    TesteService();
}

int main()
{
    Teste();
    
    RepoProduse repo;
    ProduseService service(repo);
    AdaugaCatevaProduse(service);
    UI ui(service);
    ui.run();
    //_CrtDumpMemoryLeaks();
}

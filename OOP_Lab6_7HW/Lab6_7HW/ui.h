#pragma once

#include "ServiceProduse.h"
#include "Produs.h"

class UI {
	ProduseService& service;

	void AdaugaProdusUI();

	void StergeProdusUI();

	void ModificaProdusUI();

	void TiparesteToateProduseleUI(const vector<Produs>& produse);

	void CautaProdusDupaNumeTipUI();

public:
	UI(ProduseService& service) noexcept :service{service} {}

	UI(const UI& ot) = delete;

	void run();
};
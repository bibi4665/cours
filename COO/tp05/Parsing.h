#ifndef PARSING_H
#define PARSING_H

#include <string>
#include <vector>
#include "Commande.h"
#include "cible.h"

class Parsing {

private:
	std::vector<Commande*> commandes;
	Cible cible;

public:
	void parse(std::string ligne);

	bool hasCommande(Commande commande);

	std::vector<Cible> getCibles();
};

#endif

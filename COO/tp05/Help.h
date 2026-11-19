#ifndef HELP_H
#define HELP_H

#include <string>
#include <vector>
#include "Commande.h"

class Help : Commande {

public:
	std::vector<Commande*> commandes;

	std::string afficher();
};

#endif

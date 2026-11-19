#ifndef COMMANDE_H
#define COMMANDE_H

#include <string>
#include <vector>

class Commande {

private:
	int nb_arg;
	std::string description;
	bool flag_obligatoire;
	bool flag_immediat;
	std::vector<std::string> alias;
	std::vector<std::string> arguments;

public:
	Commande(
		std::vector<std::string> alias,
		int nb_arg,
		std::string description,
		bool flag_obligatoire,
		bool flag_immediat
	);

	virtual ~Commande() = default;

	void argument(std::string argument);

	virtual void lancement();
};

#endif

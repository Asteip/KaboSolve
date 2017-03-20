#include "cNQueen.hpp"

#include <iostream>

using namespace std;

CNQueen::CNQueen(Domain **domains, int size) : Constraint(domains, size) {}

CNQueen::~CNQueen() {}

// id = indice de la variable dans le tableau
// et
// id = ligne où l'on veut savoir l'emplacement de la reine
// id E {0,...,size-1}
bool CNQueen::applyConstraint(int id) {
	int val = _domains[id]->getValue();
	bool modification = false;

	for (int i = 0; i < _size; ++i) {
		if (!_domains[i]->getIsSet()) {
			modification = modification || _domains[i]->prunerValeur(id, val-id+i);
			modification = modification || _domains[i]->prunerValeur(id, val-i+id);
		}
	}

	return modification;
}

void CNQueen::display() {}
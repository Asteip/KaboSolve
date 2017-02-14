#include "cNQueen.hpp"

#include <iostream>

using namespace std;

CNQueen::CNQueen(Domain **domains, int size) : Constraint(domains, size) {}

CNQueen::~CNQueen() {}

// id = indice de la variable dans le tableau
// et
// id = ligne où l'on veut savoir l'emplacement de la reine
// id E {0,...,size-1}
void CNQueen::applyConstraint(int id) {
	cout << "id=" << id << endl;
	int diff = id - _domains[id]->getValue();
	if (diff < 0) {
		diff = -diff;
	}

	for (int i = 0; i < _size; ++i) {
		if (i != id) {
			_domains[i]->prunerValeur(id, i+diff);
			_domains[i]->prunerValeur(id, diff-i);
		}
	}
}

void CNQueen::display() {}
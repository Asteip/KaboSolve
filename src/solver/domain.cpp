#include "domain.hpp"

#include <cassert>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>

using namespace std;

// UTILITAIRES
void Domain::triBulle() {
	bool fini;
	int i, j, val;
	j = 0;
	do {
		fini = true;
		for (i = 1; i < n-j; ++i) {
			if (possibles[i-1] > possibles[i]) {
				val = possibles[i];
				possibles[i] = possibles[i-1];
				possibles[i-1] = val;
				fini = false;
			}
		}
		++j;
	} while(!fini);
}

int Domain::dichotomie(int val) {
	assert(size > 0);
	int inf, sup, ind, valInd;
	inf = 0;
	sup = size;
	ind = sup/2;
	valInd = possibles[ind];
	while ((sup > inf+1) && (valInd != val)) {
		if (valInd > val) {
			sup = ind;
		} else {
			inf = ind;
		}
		ind = inf + (sup-inf)/2;
		valInd = possibles[ind];
	}
	return ind;
}

int Domain::indVal(int val) {
	int ind;
	if (size > 0) {
		ind = dichotomie(val);

		if (possibles[ind] != val) {
			ind = -1;
		}
	} else {
		ind = -1;
	}

	return ind;
}

int Domain::posValSupOuEgale(int val) {
	int ind;

	if (size > 0) {
		ind = dichotomie(val);

		if (possibles[ind] < val) {
			++ind;
		}
	} else {
		ind = 0;
	}

	return ind;
}

int Domain::posValInfOuEgale(int val) {
	int ind;

	if (size > 0) {
		ind = dichotomie(val);

		if (possibles[ind] > val) {
			--ind;
		}
	} else {
		ind = 0;
	}

	return ind;
}

// CONSTRUCTEUR
Domain::Domain(int id, int n, int *set) {
	this->id = id;
	this->n = n;
	this->size = n;
	this->nbPruned = 0;
	this->possibles = set;
	triBulle();
	this->indexes = new int[n];
	this->pruned = new int[n];
	this->isSet = false;
}

// FIXAGE
void Domain::fixer() {
	isSet = true;
	value = possibles[rand()%size];
	prunerValeur(-1, value);
}

// PRUNAGES
void Domain::prunerValeur(int id, int val) {
	if ((val >= possibles[0]) && (val <= possibles[size-1])) {
		int ind = indVal(val);
		if (ind != -1) {
			pruned[nbPruned] = val;
			indexes[nbPruned] = id;
			++nbPruned;
			--size;
			for (int i = ind; i < size; ++i) {
				possibles[i] = possibles[i+1];
			}
		}
	}
}

void Domain::prunerSup(int id, int val) {
	if (val <= possibles[size-1]) {
		int ind = posValSupOuEgale(val);
		int diff = size-ind;
		for (int i = size-1; i >= ind; --i) {
			pruned[nbPruned] = possibles[i];
			indexes[nbPruned] = id;
			++nbPruned;
		}
		size = size - diff;
	}
}

void Domain::prunerInf(int id, int val) {
	if (val >= possibles[0]) {
		int ind = posValInfOuEgale(val);
		int i;
		for (i = ind; i >= 0; --i) {
			pruned[nbPruned] = possibles[i];
			indexes[nbPruned] = id;
			possibles[i] = possibles[i+ind+1];
			++nbPruned;
		}
		for (i = ind+1; i < size; ++i) {
			possibles[i] = possibles[i+ind+1];
		}
		size = size - ind - 1;
	}
}

// BACKTRACK
void Domain::backtrack(int id) {
	/*cout << "AVANT" << endl;
	cout << "size=" << size << endl;
	cout << "nbPruned=" << nbPruned << endl;
	cout << "possibles :" << endl;
	for (int l = 0; l < size; ++l) {
		cout << possibles[l] << "|";
	}
	cout << endl << "pruned :" << endl;
	for (int l = 0; l < nbPruned; ++l) {
		cout << pruned[l] << "|";
	}*/






	int i, ind;
	while ((nbPruned > 0) && (indexes[nbPruned-1] == id)) {
		--nbPruned;
		ind = posValSupOuEgale(pruned[nbPruned]);
		for (i = size; i > ind; --i) {
			possibles[i] = possibles[i-1];
		}
		possibles[ind] = pruned[nbPruned];
		++size;
	}









	/*cout << endl << "APRES" << endl;
	cout << "size=" << size << endl;
	cout << "nbPruned=" << nbPruned << endl;
	cout << "possibles :" << endl;
	for (int l = 0; l < size; ++l) {
		cout << possibles[l] << "|";
	}
	cout << endl << "pruned :" << endl;
	for (int l = 0; l < nbPruned; ++l) {
		cout << pruned[l] << "|";
	}*/
}

void Domain::reset() {
	this->backtrack(-1);
	isSet = false;
}

// ACCESSEURS
int Domain::getId() {
	return id;
}

int Domain::getN() {
	return n;
}

int Domain::getSize() {
	return size;
}

int Domain::getMin() {
	return possibles[0];
}

int Domain::getMax() {
	return possibles[size-1];
}

int Domain::getValue() {
	assert(isSet);
	return value;
}

bool Domain::getIsSet() {
	return isSet;
}


// AFFICHAGE DEBUG
void Domain::affichage() {
	cout << "id=" << id << endl;
	cout << "n=" << n << endl;
	cout << "size=" << size << endl;
	cout << "nbPruned=" << nbPruned << endl;
	cout << "value=" << value << endl;
	cout << "isSet=" << isSet << endl << endl;

	cout << "possibles :" << endl;
	for (int i = 0; i < size; ++i) {
		cout << i << ": " << possibles[i] << endl;
	}

	cout << endl << "pruned | indexes :" << endl;
	for (int i = 0; i < nbPruned; ++i) {
		cout << i << ": " << pruned[i] << " | " << indexes[i] << endl;
	}
}

/*void Domain::affichageNQueen() {
	cout << "{";
	if (size > 0) {
		cout << possibles[0];
	}
	for (int i = 1; i < size; ++i) {
		 cout << ", " << possibles[i];
	}
	cout << "}" << endl;
}*/

void Domain::affichageNQueen() {
	int j = 0;
	if (!isSet) {
		for (int i = 0; i < n; ++i) {
			if ((j < size) && (possibles[j] == i)) {
				cout << "_ ";
				++j;
			} else {
				cout << "X ";
			}
		}
	} else {
		for (int i = 0; i < n; ++i) {
			if (i == getValue()) {
				cout << "O ";
			} else if ((j < size) && (possibles[j] == i)) {
				cout << "_ ";
				++j;
			} else {
				cout << "X ";
			}
		}
	}
	cout << endl;
}

void Domain::affichageResultatNQueen() {
	int j = 0;
	assert(isSet);
	for (int i = 0; i < n; ++i) {
		if (i == getValue()) {
			cout << "O ";
		} else {
			cout << "_ ";
			++j;
		}
	}
	cout << endl;
}



void Domain::setId(int id) {
	this->id = id;
}
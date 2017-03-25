#include "domain.hpp"

#include <cassert>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

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
bool Domain::prunerValeur(int id, int val) {
	bool modification = false;
	if ((val >= possibles[0]) && (val <= possibles[size-1])) {
		int ind = indVal(val);
		if (ind != -1) {
			modification = true;
			pruned[nbPruned] = val;
			indexes[nbPruned] = id;
			++nbPruned;
			--size;
			for (int i = ind; i < size; ++i) {
				possibles[i] = possibles[i+1];
			}
		}
	}
	return modification;
}

bool Domain::prunerSup(int id, int val) {
	bool modification = false;
	if ((size > 0) && (val <= possibles[size-1])) {
		modification = true;
		int ind = posValSupOuEgale(val);
		int diff = size-ind;
		for (int i = size-1; i >= ind; --i) {
			pruned[nbPruned] = possibles[i];
			indexes[nbPruned] = id;
			++nbPruned;
		}
		size = size - diff;
	}
	return modification;
}

bool Domain::prunerInf(int id, int val) {
	bool modification = false;
	if ((size > 0) && (val >= possibles[0])) {
		modification = true;
		int ind = posValInfOuEgale(val);
		for (int i = ind; i >= 0; --i) {
			pruned[nbPruned] = possibles[i];
			indexes[nbPruned] = id;
			possibles[i] = possibles[i+ind+1];
			++nbPruned;
		}
		for (int i = ind+1; i < size; ++i) {
			possibles[i] = possibles[i+ind+1];
		}
		size = size - ind - 1;
	}
	return modification;
}

// BACKTRACK
void Domain::backtrack(int id) {
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

void Domain::setId(int id) {
	this->id = id;
}
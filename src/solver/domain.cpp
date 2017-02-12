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

int Domain::indVal(int val) {
	int inf, sup, ind, valInd;
	inf = 0;
	sup = n;
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

	if (valInd != val) {
		ind = -1;
	}

	return ind;
}

int Domain::indPossiblesInd(int ind) {
	if (size > 0) {
		int inf, sup, i, indI;
		inf = 0;
		sup = size;
		i = sup/2;
		indI = possibles[i];
		while ((sup > inf+1) && ((indI-ind)*(indI-ind) > 1)) {
			if (indI > ind) {
				sup = i;
			} else {
				inf = i;
			}
			i = inf + (sup-inf)/2;
			indI = possibles[i];
		}

		if (possibles[i] < ind) {
			++i;
		} else if ((i > 0) && (possibles[i] > ind)) {
			--i;
		}

		return i;
	} else {
		return 0;
	}
}

// CONSTRUCTEUR
Domain::Domain(int n, int *set) {
	this->n = n;
	this->size = n;
	this->nbPruned = 0;
	this->possibles = set;
	triBulle();
	this->possibles = new int[n];
	for (int i = 0; i < n; ++i) {
		this->possibles[i] = i;
	}
	this->indexes = new int[n];
	this->pruned = new int[n];
	this->min = possibles[0];
	this->max = possibles[n-1];
}

// FIXAGE
void Domain::fixer() {
	isSet = true;
	value = possibles[rand()%size];
	prunerValeur(-1, value);
}

// PRUNAGES
void Domain::prunerValeur(int id, int val) {
	if ((val >= min) && (val <= max)) {
		int ind = indVal(val);
		if (ind != -1) {
			pruned[nbPruned] = val;
			indexes[nbPruned] = id;
			++nbPruned;
			--size;
			if (size && (val == min)) {
				min = possibles[0];
			}
			if (size && (val == max)) {
				max = possibles[size];
			}
		}
	}
}

// BACKTRACK
void Domain::backtrack(int id) {
	int i, ind;
	i = nbPruned;
	while (indexes[nbPruned] == id) {
		ind = indPossiblesInd(pruned[nbPruned]);
		for (i = size; i > ind; --i) {
			possibles[i] = possibles[i-1];
		}
		possibles[i] = pruned[nbPruned];
		--nbPruned;
		++size;
	}
}

void Domain::reset() {
	backtrack(-1);
}

// ACCESSEURS
int Domain::getN() {
	return n;
}

int Domain::getSize() {
	return size;
}

int Domain::getMin() {
	return min;
}

int Domain::getMax() {
	return max;
}

int Domain::getValue() {
	assert(isSet);
	return value;
}

bool Domain::getIsSet() {
	return isSet;
}
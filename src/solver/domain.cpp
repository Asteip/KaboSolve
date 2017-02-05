#include "domain.hpp"

#include <iostream>

using namespace std;

// UTILITAIRES
void Domain::triBulle() {
	bool fini;
	int i, j, val;
	j = 0;
	do {
		fini = true;
		for (i = 1; i < n-j; ++i) {
			if (set[i-1] > set[i]) {
				val = set[i];
				set[i] = set[i-1];
				set[i-1] = val;
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
	valInd = set[ind];
	while ((sup > inf+1) && (valInd != val)) {
		if (valInd > val) {
			sup = ind;
		} else {
			inf = ind;
		}
		ind = inf + (sup-inf)/2;
		valInd = set[ind];
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

int Domain::indPrunedInd(int ind) {
	if (nbPruned > 0) {
		int inf, sup, i, indI;
		inf = 0;
		sup = nbPruned;
		i = sup/2;
		indI = pruned[i];
		while ((sup > inf+1) && ((indI-ind)*(indI-ind) > 1)) {
			if (indI > ind) {
				sup = i;
			} else {
				inf = i;
			}
			i = inf + (sup-inf)/2;
			indI = pruned[i];
		}

		if (pruned[i] < ind) {
			++i;
		}

		return i;
	} else {
		return 0;
	}
}

void Domain::setPruned(int ind) {
	isPruned[ind] = true;
	int i = indPossiblesInd(ind);
	for (i; i < size; ++i) {
		possibles[i] = possibles[i+1];
	}
	i = indPrunedInd(ind);
	for (int j = nbPruned; j > i; --j) {
		pruned[j] = pruned[j-1];
	}
	pruned[i] = ind;
	++nbPruned;
	--size;
}

// CONSTRUCTEUR
Domain::Domain(int n, int *set) {
	this->n = n;
	this->size = n;
	this->nbPruned = 0;
	this->set = set;
	triBulle();
	isPruned = new bool[n];
	this->possibles = new int[n];
	for (int i = 0; i < n; ++i) {
		this->possibles[i] = i;
	}
	this->indexes = new int[n];
	this->pruned = new int[n];
	this->indMin = 0;
	this->indMax = n-1;
}

// ACCESSEURS
int Domain::getN() {
	return n;
}

int Domain::getSize() {
	return size;
}

int Domain::getMin() {
	return set[indMin];
}

int Domain::getMax() {
	return set[indMax];
}

// PRUNAGES
void Domain::prunerValeur(int id, int val) {
	if ((val >= set[indMin]) && (val <= set[indMax])) {
		int ind = indVal(val);
		if ((ind != -1) &&  (!isPruned[ind])) {
			setPruned(ind);
			if (ind == indMin) {
				++indMin;
			}
			if (ind == indMax) {
				--indMax;
			}
		}
	}
}
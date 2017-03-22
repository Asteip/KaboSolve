#include "pSudoku.hpp"
#include <iostream>

using namespace std;

PSudoku::PSudoku(int n, bool diag) {
	_latin = n;
	_diag = diag;
	generateProblem();
}

PSudoku::~PSudoku() {}

void PSudoku::applyConstraint(int id){
	for(int i = 0 ; i < _m ; ++i){
		_constraints[i]->applyConstraint(id);
	}
}

void PSudoku::generateProblem() {
	int *liste;
	int latinSquare = _latin*_latin;
	Domain **lDom, **lDomCol, **lDomLine;
	_n = latinSquare*latinSquare;
	_m = 3*latinSquare;
	if (_diag) {
		_m+=2;
	}
	_domains = new Domain * [_n];
	_constraints = new Constraint * [_m];

	// DOMAINES
	for (int i = 0; i < _n; ++i) {
		liste = new int [latinSquare];
		for (int j = 0; j < latinSquare; ++j) {
			liste[j] = j+1;
		}
		_domains[i] = new Domain(i, latinSquare, liste);
	}

	// CONTRAINTES
	// ALLDIFF COLONNES ET LIGNES
	for (int i = 0; i < latinSquare; ++i) {
		lDomCol = new Domain * [latinSquare];
		lDomLine = new Domain * [latinSquare];
		for (int j = 0; j < latinSquare; ++j) {
			lDomCol[j] = _domains[j*latinSquare+i];
			lDomLine[j] = _domains[i*latinSquare+j];
		}
		_constraints[2*i] = new CAllDiff(lDomCol, latinSquare);
		_constraints[2*i+1] = new CAllDiff(lDomLine, latinSquare);
	}

	// ALLDIFF SUR LES CARRES
	for (int i = 0; i < _latin; ++i) {
		for (int j = 0; j < _latin; ++j) {
			lDom = new Domain * [latinSquare];
			for (int k = 0; k < _latin; ++k) {
				for (int l = 0; l < _latin; ++l) {
					lDom[k*_latin+l] = _domains[i*_latin*latinSquare+j*_latin+k*latinSquare+l];
				}
			}
			_constraints[i*_latin+j+2*latinSquare] = new CAllDiff(lDom,latinSquare);
		}
	}

	if (_diag) {
		// ALLDIFF SUR LA DIAGONALE 1
		lDom = new Domain * [latinSquare];
		for (int i = 0; i < latinSquare; ++i) {
				lDom[i] = _domains[i*latinSquare+i];
		}
		_constraints[_m-2] = new CAllDiff(lDom, latinSquare);

		// ALLDIFF SUR LA DIAGONALE 2
		lDom = new Domain * [latinSquare];
		for (int i = 0; i < latinSquare; ++i) {
			lDom[i] = _domains[((i+1)*latinSquare)-i-1];
		}
		_constraints[_m-1] = new CAllDiff(lDom, latinSquare);
	}
}

void PSudoku::afficher() {
	int ind = 0;
	int nbMax, nbNumber, val;

	val = _latin*_latin;
	nbMax = 1;
	while (val >= 10) {
		val /= 10;
		++nbMax;
	}


	for (int i = 0; i < _latin; ++i) {
		for (int j = 0; j < _latin; ++j) {
			for (int k = 0; k < _latin; ++k) {
				for (int l = 0; l < _latin; ++l) {
					val = _domains[ind]->getValue();
					nbNumber = 1;
					while (val >= 10) {
						val /= 10;
						++nbNumber;
					}

					cout << " " << _domains[ind]->getValue();

					while (nbNumber < nbMax) {
						cout << " ";
						++nbNumber;
					}

					++ind;
				}
				cout << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
}
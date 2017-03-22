#include "pSudoku.hpp"
#include <iostream>

using namespace std;

PSudoku::PSudoku() {
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
	Domain **lDom, **lDomCol, **lDomLine;
	_n = 81;
	_m = 27;
	_domains = new Domain * [_n];
	_constraints = new Constraint * [_m];

	// DOMAINES
	for (int i = 0; i < _n; ++i) {
		liste = new int [9];
		for (int j = 0; j < 9; ++j) {
			liste[j] = j+1;
		}
		_domains[i] = new Domain(i, 9, liste);
	}

	// CONTRAINTES
	// ALLDIFF COLONNES ET LIGNES
	for (int i = 0; i < 9; ++i) {
		lDomCol = new Domain * [9];
		lDomLine = new Domain * [9];
		for (int j = 0; j < 9; ++j) {
			lDomCol[j] = _domains[j*9+i];
			lDomLine[j] = _domains[i*9+j];
		}
		_constraints[2*i] = new CAllDiff(lDomCol, 9);
		_constraints[2*i+1] = new CAllDiff(lDomLine, 9);
	}

	// ALLDIFF SUR LES CARRES
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			lDom = new Domain * [9];
			for (int k = 0; k < 3; ++k) {
				for (int l = 0; l < 3; ++l) {
					cout << "k=" << k*3+l << " ind=" << i*27+j*3+k*9+l << endl;
					lDom[k*3+l] = _domains[i*27+j*3+k*9+l];
				}
			}
			cout << endl;
			_constraints[i*3+j+18] = new CAllDiff(lDom, 9);
		}
	}

	_m = 27;
}

void PSudoku::afficher() {
	int ind = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				for (int l = 0; l < 3; ++l) {
					cout << " " << _domains[ind]->getValue();
					++ind;
				}
				cout << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
}
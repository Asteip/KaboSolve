#include "pMagicSquare.hpp"
#include <iostream>

using namespace std;

PMagicSquare::PMagicSquare(int n) {
	generateProblem(n);
}

PMagicSquare::~PMagicSquare() {}

void PMagicSquare::applyConstraint(int id){
	for(int i = 0 ; i < _m ; ++i){
		_constraints[i]->applyConstraint(id);
	}
}

void PMagicSquare::generateProblem(int n) {
	int *liste;
	Domain **lDom;
	//_taille = n;
	_n = n*n;
	_m = 1;
	_domains = new Domain * [_n];
	_constraints = new Constraint * [1];

	for (int i = 0; i < _n; ++i) {
		liste = new int[_n];
		for (int j = 0; j < _n; ++j) {
			liste[j] = j+1;
		}
		_domains[i] = new Domain(i, _n, liste);
	}

	lDom = new Domain * [_n];
	for (int j = 0; j < _n; ++j) {
		lDom[j] = _domains[j];
	}
	_constraints[0] = new CAllDiff(lDom, _n);
}

void PMagicSquare::afficher() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << _domains[i*5+j]->getValue() << "\t";
		}
		cout << endl;
	}
}
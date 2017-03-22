#include "pMagicSquare.hpp"
#include <iostream>

using namespace std;

PMagicSquare::PMagicSquare(int n) {
	_taille = n;
	_n = n*n;
	_magic = n*(n*n+1)/2;
	generateProblem();
}

PMagicSquare::~PMagicSquare() {}

void PMagicSquare::applyConstraint(int id){
	for(int i = 0 ; i < _m ; ++i){
		_constraints[i]->applyConstraint(id);
	}
}

void PMagicSquare::generateProblem() {
	int *liste;
	Domain **lDom, **lDomCol, **lDomLine;
	_m = 2*_taille+6;
	_domains = new Domain * [_n];
	_constraints = new Constraint * [_m];
	
	// DOMAINES
	for (int i = 0; i < _n; ++i) {
		liste = new int[_n];
		for (int j = 0; j < _n; ++j) {
			liste[j] = j+1;
		}
		_domains[i] = new Domain(i, _n, liste);
		
		//_domains[i]->affichage();
	}
	
	// COLONNES ET LIGNES
	// Les coefficients
	liste = new int [_taille];
	for (int i = 0; i < _taille; ++i) {
		liste[i] = 1;
	}
	for (int i = 0; i < _taille; ++i) {
		lDomCol = new Domain * [_taille];
		lDomLine = new Domain * [_taille];
		for (int j = 0; j < _taille; ++j) {
			lDomLine[j] = _domains[i*_taille+j];
			lDomCol[j] = _domains[j*_taille+i];
		}
		_constraints[2*i] = new CEqual(liste, _magic, lDomCol, _taille);
		_constraints[2*i+1] = new CEqual(liste, _magic, lDomLine, _taille);
	}
	
	// DIAGONALE 1
	lDom = new Domain * [_taille];
	for(int i = 0; i < _taille; ++i) {
		lDom[i] = _domains[i*_taille+i];
	}
	_constraints[_m-6] = new CEqual(liste, _magic, lDom, _taille);
		
	// DIAGONALE 2
	lDom = new Domain * [_taille];
	for(int i = 0; i < _taille; ++i) {
		lDom[i] = _domains[((i+1)*_taille)-1];
	}
	_constraints[_m-5] = new CEqual(liste, _magic, lDom, _taille);
	
	// ALLDIFF
	lDom = new Domain * [_n];
	for (int i = 0; i < _n; ++i) {
		lDom[i] = _domains[i];
	}
	_constraints[_m-4] = new CAllDiff(lDom, _n);

	// CONTRAINTES DE SYMETRIE
	liste = new int [2];
	liste[0] = 1;
	liste[1] = -1;

	lDom = new Domain * [2];
	lDom[0] = _domains[0];
	lDom[1] = _domains[_taille-1];
	_constraints[_m-3] = new CInfOrEqual(liste, 0, lDom, 2);

	lDom = new Domain * [2];
	lDom[0] = _domains[0];
	lDom[1] = _domains[_n-_taille];
	_constraints[_m-2] = new CInfOrEqual(liste, 0, lDom, 2);

	lDom = new Domain * [2];
	lDom[0] = _domains[_taille-1];
	lDom[1] = _domains[_n-_taille];
	_constraints[_m-1] = new CInfOrEqual(liste, 0, lDom, 2);

	//_m -= 1;
}

void PMagicSquare::afficher() {
	cout << "somme = " << _magic << endl;
	int somme = 0;

	// Somme de la diagonale 2
	for (int i = 0; i < _taille; ++i) {
		somme += _domains[((i+1)*_taille)-1]->getValue();
		cout << "\t";
	}
	cout << "[" << somme << "]" << endl;

	for (int i = 0; i < _taille; ++i) {
		somme = 0;
		for (int j = 0; j < _taille; ++j) {
			somme += _domains[i*_taille+j]->getValue();
			cout << "  " << _domains[i*_taille+j]->getValue() << "\t";
		}
		cout << "[" << somme << "]" << endl;
	}

	// Somme des colonnes
	for (int i = 0; i < _taille; ++i) {
		somme = 0;
		for (int j = 0; j < _taille; ++j) {
			somme += _domains[j*_taille+i]->getValue();
		}
		cout << "[" << somme << "]\t";
	}

	// Somme de la diagonale 1
	somme = 0;
	for (int i = 0; i < _taille; ++i) {
		somme += _domains[i*_taille+i]->getValue();
	}
	cout << "[" << somme << "]" << endl;

	cout << endl;
}

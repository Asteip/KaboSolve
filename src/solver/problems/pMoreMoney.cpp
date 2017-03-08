#include "pMoreMoney.hpp"
#include <iostream>

using namespace std;

// 	SEND
// 	MORE
// MONEY
// S=x0 E=x1 N=x2 D=x3 M=x4 O=x5 R=x6 Y=x7
// rY=x8 rE=X9 rN=x10 rO=x11 rM=x12

PMoreMoney::PMoreMoney() {
	generateProblem();
}

PMoreMoney::~PMoreMoney() {}

void PMoreMoney::generateProblem() {
	int i, j;
	int *liste;
	Domain ** lDom;
	_domains = new Domain * [13];
	_n = 13;
	_m = 8;

	for (i = 0; i < 8; ++i) {
		liste = new int[9];
		for (j = 0; j < 9; ++j) {
			liste[j] = j+1;
		}
		_domains[i] = new Domain(i, 9, liste);
	}
	for (i; i < 13; ++i) {
		liste = new int[2];
		liste[0] = 0;
		liste[1] = 1;
		_domains[i] = new Domain(i, 2, liste);
	}

	// coef, mem, dom, size
	_constraints = new Constraint * [10];
	// D+E = Y
	// x3 + x1 -x7 -10*x8 = 0
	liste = new int [4];
	lDom = new Domain * [4];
	liste[0] = 1;
	liste[1] = 1;
	liste[2] = -1;
	liste[3] = -10;
	lDom[0] = _domains[3];
	lDom[1] = _domains[1];
	lDom[2] = _domains[7];
	lDom[3] = _domains[8];
	_constraints[0] = new CSupOrEqual(liste, 0, lDom, 4);
	_constraints[1] = new CInfOrEqual(liste, 0, lDom, 4);

	// N+R = E
	// x2 + x6 -x1 -10*x9 = 0
	liste = new int [4];
	lDom = new Domain * [4];
	liste[0] = 1;
	liste[1] = 1;
	liste[2] = -1;
	liste[3] = -10;
	lDom[0] = _domains[2];
	lDom[1] = _domains[6];
	lDom[2] = _domains[1];
	lDom[3] = _domains[9];
	_constraints[2] = new CSupOrEqual(liste, 0, lDom, 4);
	_constraints[3] = new CInfOrEqual(liste, 0, lDom, 4);

	// E+O = N
	// x1 + x5 -x2 -10*x10 = 0
	liste = new int [4];
	lDom = new Domain * [4];
	liste[0] = 1;
	liste[1] = 1;
	liste[2] = -1;
	liste[3] = -10;
	lDom[0] = _domains[1];
	lDom[1] = _domains[5];
	lDom[2] = _domains[2];
	lDom[3] = _domains[10];
	_constraints[4] = new CSupOrEqual(liste, 0, lDom, 4);
	_constraints[5] = new CInfOrEqual(liste, 0, lDom, 4);

	// S+M = O
	// x0 + x4 -x5 -10*x11 = 0
	liste = new int [4];
	lDom = new Domain * [4];
	liste[0] = 1;
	liste[1] = 1;
	liste[2] = -1;
	liste[3] = -10;
	lDom[0] = _domains[0];
	lDom[1] = _domains[4];
	lDom[2] = _domains[5];
	lDom[3] = _domains[11];
	_constraints[6] = new CSupOrEqual(liste, 0, lDom, 4);
	_constraints[7] = new CInfOrEqual(liste, 0, lDom, 4);

	// M = rM
	// x4 - x12 = 0
	liste = new int [2];
	lDom = new Domain * [2];
	liste[0] = 1;
	liste[1] = -1;
	lDom[0] = _domains[4];
	lDom[1] = _domains[12];
	_constraints[8] = new CSupOrEqual(liste, 0, lDom, 2);
	_constraints[9] = new CInfOrEqual(liste, 0, lDom, 2);




	/*for (int k = 0; k < _n; ++k) {
		_domains[k]->affichage();
		cout << endl << endl;
	 }*/

// 	SEND
// 	MORE
// MONEY
// S=x0 E=x1 N=x2 D=x3 M=x4 O=x5 R=x6 Y=x7
// rY=x8 rE=X9 rN=x10 rO=x11 rM=x12
}
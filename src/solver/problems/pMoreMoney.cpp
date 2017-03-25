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

/*void PMoreMoney::applyConstraint(int id){	// méthode optimale ?
	for(int i = 0 ; i < _m ; ++i){
		_constraints[i]->applyConstraint(id);
	}
}*/

void PMoreMoney::generateProblem() {
	int i, j;
	int *liste;
	Domain **lDom;
	_domains = new Domain * [12];
	_n = 12;
	_m = 6;
	//_m = 1;

	for (i = 0; i < 8; ++i) {
		liste = new int[10];
		for (j = 0; j < 10; ++j) {
			liste[j] = j;
		}
		_domains[i] = new Domain(i, 10, liste);
	}
	for (i; i < 12; ++i) {
		liste = new int[2];
		liste[0] = 0;
		liste[1] = 1;
		_domains[i] = new Domain(i, 2, liste);
	}

	// coef, mem, dom, size
	_constraints = new Constraint * [11];
	// D+E = Y+10*rY
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
	_constraints[0] = new CEqual(liste, 0, lDom, 4);

	// N+R = E
	// x2 + x6 +x8 -x1 -10*x9 = 0
	liste = new int [5];
	lDom = new Domain * [5];
	liste[0] = 1;
	liste[1] = 1;
	liste[2] = 1;
	liste[3] = -1;
	liste[4] = -10;
	lDom[0] = _domains[2];
	lDom[1] = _domains[6];
	lDom[2] = _domains[8];
	lDom[3] = _domains[1];
	lDom[4] = _domains[9];
	_constraints[1] = new CEqual(liste, 0, lDom, 5);

	// E+O = N
	// x1 + x5 +x9 -x2 -10*x10 = 0
	lDom = new Domain * [5];
	lDom[0] = _domains[1];
	lDom[1] = _domains[5];
	lDom[2] = _domains[9];
	lDom[3] = _domains[2];
	lDom[4] = _domains[10];
	_constraints[2] = new CEqual(liste, 0, lDom, 5);

	// S+M = O
	// x0 + x4 +x10 -x5 -10*x11 = 0
	lDom = new Domain * [5];
	lDom[0] = _domains[0];
	lDom[1] = _domains[4];
	lDom[2] = _domains[10];
	lDom[3] = _domains[5];
	lDom[4] = _domains[11];
	_constraints[3] = new CEqual(liste, 0, lDom, 5);

	// M = rO
	// x4 - x11 = 0
	liste = new int [2];
	lDom = new Domain * [2];
	liste[0] = 1;
	liste[1] = -1;
	lDom[0] = _domains[4];
	lDom[1] = _domains[11];
	_constraints[4] = new CEqual(liste, 0, lDom, 2);



	lDom = new Domain * [8];
	for (int i = 0; i < 8; ++i) {
		lDom[i] = _domains[i];
	}
	_constraints[5] = new CAllDiff(lDom, 8);



// 	SEND
// 	MORE
// MONEY
// S=x0 E=x1 N=x2 D=x3 M=x4 O=x5 R=x6 Y=x7
// rY=x8 rE=X9 rN=x10 rO=x11 rM=x12
}

void PMoreMoney::afficher() {

			cout << " "
 			<< _domains[11]->getValue()
 			<< _domains[10]->getValue()
 			<< _domains[9]->getValue()
 			<< _domains[8]->getValue()
 			<< endl;

 			cout << "  "
 			<< _domains[0]->getValue()
 			<< _domains[1]->getValue()
 			<< _domains[2]->getValue()
 			<< _domains[3]->getValue()
 			<< endl;

 			cout << "+ "
 			<< _domains[4]->getValue()
 			<< _domains[5]->getValue()
 			<< _domains[6]->getValue()
 			<< _domains[1]->getValue()
 			<< endl;

 			cout << "------" << endl;

 			cout << " "
 			<< _domains[4]->getValue()
 			<< _domains[5]->getValue()
 			<< _domains[2]->getValue()
 			<< _domains[1]->getValue()
 			<< _domains[7]->getValue()
 			<< endl;
}
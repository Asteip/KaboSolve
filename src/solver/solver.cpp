#include "solver.hpp"
#include "domain.hpp"
#include "constraint.hpp"

#include <iostream>

using namespace std;

Solver::Solver (Problem *p) {
	_n = p->getN();
}

void Solver::solve() {
	
}

// void Solver::solve() {
// 	bool fini = false;
// 	int i = 0;
// 	int j;
// 	Domain *d;
// 	int id;

// 	/*for (int k = 0; k < _n; ++k) {
// 		cout << k << ": ";
// 		_domains[k]->affichageNQueen();
// 	}*/











// 	while ((i >= 0) && (i < _n)) {
// //														cout << endl << "NOUVELLE ITERATION : " << i << endl;
// 		d = _domains[i];
// 		id = d->getId();

// 		if (d->getIsSet()) {
// //														cout << "is already set" << endl;
// //														cout << "on backtrack" << endl;
// 			for (j = i+1; j < _n; ++j) {
// //				cout << "j=" << j << endl;
// //				cout << "id=" << id << endl;
// 				_domains[j]->backtrack(id);
// 			}
// /*														for (int k = 0; k < _n; ++k) {
// 															cout << k << ": ";
// 															_domains[k]->affichageNQueen();
// 														}
// */			if (d->getSize() > 0) {
// 				d->fixer();
// /*														cout << "est fixé à " << d->getValue() << endl;
// 														for (int k = 0; k < _n; ++k) {
// 															cout << k << ": ";
// 															_domains[k]->affichageNQueen();
// 														}

// 														cout << "on applique la première contrainte" << endl;
// */				_constraints[0]->applyConstraint(id);
// /*														for (int k = 0; k < _n; ++k) {
// 															cout << k << ": ";
// 															_domains[k]->affichageNQueen();
// 														}
// 														cout << "on applique la seconde contrainte" << endl;
// */				_constraints[1]->applyConstraint(id);
// /*														for (int k = 0; k < _n; ++k) {
// 															cout << k << ": ";
// 															_domains[k]->affichageNQueen();
// 														}
// */				++i;
// 			} else {
// 														cout << "le domaine est vide" << endl;
// 														cout << "on reset le domaine" << endl;
// 				d->reset();
// /*														for (int k = 0; k < _n; ++k) {
// 															cout << k << ": ";
// 															_domains[k]->affichageNQueen();
// 														}
// */				--i;
// 			}
// 		} else {
// //														cout << "isn't set" << endl;
// 			if (d->getSize() > 0) {
// 				d->fixer();
// /*														cout << "est fixé à " << d->getValue() << endl;
// 														for (int k = 0; k < _n; ++k) {
// 															cout << k << ": ";
// 															_domains[k]->affichageNQueen();
// 														}
// 														cout << "on applique la première contrainte" << endl;
// */				_constraints[0]->applyConstraint(id);
// /*														for (int k = 0; k < _n; ++k) {
// 															cout << k << ": ";
// 															_domains[k]->affichageNQueen();
// 														}
// 														cout << "on applique la seconde contrainte" << endl;
// */				_constraints[1]->applyConstraint(id);
// /*														for (int k = 0; k < _n; ++k) {
// 															cout << k << ": ";
// 															_domains[k]->affichageNQueen();
// 														}
// */				++i;
// 			} else {
// //														cout << "le domaine est vide" << endl;
// 				--i;
// 			}
// 		}



















// 		/*for (int k = 0; k < _n; ++k) {
// 			cout << k << ": ";
// 			_domains[k]->affichageNQueen();
// 		}*/
// 	}



// 	if (i > 0) {
// 		cout << endl << endl;
// 		/*for (int k = 0; k < _n; ++k) {
// 			cout << k << ": ";
// 			_domains[k]->affichageNQueen();
// 		}*/
// 		/*	cout << endl << endl;
// 			for (int k = 0; k < _n; ++k) {
// 				cout << k << ": " << _domains[k]->getValue() << endl;
// 			}*/
// 		for (int k = 0; k < _n; ++k) {
// 			cout << k << ":\t";
// 			_domains[k]->affichageResultatNQueen();
// 		}
// 	} else {
// 		cout << "PAS DE SOLUTION" << endl;
// 	}
// }
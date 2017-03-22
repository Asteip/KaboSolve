#include "solver.hpp"
#include "domain.hpp"
#include "constraint.hpp"

#include "constraints/cInfOrEqual.hpp"
#include "constraints/cSupOrEqual.hpp"

#include <string>
#include <iostream>

using namespace std;

Solver::Solver (Problem *p) {
	_p = p;
	_n = p->getN();
	_domains = new Domain * [_n];
}

void Solver::solve() {
	int j, i = 0;
	int id;
	bool chercher = true;
	string entree;
	Domain *d = _p->getBestDomain();
	id = d->getId();

	_p->applyConstraint(-2);
 	while (chercher) {
		while ((i != -1) && (i < _n)) {
			if (d->getIsSet()) {
				_p->backtrack(id);
				if (d->getSize() > 0) {
					d->fixer();
					_p->applyConstraint(id);
					++i;
					if (i < _n) {
						d = _p->getBestDomain();
						id = d->getId();
					}
				} else {
					d->reset();
					--i;
					if (i >= 0) {
						d = _domains[i];
						id = d->getId();
					}
				}
			} else {
				if (d->getSize() > 0) {
					d->fixer();
					_domains[i] = d;
					_p->applyConstraint(id);
					++i;
					if (i < _n) {
						d = _p->getBestDomain();
						id = d->getId();
					}
				} else {
					--i;
					if (i >= 0) {
						d = _domains[i];
						id = d->getId();
					}
				}
			}
		}

		if (i != -1) {
			_p->afficher();
 			//cout << endl;
	 		cout << endl << "Trouver une autre solution ? o/n : ";
	 		cin >> entree;
	 		chercher = ((entree == "o") || (entree == "O"));
	 		--i;
	 	} else {
	 		cout << "Pas de solution" << endl;
	 		chercher = false;
	 	}
 	}
}

void Solver::solveAll() {
	int nbSol = 0;
	int j, i = 0;
	int id;
	Domain *d = _p->getBestDomain();
	id = d->getId();

	_p->applyConstraint(-2);
	while (i != -1) {
		while ((i != -1) && (i < _n)) {
			if (d->getIsSet()) {
				_p->backtrack(id);
					if (d->getSize() > 0) {
					d->fixer();
					_p->applyConstraint(id);
					++i;
					if (i < _n) {
						d = _p->getBestDomain();
						id = d->getId();
					}
				} else {
					d->reset();
					--i;
					if (i >= 0) {
						d = _domains[i];
						id = d->getId();
					}
				}
			} else {
				if (d->getSize() > 0) {
					d->fixer();
					_domains[i] = d;
					_p->applyConstraint(id);
					++i;
					if (i < _n) {
						d = _p->getBestDomain();
						id = d->getId();
					}
				} else {
					--i;
					if (i >= 0) {
						d = _domains[i];
						id = d->getId();
					}
				}
			}
		}

		if (i != -1) {
			/*_p->afficher();
			cout << endl;*/
			++nbSol;
			--i;
		} else {
			cout << "Nombre de solution : " << nbSol << endl;
		}
	}
}
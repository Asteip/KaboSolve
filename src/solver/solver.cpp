#include "solver.hpp"
#include "domain.hpp"
#include "constraint.hpp"

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
	Domain *d = _p->getBestDomain();
	id = d->getId();


	Domain **dAffich = _p->getDomains();
	/*for (int k = 0; k < _n; ++k) {
 		cout << k << ": ";
 		dAffich[k]->affichageNQueen();
 	}
 	cout << endl;*/



	while ((i >= 0) && (i < _n)) {
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
				if (i > 0) {
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
				if (i > 0) {
					d = _domains[i];
					id = d->getId();
				}
			}
		}





		/*for (int k = 0; k < _n; ++k) {
	 		cout << k << ": ";
	 		dAffich[k]->affichageNQueen();
 		}
 		cout << endl;*/
	}



	for (int k = 0; k < _n; ++k) {
 		cout << k << ": ";
 		dAffich[k]->affichageResultatNQueen();
 	}
}
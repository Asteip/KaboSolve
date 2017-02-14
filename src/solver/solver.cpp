#include "solver.hpp"
#include "domain.hpp"
#include "constraint.hpp"
#include "constraints/cAllDiff.hpp"
#include "constraints/cNQueen.hpp"

#include <iostream>

using namespace std;

Solver::Solver (Domain **domains, int n, Constraint **constraints, int m) {
	_n = n;
	_m = m;
	_domains = domains;
	_constraints = constraints;
}

void Solver::solve() {
	bool fini = false;
	int i = 0;
	int j;
	Domain *d;
	int id;

	for (int k = 0; k < _n; ++k) {
		cout << k << ": ";
		_domains[k]->affichageNQueen();
	}











	while ((i >= 0) && (i < _n)) {
		d = _domains[i];
		id = d->getId();

		if (d->getIsSet()) {
														cout << i << " is set" << endl;
			for (j = i+1; j < _n; ++j) {
				_domains[j]->backtrack(id);
			}
			if (d->getSize() > 0) {
				d->fixer();
														cout << i << " est fixé à " << d->getValue() << endl;
				_constraints[0]->applyConstraint(id);
				_constraints[1]->applyConstraint(id);
				++i;
			} else {									cout << i << " est vide" << endl;
				d->reset();
				--i;
			}
		} else {
			if (d->getSize() > 0) {
				d->fixer();
														cout << i << " est fixé à " << d->getValue() << endl;
				_constraints[0]->applyConstraint(id);
				_constraints[1]->applyConstraint(id);
				++i;
			} else {
														cout << i << " est vide" << endl;
				--i;
			}
		}



















		for (int k = 0; k < _n; ++k) {
			cout << k << ": ";
			_domains[k]->affichageNQueen();
		}
	}



	if (i > 0) {
		for (i = 0; i < _n; ++i) {
			cout << i << ": " << _domains[i]->getValue() << endl;
		}
	} else {
		cout << "PAS DE SOLUTION" << endl;
	}
}
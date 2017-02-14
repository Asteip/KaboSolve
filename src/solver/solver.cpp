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

	for (int k = i; k < _n; ++k) {
		cout << k << ": ";
		_domains[k]->affichageNQueen();
	}
	while (!fini && (i > -1)) {
		if (_domains[i]->getSize() > 0) {
			_domains[i]->fixer();
			cout << "val=" << _domains[i]->getValue() << endl;
			_constraints[0]->applyConstraint(_domains[i]->getId());
			_constraints[1]->applyConstraint(_domains[i]->getId());
			++i;
		} else {
			_domains[i]->reset();
			for (j = i+1; j < _n; ++j) {
				_domains[j]->backtrack(_domains[i]->getId());
			}
			--i;
		}

		fini = (i == _n);


		for (int k = i; k < _n; ++k) {
			cout << k << ": ";
			_domains[k]->affichageNQueen();
		}
	}



	if (fini) {
		for (i = 0; i < _n; ++i) {
			cout << i << ": " << _domains[i]->getValue() << endl;
		}
	} else {
		cout << "PAS DE SOLUTION" << endl;
	}
}
#include "pNQueen.hpp"

void PNQueen::generateProblem() {
	_domains = new Domain * [_n];

	for (int i = 0 ; i < _n ; ++i){
		int line[_n];
		for (int j = 0 ; j < _n ; ++j){
			line[j] = j;
		}
		_domains[i] = new Domain(i, _n, &line);
	}

	// Create the constraints
	_m = 2;
	_constraints = new Constraint * [2];

	_constraints[0] = new cNQueen(_domains, _n);
	_constraints[1] = new cAllDiff(_domains, _n);
}

PNQueen::PNQueen(int n){

	// Create the domains
	_n = n;
	generateProblem();
}

PNQueen::~PNQueen() {}

Domains * PNQueen::getMinDomain(){
	Domain * res = _domains[0];
	int i = 1;
	int min = res->getSize();

	while ((min > 0) && (i < _n)) {
		if (_domains[i]->getSize() < min) {
			res = _domains[i];
			min = res->getSize();
		}
		++i;
	}

	return res;
}
#include "pNQueen.hpp"

PNQueen::PNQueen(int n){
	_n = n;
	generateProblem();
}

PNQueen::~PNQueen() {}

void PNQueen::generateProblem() {
	// Create the domains
	_domains = new Domain * [_n];
	int *line;

	for (int i = 0 ; i < _n ; ++i){
		line = new int [_n];
		for (int j = 0 ; j < _n ; ++j){
			line[j] = j;
		}
		_domains[i] = new Domain(i, _n, line);
	}

	// Create the constraints
	_m = 2;
	_constraints = new Constraint * [2];

	_constraints[0] = new CNQueen(_domains, _n);
	_constraints[1] = new CAllDiff(_domains, _n);
}

void PNQueen::applyConstraint(int id) {
	for(int i = 0 ; i < _n ; ++i){
		_domains[i]->backtrack(id);
	}
}
#include "pNQueen.hpp"

PNQueen::PNQueen(int n){

	// Create the domains
	_n = n;
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
	_constraints = new Constraint * [_m];

	_constraints[0] = new cNQueen(_domains, _n);
	_constraints[1] = new cAllDiff(_domains, _n);
}

PNQueen::~PNQueen(){}

Domains * PNQueen::getMinDomain(){
	Domain * res = _domains[0];

	for(int i = 1 ; i < _n ; ++i){
		if(_domains[i]->getSize() < res->getSize()) res = _domains[i];
		if(res->getSize() == 0) break;
	}

	return res;
}
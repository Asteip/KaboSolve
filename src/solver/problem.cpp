#include "problem.hpp"

Problem::Problem(){}

Problem::~Problem(){
	for (int i = 0 ; i < _n ; ++i){
		delete _domains[i];
	}

	for (int i = 0 ; i < _m ; ++i){
		delete _constraints[i];
	}

	delete _domains;
	delete _constraints;
}

Domain *Problem::getBestDomain() {
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

void Problem::applyConstraint(int id){
	for(int i = 0 ; i < _m ; ++i){
		_constraints[i]->applyConstraint(id);
	}
}

void Problem::backtrack(int id){
	for(int i = 0 ; i < _n < ++i){
		_domains[i]->backtrack(int id);
	}
}

int Problem::getN(){
	return _n;
}

Domain ** Problem::getDomains(){
	return _domains;
}

int Problem::getM(){
	return _m;
}

Constraint ** Problem::getConstraints(){
	return _constraints;
}
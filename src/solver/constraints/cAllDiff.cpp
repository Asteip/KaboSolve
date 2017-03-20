#include "cAllDiff.hpp"

#include <iostream>
using namespace std;

CAllDiff::CAllDiff(Domain **domains, int size) : Constraint(domains, size){
}

CAllDiff::~CAllDiff(){
}

bool CAllDiff::applyConstraint(int id) {
	int t;
	bool modification = false;

	int k = 0;
	while ((k < _size) && (_domains[k]->getId() != id)) {
		++k;
	}
	if (k < _size) {
		t = _domains[k]->getValue();

		for (int i = 0 ; i < _size ; ++i) {
			if (!_domains[i]->getIsSet()) {
				modification = _domains[i]->prunerValeur(id, t) || modification;
			}
		}
	}

	return modification;
}

void CAllDiff::display() {}
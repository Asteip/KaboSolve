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

	t = _domains[id]->getValue();

	for (int i = 0 ; i < _size ; ++i) {
		if (!_domains[i]->getIsSet()) {
			modification = modification || _domains[i]->prunerValeur(id, t);
		}
	}

	return modification;
}

void CAllDiff::display() {}
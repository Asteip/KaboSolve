#include "cAllDiff.hpp"

#include <iostream>
using namespace std;

CAllDiff::CAllDiff(Domain **domains, int size) : Constraint(domains, size){
}

CAllDiff::~CAllDiff(){
}

void CAllDiff::applyConstraint(int id) {
	int t;
	int i = 0;

	while (_domains[i]->getId() != id) {
		++i;
	}
	t = _domains[i]->getValue();

	for (int i = 0 ; i < _size ; ++i) {
		//cout << "i=" << i << endl;
		if (!_domains[i]->getIsSet()) {
			//cout << "prunage" << endl;
			_domains[i]->prunerValeur(id, t);
		}
	}
}

void CAllDiff::display() {}
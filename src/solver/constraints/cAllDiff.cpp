#include "cAllDiff.hpp"

CAllDiff::CAllDiff(int *coefficients, int rightMember, Domain **domains, int size) : Constraint(coefficients, rightMember, domains, size){
}

CAllDiff::~CAllDiff(){
}

void CAllDiff::applyConstraint(int id){
	int t = 0;

	for (int i = 0 ; i < _size ; ++i){
		if(_domains[i]->getId() == id){
			t = _domains[i]->getValue();
		}
	}

	for(int i = 0 ; i < _size ; ++i){
		if(!_domains[i]->getIsSet()){
			_domains[i]->prunerValeur(id, t);
		}
	}
}
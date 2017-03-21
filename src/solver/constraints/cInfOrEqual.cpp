#include "cInfOrEqual.hpp"

#include <iostream>

using namespace std;

CInfOrEqual::CInfOrEqual(int *coefficients, int rightMember, Domain **domains, int size) : Constraint(domains, size){
	_coefficients = coefficients;
	_rightMember = rightMember;
}

CInfOrEqual::~CInfOrEqual(){}

bool CInfOrEqual::applyConstraint(int id){
	int t;
	double td = 0.0;
	double coef;
	bool modification = false;

	double somme = _rightMember;
	for(int i = 0; i < _size; ++i) {
		coef = _coefficients[i];
		if (_domains[i]->getIsSet()) {
			somme -= coef*_domains[i]->getValue();
		} else if (coef > 0) {
			somme -= coef*_domains[i]->getMin();
		} else {
			somme -= coef*_domains[i]->getMax();
		}
	}

	for (int i = 0; i < _size; ++i) {
		if (!_domains[i]->getIsSet()) {
			coef = _coefficients[i];
			if (coef > 0) {
				t = somme + coef*_domains[i]->getMin();
			} else {
				t = somme + coef*_domains[i]->getMax();
			}
			td = t;
			t /= _coefficients[i];
			td /= _coefficients[i];

			if (td < 0) {
				--t;
			}

			if (t == td) {
				if (_coefficients[i] > 0) {
					modification = _domains[i]->prunerSup(id, t+1) || modification;
				} else {
					modification = _domains[i]->prunerInf(id, t-1) || modification;
				}
			} else {
				if (_coefficients[i] > 0) {
					modification = _domains[i]->prunerSup(id, t+1) || modification;
				} else {
					modification = _domains[i]->prunerInf(id, t) || modification;
				}
			}
		}
	}

	return modification;
}

/*bool CInfOrEqual::applyConstraint(int id){
	double td = 0.0;
	double coef;
	bool modification = false;

	for(int i = 0; i < _size; ++i) {
		int t  = _rightMember;
		if (!_domains[i]->getIsSet()) {
			for(int j = 0; j < _size; ++j) {
				if (i!=j) {
					coef = _coefficients[j];
					if(_domains[j]->getIsSet()) {
						t -= coef*_domains[j]->getValue();
					} else if (coef > 0) {
						t -= coef*_domains[j]->getMin();
					} else {
						t -= coef*_domains[j]->getMax();
					}
				}
			}
			td = t;
			t /= _coefficients[i];
			td /= _coefficients[i];

			if (td < 0) {
				--t;
			}

			if (t == td) {
				if (_coefficients[i] > 0) {
					modification = _domains[i]->prunerSup(id, t+1) || modification;
				} else {
					modification = _domains[i]->prunerInf(id, t-1) || modification;
				}
			} else {
				if (_coefficients[i] > 0) {
					modification = _domains[i]->prunerSup(id, t+1) || modification;
				} else {
					modification = _domains[i]->prunerInf(id, t) || modification;
				}
			}
		}
	}

	return modification;
}*/

void CInfOrEqual::display() {
	cout << "size=" << _size << endl;
	cout << "rightMember=" << _rightMember << endl;
	cout << endl << "contrainte : ";
	for (int i = 0; i < _size; ++i) {
		cout << _coefficients[i] << "*X" << _domains[i]->getId() << " + ";
	}
	cout << " <= " << _rightMember << endl;
}
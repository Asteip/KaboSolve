#include "cEqual.hpp"

#include <iostream>

using namespace std;

CEqual::CEqual(int *coefficients, int rightMember, Domain **domains, int size) : Constraint(domains, size){
	_coefficients = coefficients;
	_rightMember = rightMember;
}

CEqual::~CEqual(){}

bool CEqual::applyConstraint(int id) {
	int tIOE, tSOE;
	double tdIOE, tdSOE;
	double coef;
	bool modification = false;

	double sommeIOE = _rightMember;
	double sommeSOE = _rightMember;

	for(int i = 0; i < _size; ++i) {
		coef = _coefficients[i];
		if (_domains[i]->getIsSet()) {
			sommeSOE -= coef*_domains[i]->getValue();
			sommeIOE -= coef*_domains[i]->getValue();
		} else if (coef > 0) {
			sommeSOE -= coef*_domains[i]->getMax();
			sommeIOE -= coef*_domains[i]->getMin();
		} else {
			sommeSOE -= coef*_domains[i]->getMin();
			sommeIOE -= coef*_domains[i]->getMax();
		}
	}

	for (int i = 0; i < _size; ++i) {
		if (!_domains[i]->getIsSet()) {
			coef = _coefficients[i];
			if (coef > 0) {
				tSOE = sommeSOE + coef*_domains[i]->getMax();
				tIOE = sommeIOE + coef*_domains[i]->getMin();
			} else {
				tSOE = sommeSOE + coef*_domains[i]->getMin();
				tIOE = sommeIOE + coef*_domains[i]->getMax();
			}
			tdSOE = tSOE;
			tSOE /= _coefficients[i];
			tdSOE /= _coefficients[i];

			tdIOE = tIOE;
			tIOE /= _coefficients[i];
			tdIOE /= _coefficients[i];

			if (tdIOE < 0) {
				--tIOE;
			}
			if (tdSOE < 0) {
				--tSOE;
			}

			if (tSOE == tdSOE) {
				if (_coefficients[i] > 0) {
					modification = _domains[i]->prunerInf(id, tSOE-1) || modification;
				} else {
					modification = _domains[i]->prunerSup(id, tSOE+1) || modification;
				}
			} else {
				if (_coefficients[i] > 0) {
					modification = _domains[i]->prunerInf(id, tSOE) || modification;
				} else {
					modification = _domains[i]->prunerSup(id, tSOE+1) || modification;
				}
			}

			if (tIOE == tdIOE) {
				if (_coefficients[i] > 0) {
					modification = _domains[i]->prunerSup(id, tIOE+1) || modification;
				} else {
					modification = _domains[i]->prunerInf(id, tIOE-1) || modification;
				}
			} else {
				if (_coefficients[i] > 0) {
					modification = _domains[i]->prunerSup(id, tIOE+1) || modification;
				} else {
					modification = _domains[i]->prunerInf(id, tIOE) || modification;
				}
			}
		}
	}

	return modification;
}

void CEqual::display() {
	cout << "size=" << _size << endl;
	cout << "rightMember=" << _rightMember << endl;
	cout << endl << "contrainte : ";
	for (int i = 0; i < _size; ++i) {
		cout << _coefficients[i] << "*X" << _domains[i]->getId() << " + ";
	}
	cout << " <= " << _rightMember << endl;
}
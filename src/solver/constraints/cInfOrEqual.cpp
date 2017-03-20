#include "cInfOrEqual.hpp"

#include <iostream>

using namespace std;

CInfOrEqual::CInfOrEqual(int *coefficients, int rightMember, Domain **domains, int size) : Constraint(domains, size){
	_coefficients = coefficients;
	_rightMember = rightMember;
}

CInfOrEqual::~CInfOrEqual(){}

bool CInfOrEqual::applyConstraint(int id){
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
			//cout << "ICI t=" << t << endl;
			td = t;
			t /= _coefficients[i];
			td /= _coefficients[i];

			/*cout << "t=" << t << endl;
			cout << "td=" << td << endl;*/


			if (t == td) {
				if (_coefficients[i] > 0) {
					modification = modification || _domains[i]->prunerSup(id, t+1);
				} else {
					modification = modification || _domains[i]->prunerInf(id, t-1);
				}
			} else {
				if (_coefficients[i] > 0) {
					modification = modification || _domains[i]->prunerSup(id, t+1);
				} else {
					modification = modification || _domains[i]->prunerInf(id, t);
				}
			}



			/*} else {
				cout << "prunage <= " << _domains[i]->getId() << endl;
				std::cout << "t=" << t << std::endl << endl;
				_domains[i]->prunerSup(id, t);
			}*/
		}
	}

	return modification;
}

void CInfOrEqual::display() {
	cout << "size=" << _size << endl;
	cout << "rightMember=" << _rightMember << endl;
	cout << endl << "contrainte : ";
	for (int i = 0; i < _size; ++i) {
		cout << _coefficients[i] << "*X" << _domains[i]->getId() << " + ";
	}
	cout << " <= " << _rightMember << endl;
}
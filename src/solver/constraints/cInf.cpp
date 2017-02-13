#include "cInf.hpp"

CInf::CInf(int *coefficients, int rightMember, Domain **domains, int size) : Constraint(domains, size){
	_coefficients = coefficients;
	_rightMember = rightMember;
}

CInf::~CInf(){
}

void CInf::applyConstraint(int id){
	double td = 0.0;

	for(int i = 0; i < _size; ++i) {
		int t  = _rightMember;
		if (!_domains[i]->getIsSet()) {
			for(int j = 0; j < _size; ++j) {
				if (i!=j) {
					if(_domains[j]->getIsSet()) {
						t += -_coefficients[j]*_domains[j]->getValue();
					} else {
						t += -_coefficients[j]*_domains[j]->getMin();
					}
				}
			}
			td = t;
			t /= _coefficients[i];
			td /= _coefficients[i];
			std::cout << "t=" << t << std::endl;

			if (t == td) {
				_domains[i]->prunerSup(id, t+1);
			} else {
				_domains[i]->prunerSup(id, t+1);
			}
		}
	}
}
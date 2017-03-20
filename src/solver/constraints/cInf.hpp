#ifndef C_INF
#define C_INF

#include "../constraint.hpp"

class CInf : public Constraint{

public:
	CInf(int *coefficients, int rightMember, Domain **domains, int size);
	~CInf();

	virtual bool applyConstraint(int id);
	
private:
	int *_coefficients;
	int _rightMember;

};

#endif
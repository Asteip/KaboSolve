#ifndef C_INF_OR_EQUAL
#define C_INF_OR_EQUAL

#include "../constraint.hpp"

class CInfOrEqual : public Constraint{

public:
	CInfOrEqual(int *coefficients, int rightMember, Domain **domains, int size);
	~CInfOrEqual();

	virtual void applyConstraint(int id);
};

#endif
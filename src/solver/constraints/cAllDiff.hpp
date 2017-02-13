#ifndef C_ALL_DIFF
#define C_ALL_DIFF

#include "../constraint.hpp"

class CAllDiff : public Constraint{

public:
	CAllDiff(int *coefficients, int rightMember, Domain **domains, int size);
	~CAllDiff();

	virtual void applyConstraint(int id);
};

#endif
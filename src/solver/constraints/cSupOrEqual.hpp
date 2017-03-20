#ifndef C_SUP_OR_EQUAL
#define C_SUP_OR_EQUAL

#include "../constraint.hpp"

class CSupOrEqual : public Constraint {

public:
	CSupOrEqual(int *coefficients, int rightMember, Domain **domains, int size);
	~CSupOrEqual();

	void display();
	virtual bool applyConstraint(int id);

private:
	int *_coefficients;
	int _rightMember;
};

#endif
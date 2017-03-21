#ifndef C_EQUAL
#define C_EQUAL

#include "../constraint.hpp"

class CEqual : public Constraint {

public:
	CEqual(int *coefficients, int rightMember, Domain **domains, int size);
	~CEqual();

	void display();
	virtual bool applyConstraint(int id);

private:
	int *_coefficients;
	int _rightMember;
};

#endif
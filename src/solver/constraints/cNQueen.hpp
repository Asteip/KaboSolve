#ifndef C_N_QUEEN
#define C_N_QUEEN

#include "../constraint.hpp"

class CNQueen : public Constraint{

public:
	CNQueen(Domain **domains, int size);
	~CNQueen();

	virtual void applyConstraint(int id);
};

#endif //C_N_QUEEN
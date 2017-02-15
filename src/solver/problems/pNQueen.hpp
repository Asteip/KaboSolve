#ifndef P_N_QUEEN_HPP
#define P_N_QUEEN_HPP

#include "../problem.hpp"

class PNQueen : public Problem {

public:
	PNQueen(int n);
	~PNQueen();

	Domain * getMinDomain();

private:
	void generateProblem();
};

#endif
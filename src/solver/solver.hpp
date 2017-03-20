#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "domain.hpp"
#include "constraint.hpp"
#include "constraints/cAllDiff.hpp"
#include "constraints/cNQueen.hpp"
#include "problem.hpp"

class Solver{

public:
	Solver (Problem *p);
	void solve();
	void solveAll();
	void test();

private:
	Problem *_p;
	int _n;
	Domain **_domains;
};

#endif
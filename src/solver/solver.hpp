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

private:
	int _n;
	int _m;
	Domain **_domains;
	Constraint **_constraints;
};

#endif
#ifndef P_N_QUEEN_HPP
#define P_N_QUEEN_HPP

#include "../problem.hpp"
#include "../constraint.hpp"
#include "../constraints/cNQueen.hpp"
#include "../constraints/cAllDiff.hpp"
#include "../constraints/cInfOrEqual.hpp"

class PNQueen : public Problem {

	public:
		PNQueen(int n);
		~PNQueen();

		void applyConstraint(int id);
		void afficher();

	private:
		void generateProblem();
};

#endif
#ifndef P_MORE_MONEY_HPP
#define P_MORE_MONEY_HPP

#include "../problem.hpp"
#include "../constraint.hpp"
#include "../constraints/cEqual.hpp"
#include "../constraints/cAllDiff.hpp"

class PMoreMoney : public Problem {

	public:
		PMoreMoney();
		~PMoreMoney();

		//void applyConstraint(int id);
		void afficher();

	private:
		void generateProblem();
};

#endif
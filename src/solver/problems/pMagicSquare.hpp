#ifndef P_MAGIC_SQUARE
#define P_MAGIC_SQUARE

#include "../problem.hpp"
#include "../constraint.hpp"
#include "../constraints/cEqual.hpp"
#include "../constraints/cAllDiff.hpp"

class PMagicSquare : public Problem {

	private:
		int _taille;

	public:
		PMagicSquare(int n);
		~PMagicSquare();

		void applyConstraint(int id);
		void afficher();

	private:
		void generateProblem(int n);
};

#endif
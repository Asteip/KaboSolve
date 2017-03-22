#include "solver.hpp"
#include "problem.hpp"
#include "problems/pNQueen.hpp"
#include "problems/pMoreMoney.hpp"
#include "problems/pMagicSquare.hpp"
#include "domain.hpp"
#include "constraint.hpp"
#include "constraints/cInfOrEqual.hpp"
#include "constraints/cNQueen.hpp"
#include "constraints/cAllDiff.hpp"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

int main(int argc, char **argv) {
	srand(time(NULL));
	//srand(0);
	clock_t debut, fin;

	char n_queens[] = "n-queens";
	char more_money[] = "more-money";
	char magic_square[] = "magic-square";
	char sudoku[] = "sudoku";

	if(argc < 3){
		cout << "Usage : KaboSolve <problem> <number of solutions> [<options>]" << endl;
		cout << "Valid options : " << endl;
		cout << "	problem : n-queens, more-money, magic-square, sudoku" << endl;
		cout << "	number of solutions : \"one\" (finds the first solution) or \"all\" (finds all solutions)" << endl;
		cout << "	options : additional options" << endl;
	}
	else{
		cout << "======== Starting ========" << endl << endl;

		if(strstr(argv[1], n_queens) && strlen(argv[1]) == strlen(n_queens)){

			cout << "***** N-QUEENS problem *****" << endl << endl;

			if(argc <= 3){
				cout << "Usage : KaboSolve n-queens <number of solutions> <number of queens>" << endl;
				cout << "	number of solutions : \"one\" (finds the first solution) or \"all\" (finds all solutions)" << endl;
				cout << "	number of queens : number of queens you want to run the solver on" << endl;
				cout << endl << "Example : \"KaboSolve n-queens all 5\" to find all the solution of the n-queens problem for 5 queens" << endl;
			}
			else{
				int N = atoi(argv[3]);
				
				if(N <= 0){
					cout << "ERROR : the number of queens must be an integer greater than 0" << endl;
				}
				else{
					Problem *p = new PNQueen(N);
					Solver s(p);
					
					debut = clock();

					if(strstr(argv[2], "one"))
						s.solve();
					else if(strstr(argv[2], "all"))
						s.solveAll();
					else
						cout << "ERROR : <number of solution> parameter accepts only \"one\" or \"all\" value" << endl;

					fin = clock();
					cout << endl << "Time : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl;
				}
			}

		}
		else if(strstr(argv[1], more_money) && strlen(argv[1]) == strlen(more_money)){
			cout << "***** SEND MORE MONEY problem *****" << endl << endl;
				
			Problem *p = new PMoreMoney();
			Solver s(p);

			debut = clock();

			if(strstr(argv[2], "one"))
				s.solve();
			else if(strstr(argv[2], "all"))
				s.solveAll();
			else
				cout << "ERROR : <number of solution> parameter accepts only \"one\" or \"all\" value" << endl;

			fin = clock();

			cout << endl << "Time : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl;
		}
		else if(strstr(argv[1], magic_square) && strlen(argv[1]) == strlen(magic_square)){
			cout << "***** MAGIC SQUARE problem *****" << endl << endl;

			if(argc <= 3){
				cout << "Usage : KaboSolve magic-square <number of solutions> <size of the square>" << endl;
				cout << "	number of solutions : \"one\" (finds the first solution) or \"all\" (finds all solutions)" << endl;
				cout << "	size of the square : size of the square array" << endl;
				cout << endl << "Example : \"KaboSolve magic-square all 5\" to find all the solution of the magic-square problem for a square of size 5x5" << endl;
			}
			else{
				int N = atoi(argv[3]);
				
				if(N <= 0){
					cout << "ERROR : the size of the square must be greater than 0" << endl;
				}
				else{
					PMagicSquare *p = new PMagicSquare(N);

					Solver s(p);
					debut = clock();

					if(strstr(argv[2], "one"))
						s.solve();
					else if(strstr(argv[2], "all"))
						s.solveAll();
					else
						cout << "ERROR : <number of solution> parameter accepts only \"one\" or \"all\" value" << endl;

					fin = clock();

					cout << endl << "Time : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl;
				}
			}
		}
		else if(strstr(argv[1], sudoku) && strlen(argv[1]) == strlen(sudoku)){
			cout << "***** SUDOKU problem *****" << endl << endl;
				
			/*Problem *p = new PMoreMoney();
			Solver s(p);

			debut = clock();

			if(strstr(argv[2], "one"))
				s.solve();
			else if(strstr(argv[2], "all"))
				s.solveAll();
			else
				cout << "ERROR : <number of solution> parameter accepts only \"one\" or \"all\" value" << endl;

			fin = clock();

			cout << endl << "Time : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl;*/
		}
		else{
			cout << "ERROR : the problem : " << argv[1] << " doesn't exist" << endl;
		}

		cout << endl << "======== END ========" << endl;
	}

	return 0;
}

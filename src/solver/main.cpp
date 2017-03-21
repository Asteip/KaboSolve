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

	if(argc < 3){
		cout << "Usage : KaboSolve <probleme> <choix-solver> [<options>]" << endl;
		cout << "Options valides : " << endl;
		cout << "	probleme : N-reines, more-money magic-square" << endl;
		cout << "	choix-solver : one, all" << endl;
		cout << "	options : options complémentaires" << endl;
	}
	else{
		cout << "Démarrage du solver..." << endl << endl;

		if(strstr(argv[1], "N-reines")){

			cout << "***** Problème du N-reines. *****" << endl << endl;

			if(argv[3] == NULL || strlen(argv[3]) == 0){
				cout << "Veuillez spécifier un nombre de reines." << endl;
				cout << "Exemple : \"KaboSolve N-reines one 5\" pour exécuter le problème sur 5 reines." << endl;
			}
			else{
				int N = atoi(argv[3]);
				
				if(N == 0){
					cout << "ERREUR : le nombre de reines doit être un entier" << endl;
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
						cout << "ERREUR : ce choix de solver n'existe pas." << endl;

					fin = clock();

					cout << endl << "temps : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl;
				}
			}

		}
		else if(strstr(argv[1], "more-money")){
			cout << "***** Problème du send more money. *****" << endl << endl;;
				
			Problem *p = new PMoreMoney();
			
			Solver s(p);
			debut = clock();

			if(strstr(argv[2], "one"))
				s.solve();
			else if(strstr(argv[2], "all"))
				s.solveAll();
			else
				cout << "ERREUR : ce choix de solver n'existe pas." << endl;

			fin = clock();

			cout << endl << "temps : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl;
		}
		else if(strstr(argv[1], "magic-square")){
			cout << "***** Problème du carré magique. *****" << endl << endl;

			if(argv[3] == NULL || strlen(argv[3]) == 0){
				cout << "Veuillez spécifier une taille de carré." << endl;
				cout << "Exemple : \"KaboSolve magic-square one 5\" pour exécuter le problème sur un carré de taille 5." << endl;
			}
			else{
				int N = atoi(argv[3]);
				
				if(N == 0){
					cout << "ERREUR : la taille du carré doit être un entier" << endl;
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
						cout << "ERREUR : ce choix de solver n'existe pas." << endl;

					fin = clock();

					cout << endl << "temps : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl;
				}
			}
		}
		else{
			cout << "ERREUR : Pas de problème : " << argv[1] << endl << endl;
		}

		cout << endl << "=== END ===" << endl;
	}

	return 0;
}

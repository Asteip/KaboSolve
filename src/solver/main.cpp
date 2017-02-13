#include "solver.hpp"
#include "domain.hpp"
#include "constraint.hpp"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char **argv){
	//srand(time(NULL));
	srand(271);

	cout << "Démarrage du solver..." << endl << endl;
	
	Domain **d = new Domain * [5];
	int taille;
	int **coco = new int * [5];
	for (int i = 0; i < 5; ++i) {
		taille = 3 + rand() % 7;
		coco[i] = new int [taille];
		for (int j = 0; j < taille; ++j) {
			coco[i][j] = rand() % 100;
		}
		d[i] = new Domain(i, taille, coco[i]);
	}


	cout << "ENSEMBLES DE DEPART" << endl;
	for (int j = 0; j < 5; ++j) {
		d[j]->affichage();
	}

	int *toto = new int [5];
	for (int i = 0; i < 5; ++i) {
		toto[i] = 1 + rand() % 3;
	}

	Constraint c(1, toto, 250, d, 5);

	cout << endl << endl << "CONTRAINTE" << endl;
	c.afficher();

	cout << endl << "PRUNAGE" << endl;
	c.prune(5);

	cout << endl << "ENSEMBLES APRES PRUNAGE" << endl;
	for (int j = 0; j < 5; ++j) {
		d[j]->affichage();
	}

	return 0;
}
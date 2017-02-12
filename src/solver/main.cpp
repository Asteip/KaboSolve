#include "solver.hpp"
#include "domain.hpp"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char **argv){
	//srand(time(NULL));
	srand(5);

	cout << "Démarrage du solver..." << endl << endl;
	
	int *coco = new int [10];
	for (int i = 0; i < 10; ++i) {
		coco[i] = rand() % 100;
	}

	Domain d(1, 10, coco);


	d.prunerValeur(5, 20);
	d.prunerValeur(7, 32);
	d.fixer();
	d.fixer();
	d.fixer();
	d.fixer();
	d.reset();

	d.affichage();

	d.prunerInf(8, 52);

	d.affichage();

	return 0;
}
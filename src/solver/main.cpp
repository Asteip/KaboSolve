#include <iostream>

#include "solver.hpp"
#include "problem.hpp"
#include "domain.hpp"

using namespace std;

int main(void){
	cout << "Démarrage du solver..." << endl;
	
	int *coco = new int [10];
	for (int i = 0; i < 10; ++i) {
		coco[i] = 20 - 2*i;
	}
	Domain D(10, coco);

	return 0;
}
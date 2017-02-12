#ifndef DOMAIN_HPP
#define DOMAIN_HPP

class Domain {
	private:
		int n;
		int size;
		int nbPruned;
		int min;
		int max;
		int value;
		bool isSet;

		int *possibles; // Indices des valeurs possibles du domaine
		int *pruned;	// Indices des valeurs prunées du domaine
		int *indexes;	// Identifiant de la variable qui a imposé le prunage
	
	private:
		// UTILITAIRES
		void triBulle();
		int indVal(int val);
		int indPossiblesInd(int ind);

	public:
		// CONSTRUCTEUR
		Domain(int n, int *set);

		// FIXAGE
		void fixer();

		// PRUNAGES
		void prunerValeur(int id, int val);

		// BACKTRACK
		void backtrack(int id);
		void reset();

		// ACCESSEURS
		int getN();
		int getSize();
		int getMin();
		int getMax();
		int getValue();
		bool getIsSet();
};

#endif

#ifndef DOMAIN_HPP
#define DOMAIN_HPP

class Domain {
	private:
		int n;
		int size;
		int nbPruned;
		int value;
		bool isSet;

		int *possibles; // Indices des valeurs possibles du domaine
		int *pruned;	// Indices des valeurs prunées du domaine
		int *indexes;	// Identifiant de la variable qui a imposé le prunage
	
	private:
		// UTILITAIRES
		void triBulle();
		int dichotomie(int val);
		int indVal(int val);
		int posValSupOuEgale(int val);		// Position de la plus petite valeur supérieure ou égale
		int posValInfOuEgale(int val);		// Position de la plus grande valeur inférieure ou égale

	public:
		// CONSTRUCTEUR
		Domain(int n, int *set);

		// FIXAGE
		void fixer();

		// PRUNAGES
		void prunerValeur(int id, int val);
		void prunerSup(int id, int val);
		void prunerInf(int id, int val);

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

		// AFFICHAGE DEBUG
		void affichage();
};

#endif

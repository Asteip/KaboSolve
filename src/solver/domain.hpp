#ifndef DOMAIN_HPP
#define DOMAIN_HPP

/*!
 * \brief Represent the domain of variable.
 * \details This class represents the domain of possible values of a variable,
 * values can be pruned and unpruned as will.
 */
class Domain {
	private:
		int id;
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
		void triBulle();					// A l'initialisation, trie le domaine des valeurs possibles dans l'ordre croissant
		int dichotomie(int val);			// Donne l'indice de la valeur dans le domaine des possibles (plus ou moins 1 si la valeur est absente)
		int indVal(int val);				// Donne l'indice de la valeur dans le domaine des possibles (-1 si enixstante)
		int posValSupOuEgale(int val);		// Donne l'indice de la plus petite valeur supérieure ou égale dans le domaine des possibles 
		int posValInfOuEgale(int val);		// Donne l'indice de la plus grande valeur inférieure ou égale dans le domaine des possibles

	public:
		/*!
		 * \brief Create a new instance of a domain.
		 * \param id the id of the variable.
		 * \param n the number of possible values (the size of set).
		 * \param set the possible values.
		 */
		Domain(int id, int n, int *set);

		/*!
		 * \brief Set the variable to a random actual possible value.
		 * \details Also prunes the value choosen.
		 */
		void fixer();

		/*!
		 * \brief Prunes the value val.
		 * \param id the id of the variable that activates this prune.
		 * \param val the value of the variable to prune.
		 */
		void prunerValeur(int id, int val);

		/*!
		 * \brief Prunes the values above the value val.
		 * \param id the id of the variable that activates this prune.
		 * \param val the value above which the values are pruned.
		 */
		void prunerSup(int id, int val);

		/*!
		 * \brief Prunes the values under the value val.
		 * \param id the id of the variable that activates this prune.
		 * \param val the value under which the values are pruned.
		 */
		void prunerInf(int id, int val);

		/*!
		 * \brief Unprunes the values pruned by the variable with the identifiant id.
		 * \param id the identifiant of the variable that isn't set anymore.
		 */
		void backtrack(int id);

		/*!
		 * \brief Unprunes the tested values of the domain.
		 */
		void reset();

		// ACCESSEURS
		int getId();
		int getN();
		int getSize();
		int getMin();
		int getMax();
		int getValue();
		bool getIsSet();

		// AFFICHAGE DEBUG
		void affichage();
		void affichageNQueen();
};

#endif

#ifndef DOMAIN_HPP
#define DOMAIN_HPP

/*!
 * \brief Represents the domain of a variable.
 * \details This class represents the domain of possible values of a variable,
 * values can be pruned and unpruned as will.
 */
class Domain {
	private:
		int id;			// Unique id of the domain (ie : id of the variable).
		int n;			// Number of possible values at a time t.
		int size;		// Initial number of possible values (size of the set of possible value).
		int nbPruned;	// Number of values that has been pruned.
		int value;		// Fixed value in the domain.
		bool isSet;		// True if the domain is fixed, false otherwise.

		int *possibles; // Array of the possible values in the domain.
		int *pruned;	// Array of the pruned values in the domain.
		int *indexes;	// Array of id of the variable which has enforced the pruning.
	
	private:
		/*
		 * At initialisation, sort the array of possible values in croissant order.
		 */
		void triBulle();
		
		/*
		 * Returns the index of the value "val" in the array of possible values (more or less 1 if the value doesn't exist).
		 */
		int dichotomie(int val);
		
		/*
		 * Returns the index of the value "val" in the array of possible values (-1 if the value doesn't exist).
		 */
		int indVal(int val);
		
		/*
		 * Returns the index of the lowest value greater or equal than "val" in the array of possible values.
		 */
		int posValSupOuEgale(int val);
		
		/*
		 * Returns the index of the greatest value lower or equal than "val" in the array of possible values.
		 */
		int posValInfOuEgale(int val);

	public:
		/*!
		 * \brief Creates a new instance of a domain.
		 * \param id The id of the variable.
		 * \param n The number of possible values (the size of set).
		 * \param set The possible values.
		 */
		Domain(int id, int n, int *set);

		/*!
		 * \brief Set the variable to a random actual possible value.
		 * \details Also prunes the value choosen.
		 */
		void fixer();

		/*!
		 * \brief Removes the value give in parameter from the set of possible values.
		 * \param id The id of the variable (domain) that activates this prune.
		 * \param val The value of the variable to prune.
		 * \return true if some modifications happened, false otherwise.
		 */
		bool prunerValeur(int id, int val);

		/*!
		 * \brief Removes the values greater than the value give in parameter from the set of possible values.
		 * \param id The id of the variable (domain) that activates this prune.
		 * \param val The value above which the values are pruned.
		 * \return true if some modifications happened, false otherwise.
		 */
		bool prunerSup(int id, int val);

		/*!
		 * \brief Removes the values lower than the value give in parameter from the set of possible values.
		 * \param id The id of the variable (domain) that activates this prune.
		 * \param val The value under which the values are pruned.
		 * \return true if some modifications happened, false otherwise.
		 */
		bool prunerInf(int id, int val);

		/*!
		 * \brief Undo the pruning of the values which have been pruned by the variable with the given id.
		 * \param id The identifiant of the domain responsible of the pruning, this is also the variable which was set.
		 */
		void backtrack(int id);

		/*!
		 * \brief Undo the pruning of the value pruned by the domain itself.
		 */
		void reset();

		// ACCESSEURS
		
		/*!
		 * \brief Returns the Id of the doamins.
		 * \return The Id of the domains.
		 */
		int getId();
		
		/*!
		 * \brief Returns the number of possible values at a time t.
		 * \return the number of possible values at a time t.
		 */
		int getN();
		
		/*!
		 * \brief Returns the initial number of possible values (size of the set of possible value).
		 * \return the initial number of possible values (size of the set of possible value).
		 */
		int getSize();
		
		/*!
		 * \brief Returns the minimum element of the possible values.
		 * \return The minimum element of the set of possible values.
		 */
		int getMin();
		
		/*!
		 * \brief Returns the maximum element of the possible values.
		 * \return The maximum element of the set of possible values.
		 */
		int getMax();
		
		/*!
		 * \brief Returns the fixed value of the domain if it exists.
		 * \return The fixed value of the domain, it's also the fixed value of the variable.
		 */
		int getValue();
		
		/*!
		 * \brief Returns the state of the domain.
		 * \return True if the domain is fixed, false otherwise.
		 */
		bool getIsSet();
	
		/*!
		 * \brief Set the id of the domain.
		 * \param id The new value of the id for the current domain.
		 */
		void setId(int id);
};

#endif

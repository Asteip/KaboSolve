#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <string>
#include "domain.hpp"

/*!
 * \brief Represent a variable with its name and its domain.
 * \details Represent a variable for a constraint satisfaction problem.
 * Each instance must have a unique id that identify the variable and is 
 * affected to an ordered domain.
 */

class Variable{

public:

	/*!
	 * \brief Create a new instance of a variable.
	 * \param name The name of the variable.
	 * \param id Unique identifier of a variable
	 * \param domain The domain of a variable passed by reference
	 */
	Variable(std::string name, int id, Domain &domain);

	// ACCESSOR AND MODIFIER

	/*!
	 * \brief Accessor of the variable's name.
	 * \return The name of the variable.
	 */
	std::string getName();
	
	/*!
	 * \brief Accessor of the variable's id.
	 * \return The id of the variable.
	 */
	int getId();

	/*!
	 * \brief Accessor of the variable's domain.
	 * \return The domain of the variable.
	 */
	Domain * getDomain();

	/*!
	 * \brief Modifier of the variable's name.
	 * \param name The new name of the variable.
	 */
	void setName(std::string name);
	
	/*!
	 * \brief Modifier of the variable's id.
	 * \param id The new id of the variable.
	 */
	void setId(int id);
	
	/*!
	 * \brief Modifier of the variable's domain.
	 * \param domain The new domain of the variable passed by reference.
	 */
	void setDomain(Domain &domain);

private:
	Domain * _domain;
	std::string _name;
	int _id;
};

#endif
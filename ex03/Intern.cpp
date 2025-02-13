/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:10:41 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/13 10:05:42 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//--------------------------------Constructors--------------------------------//

Intern::Intern() {
	//std::cout << "Default constructor Intern called" << std::endl << std::endl;
}

Intern::Intern(Intern const & src) {
	//std::cout << "Copy constructor Intern called" << std::endl << std::endl;
	*this = src;
}

//---------------------------------Destructor---------------------------------//

Intern::~Intern() {
	//std::cout << "Destructor Intern called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//

Intern & Intern::operator=(Intern const & rhs) {
	//std::cout << "Copy assignment operator Intern called" << std::endl << std::endl;
	(void) rhs;
	return *this;
}

//-------------------------------Member functions------------------------------//

AForm *Intern::makeForm(std::string name, std::string target) {
	ShrubberyCreationForm *scrubbery = nullptr;
	RobotomyRequestForm *robotomy = nullptr;
	PresidentialPardonForm *presidential = nullptr;
	std::string form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i;

	for (i = 0; i < 3; i++) {
		if (name == form_names[i]) {
			std::cout << "Intern creates " << name << std::endl << std::endl;
			break ;
		}
	}
	switch (i) {
		case 0:
			return (scrubbery = new ShrubberyCreationForm(target));
			break;
		case 1:
			return (robotomy = new RobotomyRequestForm(target));
			break;
		case 2:
			return (presidential = new PresidentialPardonForm (target));
			break;
		default:
			std::cout << "Form doesn't exist" << std::endl << std::endl;
	}
	return (nullptr);
}
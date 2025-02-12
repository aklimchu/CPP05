#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(void); // Canonical
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src) = delete; // Canonical
		~PresidentialPardonForm(void) = default; // Canonical

		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs) = default; // Canonical

		void pardonedByZaphod(void) const;
		//void execute(Bureaucrat const & executor) const;
};
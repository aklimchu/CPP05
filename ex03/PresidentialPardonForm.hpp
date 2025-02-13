#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(void); // Canonical
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src); // Canonical
		~PresidentialPardonForm(void) = default; // Canonical

		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs) = delete; // Canonical

		void pardonedByZaphod(void) const;
		void makeNoise(void) const;
		void createFile(void) const;
};
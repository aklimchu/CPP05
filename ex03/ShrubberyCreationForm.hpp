#pragma once

#include <iostream>
#include <fstream> // for std::ifstream
#include <iomanip> // for setw()
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(void); // Canonical
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src); // Canonical
		~ShrubberyCreationForm(void) = default; // Canonical

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs) = delete; // Canonical

		void createFile(void) const;
		void makeNoise(void) const;
		void pardonedByZaphod(void) const;
};
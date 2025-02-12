#pragma once

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(void); // Canonical
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src) = delete; // Canonical
		~RobotomyRequestForm(void) = default; // Canonical

		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs) = default; // Canonical
};
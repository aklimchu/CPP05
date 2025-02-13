#pragma once

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(void); // Canonical
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src); // Canonical
		~RobotomyRequestForm(void) = default; // Canonical

		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs) = delete; // Canonical

		void makeNoise(void) const;
		void pardonedByZaphod(void) const;
		void createFile(void) const;
};
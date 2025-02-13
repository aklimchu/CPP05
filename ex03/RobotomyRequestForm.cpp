#include "RobotomyRequestForm.hpp"

//--------------------------------Constructors--------------------------------//

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", "empty", 72, 45) {
	//std::cout << "Default constructor RobotomyRequestForm called" << std::endl << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : \
	AForm("robotomy request", target, 72, 45) {
	//std::cout << "Parametric constructor RobotomyRequestForm called" << std::endl << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): AForm(src) {
	//std::cout << "Copy constructor AForm called" << std::endl << std::endl;
}

//-------------------------------Member functions------------------------------//

void RobotomyRequestForm::makeNoise(void) const {
	std::cout << "Drrrrrrrrrrrrrrrrrrr" << std::endl;
	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully" << "\n\n";
	else
		std::cout << "Robotomy of " << this->getTarget() << " failed" << "\n\n";
}

void RobotomyRequestForm::pardonedByZaphod(void) const { }

void RobotomyRequestForm::createFile(void) const { }
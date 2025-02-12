#include "RobotomyRequestForm.hpp"

//--------------------------------Constructors--------------------------------//

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "empty", 72, 45) {
	//std::cout << "Default constructor RobotomyRequestForm called" << std::endl << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : \
	AForm("RobotomyRequestForm", target, 72, 45) {
	//std::cout << "Parametric constructor RobotomyRequestForm called" << std::endl << std::endl;
}

//---------------------------------Destructor---------------------------------//

//-------------------------Copy assignment operator---------------------------//

//-------------------------------Member functions------------------------------//

void RobotomyRequestForm::makeNoise(void) const {
	std::cout << "Drrrrrrrrrrrrrrrrrrr" << std::endl;
	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully" << "\n\n";
	else
		std::cout << "Robotomy of " << this->getTarget() << " failed" << "\n\n";
}

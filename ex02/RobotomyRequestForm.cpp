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

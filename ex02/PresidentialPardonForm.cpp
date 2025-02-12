#include "PresidentialPardonForm.hpp"

//--------------------------------Constructors--------------------------------//

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "empty", 25, 5) {
	//std::cout << "Default constructor PresidentialPardonForm called" << std::endl << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : \
	AForm("PresidentialPardonForm", target, 25, 5) {
	//std::cout << "Parametric constructor PresidentialPardonForm called" << std::endl << std::endl;
}

//---------------------------------Destructor---------------------------------//

//-------------------------Copy assignment operator---------------------------//

//-------------------------------Member functions------------------------------//

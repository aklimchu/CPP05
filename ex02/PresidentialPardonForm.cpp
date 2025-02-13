#include "PresidentialPardonForm.hpp"

//--------------------------------Constructors--------------------------------//

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "empty", 25, 5) {
	//std::cout << "Default constructor PresidentialPardonForm called" << std::endl << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : \
	AForm("PresidentialPardonForm", target, 25, 5) {
	//std::cout << "Parametric constructor PresidentialPardonForm called" << std::endl << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): AForm(src) {
	//std::cout << "Copy constructor AForm called" << std::endl << std::endl;
}

//-------------------------------Member functions------------------------------//

void PresidentialPardonForm::pardonedByZaphod(void) const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl << std::endl;
}

void PresidentialPardonForm::makeNoise(void) const { }

void PresidentialPardonForm::createFile(void) const { }

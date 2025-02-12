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

void PresidentialPardonForm::pardonedByZaphod(void) const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl << std::endl;
}

/* void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw PresidentialPardonForm::GradeTooLowException();
	if (executor.getGrade() < this->getGradeToExecute())
		throw PresidentialPardonForm::GradeTooHighException();
	if (this->getSignedStatus() == false)
		throw PresidentialPardonForm::FormNotSigned();
	this->pardonedByZaphod();
} */
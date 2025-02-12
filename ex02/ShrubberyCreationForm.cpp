#include "ShrubberyCreationForm.hpp"

//--------------------------------Constructors--------------------------------//

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "empty", 145, 137) {
	//std::cout << "Default constructor ShrubberyCreationForm called" << std::endl << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : \
	AForm("ShrubberyCreationForm", target, 145, 137) {
	//std::cout << "Parametric constructor ShrubberyCreationForm called" << std::endl << std::endl;
}

//---------------------------------Destructor---------------------------------//

//-------------------------Copy assignment operator---------------------------//

//-------------------------------Member functions------------------------------//

void ShrubberyCreationForm::createFile(void) const {
	std::ofstream output_stream;

	std::string new_file = this->getTarget() + "_shrubbery";

	output_stream.open(new_file, std::ifstream::out);

	if (!output_stream){
		std::cerr << "Can't create output file" << std::endl;
		return ;
	}
	for (int i = 0; i < 5; i++) {
		output_stream << std::setw(4) <<"*" << std::endl;
		output_stream << std::setw(3) << "***" << std::endl;
		output_stream << std::setw(2) << "*****" << std::endl;
		output_stream << std::setw(1) << "*******" << std::endl;
		output_stream << "*********" << std::endl;
		output_stream << std::setw(3) << "|||" << std::endl;
		output_stream << std::setw(3) << "|||" << std::endl << std::endl;
	}

	output_stream.close();
}

/* void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw ShrubberyCreationForm::GradeTooLowException();
	if (executor.getGrade() < this->getGradeToExecute())
		throw ShrubberyCreationForm::GradeTooHighException();
	if (this->getSignedStatus() == false)
		throw ShrubberyCreationForm::FormNotSigned();
	this->createFile();
} */
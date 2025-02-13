#include "ShrubberyCreationForm.hpp"

//--------------------------------Constructors--------------------------------//

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", "empty", 145, 137) {
	//std::cout << "Default constructor ShrubberyCreationForm called" << std::endl << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : \
	AForm("shrubbery creation", target, 145, 137) {
	//std::cout << "Parametric constructor ShrubberyCreationForm called" << std::endl << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src): AForm(src) {
	//std::cout << "Copy constructor AForm called" << std::endl << std::endl;
}

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
		output_stream << std::setw(5) <<"*" << std::endl;
		output_stream << std::setw(6) << "***" << std::endl;
		output_stream << std::setw(7) << "*****" << std::endl;
		output_stream << std::setw(8) << "*******" << std::endl;
		output_stream << "*********" << std::endl;
		output_stream << std::setw(6) << "|||" << std::endl;
		output_stream << std::setw(6) << "|||" << std::endl << std::endl;
	}

	output_stream.close();
}

void ShrubberyCreationForm::makeNoise(void) const { }

void ShrubberyCreationForm::pardonedByZaphod(void) const { }
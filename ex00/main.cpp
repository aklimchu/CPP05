#include "Bureaucrat.hpp"

int	main() {
	
	//---------------------Testing the constructors------------------//

	try {
		Bureaucrat Andrei("Andrei", 0);
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << '\n';
		std::cout << "Couldn't create the bureaucrat" << std::endl << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << '\n';
		std::cout << "Couldn't create the bureaucrat" << std::endl << std::endl;
	}

	Bureaucrat* John = nullptr;

	try {
		John = new Bureaucrat ("John", 200);
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << '\n';
		std::cout << "Couldn't create the bureaucrat" << std::endl << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << '\n';
		std::cout << "Couldn't create the bureaucrat" << std::endl << std::endl;
	}

	try {
		if (John)
			std::cout << "John is here" << std::endl << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << '\n';
	}

	Bureaucrat* James = nullptr;

	try {
		James = new Bureaucrat ("James", 2);
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		if (James)
			std::cout << "James is here" << std::endl << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << '\n';
	}

	//-------------------Testing the member functions----------------//

	std::cout << *James << std::endl << std::endl;

	try {
		James->incrementGrade();
		std::cout << *James << std::endl << std::endl;
		James->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << '\n';
		std::cout << "Couldn't increment the grade" << std::endl << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << *James << std::endl << std::endl;

	try {
		for (int i = 0; i < 151; i++)
			James->decrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << '\n';
		std::cout << "Couldn't decrement the grade" << std::endl << std::endl;
	}
	
	std::cout << *James << std::endl << std::endl;

	//------------------------Freeing the memory--------------------//

	if (John)
		delete John;
	if (James)
		delete James;
}
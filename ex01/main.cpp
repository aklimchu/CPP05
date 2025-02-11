#include "Bureaucrat.hpp"

int	main() {
	
	//---------------------Testing the constructors------------------//

	std::cout << "//----------------Let's try to create some bureaucrats--------------//" \
		<< std::endl << std::endl;

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
		James = new Bureaucrat ("James", 20);
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
		if (James)
			std::cout << "James is here" << std::endl << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << '\n';
	}

	//-----------------Testing the Bureaucrat member functions--------------//

	std::cout << "//----------------Let's test the bureaucrats' grades--------------//" \
		<< std::endl << std::endl;

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

	//---------------Testing the Form member functions-------------//

	std::cout << "//----------------Let's create some forms and test them--------------//" \
		<< std::endl << std::endl;

	Form* ConstructionPermit = nullptr;

	try {
		ConstructionPermit = new Form ("Construction Permit", 200, 150);
	}
	catch (Form::GradeTooHighException& e) {
		std::cerr << e.what() << '\n';
		std::cout << "Couldn't create the form" << std::endl << std::endl;
	}
	catch (Form::GradeTooLowException& e) {
		std::cerr << e.what() << '\n';
		std::cout << "Couldn't create the form" << std::endl << std::endl;
	}

	Form* SitePermit = nullptr;

	try {
		SitePermit = new Form ("Site Permit", 2, 100);
	}
	catch (Form::GradeTooHighException& e) {
		std::cerr << e.what() << '\n';
		std::cout << "Couldn't create the form" << std::endl << std::endl;
	}
	catch (Form::GradeTooLowException& e) {
		std::cerr << e.what() << '\n';
		std::cout << "Couldn't create the form" << std::endl << std::endl;
	}

	std::cout << *James << std::endl;
	std::cout << *SitePermit << std::endl;
	James->signForm(*SitePermit);

	Bureaucrat* Jordan = nullptr;

	try {
		Jordan = new Bureaucrat ("Jordan", 1);
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << '\n';
		std::cout << "Couldn't create the bureaucrat" << std::endl << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << '\n';
		std::cout << "Couldn't create the bureaucrat" << std::endl << std::endl;
	}

	std::cout << *Jordan << std::endl;
	std::cout << *SitePermit << std::endl;
	Jordan->signForm(*SitePermit);
	
	std::cout << *Jordan << std::endl;
	std::cout << *SitePermit << std::endl;
	Jordan->signForm(*SitePermit);

	//------------------------Freeing the memory--------------------//

	if (John)
		delete John;
	if (James)
		delete James;
	if (Jordan)
		delete Jordan;
	if (ConstructionPermit)
		delete ConstructionPermit;
	if (SitePermit)
		delete SitePermit;
}
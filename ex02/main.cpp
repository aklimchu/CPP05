/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:12:10 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/13 08:59:42 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

	std::cout << *James << std::endl << std::endl;

	//---------------Testing the AForm member functions-------------//

	std::cout << "//----------------Let's create some AForms and test them--------------//" \
		<< std::endl << std::endl;

	PresidentialPardonForm* PresidentialPardon = new PresidentialPardonForm("Sir Monterrey");
	RobotomyRequestForm* RobotomyRequest = new RobotomyRequestForm("Mr McKinsey");
	RobotomyRequestForm* RobotomyRequest2 = new RobotomyRequestForm("Mr McMuffin");
	ShrubberyCreationForm* ShrubberyCreation = new ShrubberyCreationForm("mynewfile");

	std::cout << *James << std::endl << std::endl;
	std::cout << *Jordan << std::endl << std::endl;
	
	James->signAForm(*PresidentialPardon);
	James->executeForm(*PresidentialPardon);
	Jordan->signAForm(*PresidentialPardon);
	Jordan->executeForm(*PresidentialPardon);
	
	Jordan->executeForm(*RobotomyRequest);
	Jordan->signAForm(*RobotomyRequest);
	Jordan->executeForm(*RobotomyRequest);
	
	Jordan->signAForm(*RobotomyRequest2);
	Jordan->executeForm(*RobotomyRequest2);

	Jordan->signAForm(*ShrubberyCreation);
	Jordan->executeForm(*ShrubberyCreation);

	//------------------------Freeing the memory--------------------//

	if (John)
		delete John;
	if (James)
		delete James;
	if (Jordan)
		delete Jordan;
	delete PresidentialPardon;
	delete RobotomyRequest;
	delete RobotomyRequest2;
	delete ShrubberyCreation;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:11:38 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/12 09:23:43 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

//--------------------------------Constructors--------------------------------//

Bureaucrat::Bureaucrat() : name(""), grade(150) {
	//std::cout << "Default constructor Bureaucrat called" << std::endl << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	//std::cout << "Parametric constructor Bureaucrat called" << std::endl << std::endl;
	validateGrade(grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : name(src.name) {
	//std::cout << "Copy constructor Bureaucrat called" << std::endl << std::endl;
	validateGrade(grade);
	this->grade = src.grade;
}

//---------------------------------Destructor---------------------------------//

Bureaucrat::~Bureaucrat() {
	//std::cout << "Destructor Bureaucrat called" << std::endl << std::endl;
}

//-------------------------------Member functions------------------------------//

std::string Bureaucrat::getName(void) const {
	return (this->name);
}

int Bureaucrat::getGrade(void) const {
	return(this->grade);
}

void Bureaucrat::incrementGrade(void) {
	validateGrade(grade - 1);
	this->grade--;
}

void Bureaucrat::decrementGrade(void) {
	validateGrade(grade + 1);
	this->grade++;
}

void Bureaucrat::validateGrade(int grade) const {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form & formToSign) {
	try {
		formToSign.beSigned(*this);
		std::cout << this->getName() << " signed " << formToSign.getName() \
			<< std::endl << std::endl;
	}
	catch (const Form::FormAlreadySignedException & e) {
		std::cout << this->getName() << " couldn’t sign " << formToSign.getName() << \
			" because the form has been signed already before." << std::endl << std::endl;
	}
	catch (const Form::GradeTooLowException & e) {
		std::cout << this->getName() << " couldn’t sign " << formToSign.getName() << \
			" because employee's grade is too low." << std::endl << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}
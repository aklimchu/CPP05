/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:11:55 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/12 13:49:04 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void Bureaucrat::signAForm(AForm & AFormToSign) {
	try {
		AFormToSign.beSigned(*this);
		std::cout << this->getName() << " signed " << AFormToSign.getName() \
			<< std::endl << std::endl;
	}
	catch (const AForm::AFormAlreadySignedException & e) {
		std::cout << this->getName() << " couldn’t sign " << AFormToSign.getName() << \
			" because the AForm has been signed already before." << std::endl << std::endl;
	}
	catch (const AForm::GradeTooLowException & e) {
		std::cout << this->getName() << " couldn’t sign " << AFormToSign.getName() << \
			" because employee's grade is too low." << std::endl << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() \
			<< std::endl << std::endl;
	}
	catch (const AForm::FormNotSigned & e) {
		std::cout << this->getName() << " couldn’t execute " << form.getName() << \
			" because the AForm has not been signed yet." << std::endl << std::endl;
	}
	catch (const AForm::GradeTooLowException & e) {
		std::cout << this->getName() << " couldn’t execute " << form.getName() << \
			" because employee's grade is too low." << std::endl << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}
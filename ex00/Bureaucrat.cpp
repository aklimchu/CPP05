/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:11:10 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/12 09:11:11 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//--------------------------------Constructors--------------------------------//

Bureaucrat::Bureaucrat() : name(""), grade(150) {
	std::cout << "Default constructor Bureaucrat called" << std::endl << std::endl;
	validateGrade(grade);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	std::cout << "Parametric constructor Bureaucrat called" << std::endl << std::endl;
	validateGrade(grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : name(src.name) {
	std::cout << "Copy constructor Bureaucrat called" << std::endl << std::endl;
	validateGrade(grade);
	this->grade = src.grade;
}

//---------------------------------Destructor---------------------------------//

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor Bureaucrat called" << std::endl << std::endl;
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

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}
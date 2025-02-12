/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:11:43 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/12 09:11:45 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

//--------------------------------Constructors--------------------------------//

Form::Form() : name("Empty"), signedStatus(0), gradeToSign(150), gradeToExecute(150) {
	//std::cout << "Default constructor Form called" << std::endl << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : \
name(name), signedStatus(0), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	//std::cout << "Parametric constructor Form called" << std::endl << std::endl;
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
}

Form::Form(Form const & src) : name(src.name), signedStatus(src.signedStatus), \
	gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute) {
	//std::cout << "Copy constructor Form called" << std::endl << std::endl;
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
}

//---------------------------------Destructor---------------------------------//

Form::~Form() {
	//std::cout << "Destructor Form called" << std::endl << std::endl;
}

//-------------------------------Member functions------------------------------//

void Form::validateGrade(int grade) const {
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

std::string Form::getName(void) const {
	return (this->name);
}

int Form::getGradeToSign(void) const {
	return (this->gradeToSign);
}

int Form::getGradeToExecute(void) const {
	return (this->gradeToExecute);
}

bool Form::getSignedStatus(void) const {
	return (this->signedStatus);
}

void Form::beSigned(Bureaucrat & employee) {
	if (employee.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	if (this->signedStatus == true)
		throw Form::FormAlreadySignedException();
	this->signedStatus = true;
}

std::ostream & operator<<(std::ostream & o, Form const & rhs) {
	if (rhs.getSignedStatus() == false)
		o << "Form " << rhs.getName() << " has not been signed yet." << std::endl;
	else
		o << "Form " << rhs.getName() << " has been signed." << std::endl;
	o << "Grade needed to sign the form: " << rhs.getGradeToSign() << std::endl;
	o << "Grade needed to execute the form: " << rhs.getGradeToExecute() << std::endl << std::endl;
	return o;
}
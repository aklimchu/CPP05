/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:12:02 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/13 10:20:39 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//--------------------------------Constructors--------------------------------//

AForm::AForm() : name("Empty"), target("home"),signedStatus(0), gradeToSign(150), \
	gradeToExecute(150) {
	//std::cout << "Default constructor AForm called" << std::endl << std::endl;
}

AForm::AForm(std::string name, std::string target, int gradeToSign, int gradeToExecute) : \
name(name), target(target), signedStatus(0), gradeToSign(gradeToSign), \
	gradeToExecute(gradeToExecute) {
	//std::cout << "Parametric constructor AForm called" << std::endl << std::endl;
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
}

AForm::AForm(AForm const & src) : name(src.name), signedStatus(src.signedStatus), \
	gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute) {
	//std::cout << "Copy constructor AForm called" << std::endl << std::endl;
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
}

//---------------------------------Destructor---------------------------------//

AForm::~AForm() {
	//std::cout << "Destructor AForm called" << std::endl << std::endl;
}

//-------------------------------Member functions------------------------------//

void AForm::validateGrade(int grade) const {
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
}

std::string AForm::getName(void) const {
	return (this->name);
}

std::string AForm::getTarget(void) const {
	return (this->target);
}

int AForm::getGradeToSign(void) const {
	return (this->gradeToSign);
}

int AForm::getGradeToExecute(void) const {
	return (this->gradeToExecute);
}

bool AForm::getSignedStatus(void) const {
	return (this->signedStatus);
}

void AForm::beSigned(Bureaucrat & employee) {
	if (employee.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	if (this->signedStatus == true)
		throw AForm::AFormAlreadySignedException();
	this->signedStatus = true;
}

void AForm::execute(Bureaucrat const & executor) const {
	std::string form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i;
	
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (this->getSignedStatus() == false)
		throw AForm::FormNotSigned();
	for (i = 0; i < 3; i++) {
		if (this->getName() == form_names[i]) {
			break ;
		}
	}
	switch (i) {
		case 0:
			this->createFile();
			break;
		case 1:
			this->makeNoise();
			break;
		case 2:
			this->pardonedByZaphod();
			break;
		default:
			std::cout << "Form doesn't exist" << std::endl << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs) {
	if (rhs.getSignedStatus() == false)
		o << "AForm " << rhs.getName() << " has not been signed yet." << std::endl;
	else
		o << "AForm " << rhs.getName() << " has been signed." << std::endl;
	o << "Grade needed to sign the AForm: " << rhs.getGradeToSign() << std::endl;
	o << "Grade needed to execute the AForm: " << rhs.getGradeToExecute() << std::endl << std::endl;
	return o;
}
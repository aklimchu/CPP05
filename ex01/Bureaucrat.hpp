#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat(void); // Canonical
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src); // Canonical
		~Bureaucrat(void); // Canonical

		Bureaucrat & operator=(Bureaucrat const & rhs) = delete; // Canonical

		std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(Form & formToSign);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Bureaucrat can't have grade higher then 1");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Bureaucrat can't have grade lower then 150");
				}
		};

	private:
		const std::string name;
		int grade;
		void validateGrade(int grade) const;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);
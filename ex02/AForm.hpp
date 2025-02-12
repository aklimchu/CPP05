/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:12:07 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/12 14:24:57 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(void); // Canonical
		AForm(std::string name, std::string target, int gradeToSign, int gradeToExecute);
		AForm(AForm const & src); // Canonical
		~AForm(void); // Canonical

		AForm & operator=(AForm const & rhs) = delete; // Canonical

		std::string getName(void) const;
		std::string getTarget(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		bool getSignedStatus(void) const;
		
		void beSigned(Bureaucrat & employee);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("AForm can't have grade higher then 1");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("AForm can't have grade lower then 150");
				}
		};

		class AFormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("AForm has been signed already before");
				}
		};

		class FormNotSigned : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("AForm has not been signed yet");
				}
		};

		void execute(Bureaucrat const & executor) const;
		

	private:
		std::string const name;
		std::string const target;
		bool signedStatus;
		int const gradeToSign;
		int const gradeToExecute;
	
	protected:
		void validateGrade(int grade) const;
};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);
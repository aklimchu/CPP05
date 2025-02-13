/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:11:46 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/13 08:44:16 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(void); // Canonical
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(Form const & src); // Canonical
		~Form(void); // Canonical

		Form & operator=(Form const & rhs) = delete; // Canonical

		std::string getName(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		bool getSignedStatus(void) const;
		void beSigned(Bureaucrat & employee);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Form can't have grade higher then 1");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Form can't have grade lower then 150");
				}
		};

		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Form has been signed already before");
				}
		};

	private:
		std::string const name;
		bool signedStatus;
		int const gradeToSign;
		int const gradeToExecute;
		void validateGrade(int grade) const;
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);
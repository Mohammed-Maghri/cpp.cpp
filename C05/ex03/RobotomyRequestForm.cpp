/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:20:53 by mmaghri           #+#    #+#             */
/*   Updated: 2024/09/23 18:19:51 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm() : AForm("From_Shrubbery", 73, 46), target("Default"){ std::cout << "RobotomyRequestForm Cons" << std::endl;};
RobotomyRequestForm::RobotomyRequestForm(const std::string& value) : AForm("From_Shrubbery",  73, 46), target(value) {};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& value) : AForm(value) ,  target(value.target) {};
RobotomyRequestForm::~RobotomyRequestForm () {std::cout << "Destructor Is Called !" << std::endl ;};
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& value){
    this->ifsigned = value.ifsigned ;
    this->target = value.target ;
    return (*this);
};

std::string RobotomyRequestForm::Get_target(){return (this->target);};

void RobotomyRequestForm::execute(Bureaucrat const& executor){
    (this->Sign_grade < 72 || this->Excute_grade < 45 || executor.getGrade() <= 72) ? 
    (throw(CatchError())) : (functionDraw());
};

std::string RobotomyRequestForm::functionDraw() {
    std::cout << "Intern Creates " << this->target << std::endl;
    std::cout << this->target + "has been robotomizedsuccessfully 50% of the time" << std::endl ;
    return (this->target + "has been robotomizedsuccessfully 50% of the time");
}

const char * RobotomyRequestForm::CatchError::what() const throw(){
    return ("Robotomy Failed !");
};
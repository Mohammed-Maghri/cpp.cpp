/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:27:48 by mmaghri           #+#    #+#             */
/*   Updated: 2024/12/01 17:19:36 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char **argv) {
    if (argc != 2) {std::cout << "Not A Valid Argument's !" << std::endl ; return (0);}
    try {
        RPN elementsStored ;
        long long number  ;
        int first = -1;
        int second = -1;
        std::string string = argv[1];
        std::stringstream s(string);
        std::string insert ;
        for (;s >> insert;){
            if (insert.length() > 1){std::cout << "Invalid Argument !" << std::endl ; ;exit(1);}
            if (notOneOfThose(insert) == -1) throw (std::logic_error("Error Not a Valid Identifier !!"));
            if (isdigit(insert[0])){
                number = atof(insert.c_str());
                if (number > 10)   throw std::logic_error("Number too large");
                elementsStored.ElementStored.push(number);
            }
            if (insert[0] == '+' || insert[0] == '-' || insert[0] == '/' || insert[0] == '*'){
                if (elementsStored.ElementStored.size() < 2) throw std::logic_error("Not A valid Arg !");
                if (elementsStored.ElementStored.size() > 1){
                    first = elementsStored.ElementStored.top();
                    elementsStored.ElementStored.pop();
                    second = elementsStored.ElementStored.top() ;
                    elementsStored.ElementStored.pop();
                    elementsStored.ElementStored.push(functionMakeSign(insert, second, first));
                    first  = -1  ;
                    second = -1  ;
                }
            }
        };
        if (elementsStored.ElementStored.size() > 1) {throw std::logic_error("Elemet Last In stack !");}
        std::cout << " _> " << elementsStored.ElementStored.top() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl ;
    }
    return (0);
}
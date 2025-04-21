/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:35:00 by mmaghri           #+#    #+#             */
/*   Updated: 2024/11/30 10:28:57 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int functionGetTwo(RPN &elements) {
    if (elements.ElementStored.size() == 0) return -1  ;
    int toreturn ;
    toreturn = elements.ElementStored.top();
    elements.ElementStored.pop() ;
    return (toreturn);
};

int functionMakeSign (std::string sign, int first, int second) {
    if (sign[0] == '+')
        return (first + second);
    if (sign[0] == '-')
        return (first - second);
    if (sign[0] == '/'){
        if (second == 0){
            throw (std::logic_error("Can't Devide on 0 !"));
        }
        return (first / second);
    }
    if (sign[0] == '*')
        return (first * second);
    return (-999999999);
};

int notOneOfThose(std::string value) {
    for (size_t index = 0; index < value.size(); index++){
        if (!isdigit(value[index]) && (value[index] != '+' && 
        value[index] != '-' && value[index] != '/' && value[index] != '*')){
            return (-1);
        }
    }
    return (0);
};


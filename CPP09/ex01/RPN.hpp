/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:35:56 by mmaghri           #+#    #+#             */
/*   Updated: 2024/12/01 15:01:51 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <stack>
#include <iostream>
#include <sstream>

class RPN {
    public :
        RPN(){};
        RPN(RPN &value){
            (void)value ;
        };
        RPN& operator = (RPN &value){
            (void)value ;
            return (*this);
        };
        ~RPN(){};
        std::stack<int> ElementStored ;
};

int notOneOfThose(std::string value);
int functionMakeSign (std::string sign, int first, int second);
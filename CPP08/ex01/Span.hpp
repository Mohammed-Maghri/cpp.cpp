/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:38:15 by mmaghri           #+#    #+#             */
/*   Updated: 2024/10/03 15:09:54 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <iostream>
#include <vector>
class Span {
    private :
        unsigned int size;
        std::vector<int> values ;
    public :
        void addNumber(int number);
        unsigned int getVectorSize();
        int GetVar() const;
        void SetVar(int value);
        Span();
        ~Span();
        void printVecList();
        int shortestSpan();
        int longestSpan();
        Span(const Span& value);
        Span& operator= (const Span& value);
        Span(unsigned int value);
        class throwmuch : public std::exception {
            const char *what() const throw() {
                return ("The Container Does Have Enough Volumes !");
            };
        };
};

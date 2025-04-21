/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:50:45 by mmaghri           #+#    #+#             */
/*   Updated: 2024/10/03 16:44:16 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <vector>
#include <stack>
#include <deque>

template <typename T, typename container = std::deque <T> >
class MutantStack : public std::stack <T, container> {
    
        public:
            typedef typename container::iterator iterator;
            MutantStack(){
                std::cout << "Constructor Called !" << std::endl ;
            };
            MutantStack(const MutantStack& value){
                *this = value ; 
            };
            MutantStack& operator= (const MutantStack& value){
                if (this != &value){
                    this->c = value.c;
                }
                return (*this);
            };
            ~MutantStack(){
                std::cout << "Destructor Called !" << std::endl ;
            };
            iterator end() {
                return this->c.end();
            }
            iterator begin() {
                return this->c.begin();
            }
};
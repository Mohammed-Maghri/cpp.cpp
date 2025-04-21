/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:41:22 by mmaghri           #+#    #+#             */
/*   Updated: 2024/10/03 16:42:50 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(){
    size = 0;
};

Span::Span(unsigned int value) : size(value) {
};

int Span::GetVar() const{
    return (this->size) ; 
};

void Span::SetVar(int value) {
    this->size = value ;
};

unsigned int Span::getVectorSize(){
    return (values.size());
};

void Span::addNumber(int number){
    if (size > getVectorSize()) {values.push_back(number);}
    else {throw (throwmuch());};
};

void Span::printVecList(){
    for (size_t i = 0; i < values.size(); i++){
        std::cout << values[i] << std::endl ;
    };
};

int Span::longestSpan(){
    std::sort(values.begin(), values.end());
    std::vector<int>::iterator it = values.begin();
    std::vector<int>::iterator itend = values.end();
    itend-- ;
    return ((*itend - *it));
};

int Span::shortestSpan(){
    std::sort(values.begin(), values.end());
    int flag = INT_MAX;
    std::vector<int>::iterator it;
    std::vector<int>::iterator itend;
    int hold ;
    itend = values.end() ;
    it = values.begin();
    for (; it < itend - 1; it++){
        if (getVectorSize() > 1){
            hold = (*it);
            it++;
            if ((*it) - (hold) < flag){
                flag = (*it) - (hold) ;
            };
            (it--);
        }
    };
    return (flag);
};

Span::Span(const Span& value){
    *this = value ;
};

Span::~Span(){};

Span& Span::operator= (const Span& value){
    if (this != &value){
        this->size = value.size;
        this->values = value.values ;
    }
    return (*this);
}


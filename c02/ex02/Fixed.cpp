/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:17:44 by mmaghri           #+#    #+#             */
/*   Updated: 2024/09/01 22:38:30 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
    this->store = 0;
 };

Fixed& Fixed::operator=(const Fixed &copy) {
    (void)copy;
    this->store = copy.getRawBits();
    return (*this);
};

Fixed::Fixed(const Fixed &copy) {
    *this = copy ; 
};

void Fixed::getValue(){
    std::cout << this->store << std::endl ;
};

Fixed::~Fixed() {
};

int Fixed::getRawBits(void) const {
    return (this->store);
};

void Fixed::setRawBits(int const raw){
    this->store = raw ;
};

Fixed::Fixed(const float number){
    int expo = (pow(2, this->fractionali_bit));
    this->store = roundf(number * expo) ;
};

Fixed::Fixed(const int number){
    int expo = (pow(2, this->fractionali_bit));
    this->store = roundf(number * expo);
};

float Fixed::toFloat(void) const {
    int expo = (pow(2, this->fractionali_bit));
    float value = (float)this->store / (float)expo ;
    return (value);
}

int Fixed::toInt(void) const {
    std::cout << "As Int" << std::endl ;
    int expo = (pow(2, this->fractionali_bit));
    int value = this->store / expo;
    return (value);
};

std::ostream& operator<<(std::ostream& os, const Fixed &value) {
    os << value.toFloat();
    return os;
}

Fixed Fixed::operator+ (const Fixed &value) const { 
    Fixed tmp ;
    tmp.store = this->store + value.store ; 
    return (tmp);
};

Fixed Fixed::operator- (const Fixed &value) const {
    Fixed tmp ;
    tmp.store = this->store - value.store ;
    return (tmp);
};

Fixed Fixed::operator* (const Fixed &value) const {
    Fixed tmp ;
    int expo = pow(2, this->fractionali_bit);
    tmp.store = (this->store * value.store) / expo ;
    return (tmp);
};

bool Fixed::operator< (const Fixed &value) const {
    return (this->toInt() < value.toInt());
}

bool Fixed::operator> (const Fixed &value) const {
    return (this->toInt() > value.toInt());
};

bool Fixed::operator<= (const Fixed &value) const {
    return (this->toInt() <= value.toInt());
};

Fixed Fixed::operator++ (int){
    Fixed fixe(*this);
    this->store++ ;
    return (fixe);
};


Fixed Fixed::operator++ ()
{
    this->store++ ;
    return (*this);
};

Fixed Fixed::operator-- (int){
    Fixed fixe(*this);
    this->store-- ;
    return (fixe);
};


Fixed Fixed::operator-- ()
{
    this->store-- ;
    return (*this);
};
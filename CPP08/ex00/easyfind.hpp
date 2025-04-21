/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:27:23 by mmaghri           #+#    #+#             */
/*   Updated: 2024/10/03 14:42:51 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


template <typename T>

void easyfind (T value, int secvalue){
    typename T::iterator it = std::find(value.begin(), value.end(), secvalue) ;
    (it != value.end()) ? 
    (std::cout << "Element Found !" << std::endl) 
    : (std::cout << "Element Not Found !" << std::endl);
};
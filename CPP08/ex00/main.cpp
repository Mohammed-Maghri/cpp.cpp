/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:03:01 by mmaghri           #+#    #+#             */
/*   Updated: 2024/10/01 17:04:08 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(){
    std::vector<int> number;
    number.push_back(2);
    number.push_back(6);
    number.push_back(10);
    number.push_back(3);
    number.push_back(2);
    number.push_back(10);

    easyfind(number, 0);
    for (size_t i = 0; i < number.size(); i++)
    {
        std::cout << number[i] << std::endl;
    }
    return (0);
};
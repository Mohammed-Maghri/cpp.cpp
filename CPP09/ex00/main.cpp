/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:08:47 by mmaghri           #+#    #+#             */
/*   Updated: 2024/12/02 15:31:46 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <string>
#include "BitcoinExchange.hpp"

std::string returnWithoutSpaces(std::string value) {
    int start = value.find_first_not_of(" \t\n");
    int end   = value.find_last_not_of(" \t\n");
    return (value.substr(start, end));
};

void functionCheckWithExactDates (std::string values, StoreElements Data) {
    if (values.find("Error") != std::string::npos) {
        std::cout << values << std::endl;
        return ;
    }
    int holdstart = values.find("|");
    std::map<std::string, double>::iterator start = Data.beging();
    std::map<std::string, double>::iterator end = Data.theend();
    std::string startOfVALUE = returnWithoutSpaces(values.substr(0, holdstart + 1));
    startOfVALUE = startOfVALUE.substr(startOfVALUE.find_first_not_of(" \t\n"), startOfVALUE.find_last_not_of(" \t\n") + 1);
    std::string endOfVALUE = returnWithoutSpaces(values.substr(holdstart + 1));
    endOfVALUE = endOfVALUE.substr(endOfVALUE.find_first_not_of(" \t\n"), endOfVALUE.find_last_not_of(" \t\n") + 1);
    end-- ;
    if (atof(endOfVALUE.c_str()) > 1000){
        std::cout << "Error Bad Input => " << startOfVALUE << " | " <<  endOfVALUE << std::endl ;
        return ;
    }
    if (end->first <= startOfVALUE) {
        std::cout << startOfVALUE << " => " << endOfVALUE << " = " << (atof(endOfVALUE.c_str()) * end->second) << " ->" << end->second << std::endl;
        return ;
    }
    if (start->first > startOfVALUE){
        std::cout << "No Existing Dates => " << startOfVALUE << " | " << endOfVALUE  << std::endl ;
        return ;
    }
    double prev_Value = start->second;
    for (; start != end; start++){
        if (start->first >= startOfVALUE){
            if (start->first == startOfVALUE)
                std::cout << startOfVALUE << " => " << endOfVALUE << " = " << start->second << (atof(endOfVALUE.c_str()) * start->second) << std::endl ;
            else {
                std::cout <<  startOfVALUE << " => " << endOfVALUE << " = " << (atof(endOfVALUE.c_str()) * prev_Value) << std::endl ;
            }
            prev_Value = start->second ;
            break ; 
        }
        prev_Value = start->second ;
    };
};

int main(int argc, char **argv){
    if (argc != 2){
        std::cout << "could not open file." << std::endl ;
        return (1);
    }
    std::string StoreInaelement ;
    std::string CheckStore ;
    StoreElements Values;
    GetDataBase("data.csv", Values);
    CheckInputData(argv[1], Values);
    return (0);
};
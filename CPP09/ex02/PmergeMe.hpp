/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:26:07 by mmaghri           #+#    #+#             */
/*   Updated: 2024/11/30 10:34:52 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

void mergeSort(std::vector<int>& array, int left, int right, int flag);
void mergeSortd(std::deque<int>& array, int left, int right, int flag);
clock_t DfunctionSetpairs(std::deque<int> values);
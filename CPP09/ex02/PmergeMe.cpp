
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:37:20 by mmaghri           #+#    #+#             */
/*   Updated: 2024/11/29 11:58:31 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>
#include <deque>

void GetBigOrSmall(std::vector<std::pair<int, int> > &values)
{
    std::vector<std::pair<int, int> >::iterator it = values.begin();
    std::vector<std::pair<int, int> >::iterator end = values.end();
    int first, sec;
    for (; it != end; it++)
    {
        first = it->first;
        sec = it->second;
        if (it->first > it->second)
        {
            it->first = sec;
            it->second = first;
        }
    };
};

void insertElements(std::vector<int> &insertIn, std::vector<int> array)
{
    std::vector<int>::iterator st = array.begin();
    std::vector<int>::iterator end = array.end();
    std::vector<int>::iterator start = insertIn.begin();
    std::vector<int>::iterator endst = insertIn.end();
    std::vector<int>::iterator ensert;
    for (; st != end; st++)
    {
        ensert = std::lower_bound(start, endst, *st);
        insertIn.insert(ensert, *st);
        start = insertIn.begin();
        endst = insertIn.end();
    };
};

clock_t functionSetpairs(std::vector<int> values)
{
    clock_t startTime = clock();
    std::vector<int> fillbig;
    std::vector<int> fillsmall;
    bool toadjust = true;
    int adjust;
    std::vector<std::pair<int, int> > elements;
    size_t index = 0;
    for (; index <= values.size(); index += 2)
    {
        if (index + 1 >= values.size())
            break;
        if (index + 1 < values.size())
            elements.push_back(std::make_pair(values[index], values[index + 1]));
    };
    if (values.size() % 2 != 0)
    {
        toadjust = false;
        adjust = values[index];
    };
    GetBigOrSmall(elements);
    std::vector<std::pair<int, int> >::iterator beg = elements.begin();
    std::vector<std::pair<int, int> >::iterator notbeg = elements.end();
    for (; beg != notbeg; beg++)
    {
        fillsmall.push_back(beg->first);
        fillbig.push_back(beg->second);
    };
    mergeSort(fillbig, 0, fillbig.size() - 1, 0);
    std::vector<int>::iterator st = fillbig.begin();
    std::vector<int>::iterator ed = fillbig.end();
    insertElements(fillbig, fillsmall);
    st = fillbig.begin();
    ed = fillbig.end();
    std::vector<int>::iterator ensert;
    if (toadjust == false)
        fillbig.insert(std::lower_bound(st, ed, adjust), adjust);
    st = fillbig.begin();
    ed = fillbig.end();
    std::cout << "After  : ";
    for (; st != ed; st++)
        std::cout << *st << " ";
    std::cout << std::endl;
    return (startTime);
};

int checkIfOnlyNumbers(std::string value){
    if (value.size() == 0) return (-1);
    for (size_t index = 0; index < value.size(); index++){
        if (isdigit(value[index]) != 1) return (-1);
    };
    return (0);
};
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "No Argument Available !" << std::endl;
        return (0);
    }
    try
    {
        clock_t startTime ;
        std::vector<int> values;
        std::deque<int> allelemnt ;
        std::string value = argv[1];
        std::stringstream pass(value);
        std::string input;
        for (int index = 1; index < argc; index++)
        {
            if (checkIfOnlyNumbers(argv[index]) == -1) throw std::logic_error("Error Detected !!");
            if (atof(argv[index]) < 0)
                throw std::logic_error("Negative Number !");
            values.push_back(atof(argv[index]));
            allelemnt.push_back(atof(argv[index]));
        };
        std::cout << "Before : ";
        for (int i = 1; i < argc; i++) std::cout << argv[i] << " ";
        std::cout << std::endl;
        startTime = functionSetpairs(values);
        clock_t enddate = clock();
        double elapsed_ms = static_cast<double>(enddate - startTime) * 1000.0 / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << (argc - 1) << " elements with std::vector " << elapsed_ms << " us" << std::endl;
        std::cout << "Before : ";
        for (int i = 1; i < argc; i++) std::cout << argv[i] << " ";
        std::cout << std::endl;
        startTime = DfunctionSetpairs(allelemnt);
        enddate = clock();
        elapsed_ms = static_cast<double>(enddate - startTime) * 1000.0 / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << (argc - 1) << " elements with std::deque " << elapsed_ms << " us" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dmerge.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:06:40 by mmaghri           #+#    #+#             */
/*   Updated: 2024/12/01 17:32:14 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>
#include <deque>

void DGetBigOrSmall(std::deque<std::pair<int, int> > &values)
{
    std::deque<std::pair<int, int> >::iterator it = values.begin();
    std::deque<std::pair<int, int> >::iterator end = values.end();
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

void DinsertElements(std::deque<int> &insertIn, std::deque<int> array)
{
    std::deque<int>::iterator st = array.begin();
    std::deque<int>::iterator end = array.end();
    std::deque<int>::iterator start = insertIn.begin();
    std::deque<int>::iterator endst = insertIn.end();
    std::deque<int>::iterator ensert;
    for (; st != end; st++)
    {
        ensert = std::lower_bound(start, endst, *st);
        insertIn.insert(ensert, *st);
        start = insertIn.begin();
        endst = insertIn.end();
    };
};

clock_t DfunctionSetpairs(std::deque<int> values)
{
    clock_t startTime = clock();
    std::deque<int> fillbig;
    std::deque<int> fillsmall;
    bool toadjust = true;
    int adjust;
    std::deque<std::pair<int, int> > elements;
    size_t index = 0;
    for (; index <= values.size(); index += 2)
    {
        if (index + 1 >= values.size())
            break;
        if (index + 1 < values.size())
            elements.push_back(std::make_pair(values[index], values[index + 1]));
    };
    if (values.size() % 2 != 0) {toadjust = false; adjust = values[index];};
    DGetBigOrSmall(elements);
    std::deque<std::pair<int, int> >::iterator beg = elements.begin();
    std::deque<std::pair<int, int> >::iterator notbeg = elements.end();
    for (; beg != notbeg; beg++)
    {
        fillsmall.push_back(beg->first);
        fillbig.push_back(beg->second);
    };
    mergeSortd(fillbig, 0, fillbig.size() - 1, 0);
    std::deque<int>::iterator st = fillbig.begin();
    std::deque<int>::iterator ed = fillbig.end();
    DinsertElements(fillbig, fillsmall);
    st = fillbig.begin();
    ed = fillbig.end();
    std::deque<int>::iterator ensert;
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


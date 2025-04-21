/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:01:42 by mmaghri           #+#    #+#             */
/*   Updated: 2024/10/03 16:55:01 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <stack>
# include <vector>
#include <list>
int main()
{
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::cout << "---------------------" << std::endl ;
        std::stack<int > s(mstack);
        std::list<int> mtack;
        mtack.push_back(5);
        mtack.push_front(17);
        std::cout << mtack.front() << std::endl;
        mtack.pop_front();
        std::cout << mtack.size() << std::endl;
        mtack.push_back(3);
        mtack.push_back(5);
        mtack.push_back(737);
        mtack.push_back(0);
        std::list<int>::iterator iti = mtack.begin();
        std::list<int>::iterator itei = mtack.end();
        ++iti;
        --iti;
        while (iti != itei)
        {
                std::cout << *iti << std::endl;
                ++iti;
        }
        std::stack<int > w(mstack);
return 0;
}
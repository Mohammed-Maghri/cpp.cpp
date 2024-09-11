/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:28:37 by mmaghri           #+#    #+#             */
/*   Updated: 2024/09/11 18:29:51 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap {
    protected : 
        std::string name;
        unsigned int energy_point ;
        unsigned int hit_points;
        unsigned int attack_damage ;
    public :
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap &Clap);
        ClapTrap& operator= (const ClapTrap &target);
        std::string GetName() const;
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        int  GetEnergy() const;
        int  Getattack() const;
        int  GetHit() const;
        ~ClapTrap();
};
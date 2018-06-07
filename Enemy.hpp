/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 19:17:59 by dkhlopov          #+#    #+#             */
/*   Updated: 2018/04/08 19:18:01 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <curses.h>
#include <iostream>
#include "ACharacter.hpp"

class Enemy : public ACharacter
{

public:
	Enemy( void );
	Enemy(Enemy const & src);
	~Enemy( void );

	Enemy & 	operator=( Enemy const & rhs );

};

std::ostream &		operator<<( std::ostream & o, Enemy const & rhs );

#endif

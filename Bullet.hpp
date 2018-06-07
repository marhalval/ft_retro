/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 19:17:43 by dkhlopov          #+#    #+#             */
/*   Updated: 2018/04/08 19:17:45 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

#include <curses.h>
#include <iostream>
#include "ACharacter.hpp"

class Bullet : public ACharacter
{
public:
	Bullet();
	Bullet(Bullet const & src);
	~Bullet();

	Bullet & 	operator=( Bullet const & rhs );
	
};

#endif

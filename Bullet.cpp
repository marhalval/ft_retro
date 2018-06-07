/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 19:17:37 by dkhlopov          #+#    #+#             */
/*   Updated: 2018/04/08 19:17:40 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet( void ) : ACharacter(-1, -1, '*') { 
	this->_color = 2;
}

Bullet::Bullet( Bullet const & src ) {
	*this = src;
	return ;
}

Bullet::~Bullet( void ) { }

Bullet &		Bullet::operator=( Bullet const & rhs ) {
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_char = rhs.getChar();

	return *this;
}

std::ostream &		operator<<( std::ostream & o, Bullet const & rhs ) {

	o << "Bullet at pos X: " << rhs.getX() << " Y: " << rhs.getY() << std::endl;

	return o;
}

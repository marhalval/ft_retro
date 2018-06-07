/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 19:17:22 by dkhlopov          #+#    #+#             */
/*   Updated: 2018/04/08 19:17:24 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ACharacter.hpp"

ACharacter::ACharacter( void ) : _x(0), _y(0), _char(' '), _color( 1 ) { }

ACharacter::ACharacter( int const x, int const y, int const ch ) {
	this->_x = x;
	this->_y = y;
	this->_char = ch;
	this->_color = 1;
}

ACharacter::ACharacter( ACharacter const & src ) {
	*this = src;
	return ;
}

ACharacter::~ACharacter( void ) { }

ACharacter &		ACharacter::operator=( ACharacter const & rhs ) {
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_char = rhs.getChar();
	this->_color = rhs.getColor();

	return *this;
}

int			ACharacter::getX( void ) const {
	return this->_x;
}
int			ACharacter::getY( void ) const {
	return this->_y;
}
int			ACharacter::getChar( void ) const {
	return this->_char;
}

int			ACharacter::getColor( void ) const {
	return this->_color;	
}

void		ACharacter::setChar( char const ch ) {
	this->_char = ch;
}

void		ACharacter::setX( int const x ) {
	this->_x = x;
} 

void		ACharacter::setY( int const y ) {
	this->_y = y;
}

void		ACharacter::setPos( int const x, int const y ) {
	this->_x = x;
	this->_y = y;
}

void		ACharacter::draw( void ) const {

	move(this->_x, this->_y);
	addch(this->_char | COLOR_PAIR(this->_color));
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 19:17:53 by dkhlopov          #+#    #+#             */
/*   Updated: 2018/04/08 19:17:55 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy( void ) : ACharacter(-1, 0, 'X') { }

Enemy::Enemy( Enemy const & src ) {
	*this = src;
	return ;
}

Enemy::~Enemy( void	) { }

Enemy &		Enemy::operator=( Enemy const & rhs ) {
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_char = rhs.getChar();

	return *this;
}

std::ostream &		operator<<( std::ostream & o, Enemy const & rhs ) {

	o << "Enemy at pos X: " << rhs.getX() << " Y: " << rhs.getY() << std::endl;

	return o;
}

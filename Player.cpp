/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 19:18:33 by dkhlopov          #+#    #+#             */
/*   Updated: 2018/04/08 19:18:34 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player( void ) : ACharacter(0, 0, 'H') { 
	this->_shoot = false;
	this->_color = 3;
}

Player::Player( Player const & src ) {
	*this = src;
	return ;
}

Player::~Player( void ) { }

Player &		Player::operator=( Player const & rhs ) {
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_char = rhs.getChar();
	this->_color = rhs.getColor();

	return *this;
}

bool			Player::getShoot( void ) const {
	return this->_shoot;	
}

void			Player::setShoot( bool const shoot ) {
	this->_shoot = shoot;	
}

void			Player::action( int const height, int const width, bool & end_flag ) {

	int 	ch;

	ch = getch();

	switch(ch) {

		case KEY_UP:
			this->setX(this->getX() - 1);
			break;

		case KEY_DOWN:
			this->setX(this->_x + 1);
			break;

		case KEY_LEFT:
			this->setY(this->_y - 1);
			break;

		case KEY_RIGHT:
			this->setY(this->_y + 1);
			break;

		case ' ':
			this->_shoot = true;
			break;

		case 'q':
			move(10, 50);
			printw("GAME OVER");
			end_flag = true;
			
	}

	if (this->_x < 0)
		this->setX(0);
	else if (this->_x > height - 2)
		this->setX(height - 2);

	if (this->_y < 1)
		this->setY(1);
	else if (this->_y > width - 2)
		this->setY(width - 2);

}

void 		Player::draw( void ) const {
	move(this->_x, this->_y);
	addch('A' | COLOR_PAIR(this->_color));
	move(this->_x + 1, this->_y - 1);
	addch('I' | COLOR_PAIR(this->_color));
	addch('H' | COLOR_PAIR(this->_color));
	addch('I' | COLOR_PAIR(this->_color));
}

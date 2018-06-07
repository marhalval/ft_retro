/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 19:18:15 by dkhlopov          #+#    #+#             */
/*   Updated: 2018/04/08 19:18:18 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

#include <iostream>
#include <curses.h>
#include <cstdlib>
#include <unistd.h>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

#define		EMEMIES_NB  50
#define		BULLETS_NB	10
#define 	FPS			60

class Game
{

private:

	Player				_player;
	unsigned long		_cycle;
	Enemy				_enemies[EMEMIES_NB];
	Bullet 				_bullets[BULLETS_NB];
	int					_w_height;
	int					_w_width;
	bool				_end_game;
	int					_score;

public:

	Game( void );
	Game( Game const & src );
	~Game( void );

	unsigned long		getCycle( void ) const ;
	void				setCycle( unsigned long const cycle );

	Game & 				operator=( Game const & rhs );

	void 				start( void );
	void				moveEnemies( void );
	void				moveBullets( void );
	void 				drawEnemies( void ) const ;
	void				drawBullets( void ) const ;
	void 				shoot( int const x, int const y );

	void				colission( void );
	
};


#endif

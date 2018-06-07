/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 19:18:09 by dkhlopov          #+#    #+#             */
/*   Updated: 2018/04/08 19:18:12 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

unsigned long		Game::getCycle( void ) const {
	return this->_cycle;
}

void				Game::setCycle( unsigned long const cycle ) {
	this->_cycle = cycle;
}

Game::Game( void ) {
	// Init ncurces screen //
	initscr();
	nodelay(stdscr, true);
	noecho();
	curs_set(0);
	keypad(stdscr, true);
	// ---------==-------- //

	getmaxyx(stdscr, this->_w_height, this->_w_width);

	this->_player.setX(this->_w_height - 3);
	this->_player.setY(this->_w_width / 2);

	this->_cycle = 0;

	for (int i = 0; i < EMEMIES_NB; i++)
	{
		this->_enemies[i].setX(i * (-1));
	}

	this->_end_game = false;

	this->_score = 0;

	start_color();

    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
}

Game::Game( Game const & src ) {
	*this = src;
	return ;
}

Game::~Game( void ) {
	nodelay(stdscr, false);
	endwin();
}

Game &			Game::operator=( Game const & rhs ) {

	this->_cycle = rhs.getCycle();

	return *this;
}

void			Game::moveEnemies( void ) {

	for (int i = 0; i < EMEMIES_NB; i++ )
	{

		if (this->_enemies[i].getX() >= this->_w_height ) {
			this->_enemies[i].setPos(0, 0);
		}

		if (this->_enemies[i].getY() == 0) {
			this->_enemies[i].setY((rand() +this->_cycle) % this->_w_width);
		}

		this->_enemies[i].setPos(this->_enemies[i].getX() + 1, this->_enemies[i].getY());
	}

}

void 			Game::drawEnemies( void ) const {

	for (int i = 0; i < EMEMIES_NB; i++ )
	{
		if (this->_enemies[i].getX() > 0) {

			this->_enemies[i].draw();
		}
	}
}

void			Game::moveBullets( void ) {

	for (int i = 0; i < BULLETS_NB; i++ )
	{
		if (this->_bullets[i].getX() == -1)
			this->_bullets[i].setPos(-1, -1);
		if (this->_bullets[i].getX() != -1 && this->_bullets[i].getY() != -1)
			this->_bullets[i].setPos(this->_bullets[i].getX() - 1, this->_bullets[i].getY());
		else
			continue;
	}
}

void			Game::drawBullets( void ) const {

	for (int i = 0; i < BULLETS_NB; i++)
	{
		if (this->_bullets[i].getX() != -1 && this->_bullets[i].getY() != -1)
			this->_bullets[i].draw();
		else
			continue;
	}
}

void 			Game::shoot( int const x, int const y ) {

	for (int i = 0; i < BULLETS_NB; i++)
	{
		if (this->_bullets[i].getX() == -1 && this->_bullets[i].getY() == -1) {
			this->_bullets[i].setPos(x - 1, y);
			break ;
		}
	}

}

void			Game::colission( void ) {

	for (int i = 0; i < EMEMIES_NB; i++)
	{
			// Check main point
		if ( (this->_enemies[i].getX() == this->_player.getX() && this->_enemies[i].getY() == this->_player.getY() ) || 
			// Check left wing
			 (this->_enemies[i].getX() == (this->_player.getX() + 1) && this->_enemies[i].getY() == (this->_player.getY() - 1) ) || 
			// Check right wing
 			 (this->_enemies[i].getX() == (this->_player.getX() + 1) && this->_enemies[i].getY() == (this->_player.getY() + 1) ))
 		{
			this->_end_game = true;
		}

		for (int j = 0; j < BULLETS_NB; j++)
		{
			if ((this->_enemies[i].getX() == this->_bullets[j].getX() && this->_enemies[i].getY() == this->_bullets[j].getY()) || 
				(this->_enemies[i].getX() == this->_bullets[j].getX() - 1 && this->_enemies[i].getY() == this->_bullets[j].getY()) )
			{
				this->_score += 10;
				this->_enemies[i].setPos(0, 0);
				this->_bullets[j].setPos(-1, -1);
			}
		}
	}
}

void			Game::start( void ) {

	while (1) {

		clear();

		if (this->_end_game) {
			move(this->_w_height / 2, (this->_w_width / 2) - 4);
			printw("GAME OVER");
			move(this->_w_height / 2 + 1, (this->_w_width / 2) - 4);
			printw("Your score: %d", this->_score);
			while(getch() != 'q');
			break ;
		}

		if (this->_player.getShoot()) {
			this->_player.setShoot(false);
			this->shoot(this->_player.getX(), this->_player.getY());
		}

		if (!(this->_cycle % 5))
		{
			this->moveEnemies();
			this->moveBullets();
		}

		this->_player.action(this->_w_height, this->_w_width, this->_end_game);

		this->colission();

		this->drawEnemies();

		this->drawBullets();
				
		this->_player.draw();

		move(0, 0);
		printw("%d %d", this->_player.getX(), this->_player.getY());
		move(1, 0);
		printw("Scores: %d", this->_score);

		refresh();

		this->_cycle++;

		usleep(500 * FPS);
	}

}

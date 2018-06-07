/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 19:17:27 by dkhlopov          #+#    #+#             */
/*   Updated: 2018/04/08 19:17:28 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACHARACTER_HPP
# define ACHARACTER_HPP

#include <curses.h>
#include <iostream>

class ACharacter
{

protected:

	int		_x;
	int		_y;
	int		_char;
	int		_color;

public:

	ACharacter();
	ACharacter(ACharacter const & src);
	ACharacter( int const x, int const y, int const ch );
	~ACharacter();

	ACharacter & 	operator=( ACharacter const & rhs );

	int			getX( void ) const ;
	int			getY( void ) const ;
	int			getChar( void ) const ;
	int			getColor( void ) const ;

	void		setChar( char const ch );
	void		setX( int const x );
	void		setY( int const y );
	void		setPos( int const x, int const y);

	void 		draw( void ) const ;
	
};

#endif

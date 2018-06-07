/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 19:18:37 by dkhlopov          #+#    #+#             */
/*   Updated: 2018/04/08 19:18:39 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "ACharacter.hpp"

class Player : public ACharacter
{

private:

	bool			_shoot;

public:

	Player( void );
	Player( Player const & src );
	~Player( void );

	Player & 		operator=( Player const & rhs );

	bool			getShoot( void ) const;

	void			setShoot( bool const shoot ); 

	void 			action( int const height, int const width, bool & end_flag );

	void 			draw( void ) const ;

};

#endif

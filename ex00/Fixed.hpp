/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipelat <cipelat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 03:32:14 by cipelat           #+#    #+#             */
/*   Updated: 2025/11/20 03:21:11 by cipelat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H
#include <iostream>

class	Fixed{
	private :
		int					_nb;
		static const int	_bits = 8;
	public :
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator=(const Fixed &other);
		int  getRawBits(void) const;
    	void setRawBits(int const raw);
};

#endif
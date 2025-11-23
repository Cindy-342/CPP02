/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipelat <cipelat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 03:38:22 by cipelat           #+#    #+#             */
/*   Updated: 2025/11/23 20:23:48 by cipelat          ###   ########.fr       */
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
		Fixed(const int nb);
		Fixed(const float nb);
		Fixed(const Fixed& other);
		~Fixed();
		int 	getRawBits(void) const;
    	void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;	
		bool operator!=(const Fixed &other);
		bool operator==(const Fixed &other);
		bool operator<=(const Fixed &other);
		bool operator>=(const Fixed &other);
		bool operator>(const Fixed &other);
		bool operator<(const Fixed &other);
		Fixed&	operator=(const Fixed &other);
		Fixed 	operator++(int);
		Fixed 	operator--(int);
		Fixed& 	operator++();
		Fixed& 	operator--();
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
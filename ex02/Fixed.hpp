/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipelat <cipelat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 03:38:22 by cipelat           #+#    #+#             */
/*   Updated: 2025/11/24 01:21:41 by cipelat          ###   ########.fr       */
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
		bool operator!=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		Fixed&	operator=(const Fixed &other);
		Fixed 	operator++(int);
		Fixed& 	operator++();
		Fixed 	operator--(int);
		Fixed& 	operator--();
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;
		static const Fixed&	min(const Fixed &first, const Fixed &second);
		static Fixed&		min(Fixed &first, Fixed &second);
		static const Fixed&	max(const Fixed &first, const Fixed &second);
		static Fixed&		max(Fixed &first, Fixed &second);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
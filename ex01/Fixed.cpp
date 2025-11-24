/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipelat <cipelat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 03:38:32 by cipelat           #+#    #+#             */
/*   Updated: 2025/11/23 23:35:37 by cipelat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _nb(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
    _nb = nb << _bits; 
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	if (nb >= 0)
    	_nb = (int)(nb * (1 << _bits) + 0.5f);
	else
    	_nb = (int)(nb * (1 << _bits) - 0.5f);
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_nb = other._nb;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_nb = other._nb;
	return(*this);
}

int  Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_nb);
}

void Fixed::setRawBits(int const raw)
{
	_nb = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_nb / (1 << _bits));
}

int Fixed::toInt(void) const
{
	return (_nb >> _bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	const float nb = fixed.toFloat();
	out << nb;
	return(out);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
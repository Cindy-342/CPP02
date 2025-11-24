/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipelat <cipelat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 03:38:32 by cipelat           #+#    #+#             */
/*   Updated: 2025/11/24 01:22:09 by cipelat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/* ************************************************************************** */
/*                          CONSTRUCTORS / DESTRUCTORS                        */
/* ************************************************************************** */

Fixed::Fixed() : _nb(0) 
{
}

Fixed::Fixed(const int nb)
{
    _nb = nb << _bits; 
}

Fixed::Fixed(const float nb)
{
	if (nb >= 0)
    	_nb = (int)(nb * (1 << _bits) + 0.5f);
	else
    	_nb = (int)(nb * (1 << _bits) - 0.5f);
}

Fixed::Fixed(const Fixed& other)
{
	this->_nb = other._nb;
}

Fixed::~Fixed()
{
}


/* ************************************************************************** */
/*                           GETTERS / SETTERS                                */
/* ************************************************************************** */

int  Fixed::getRawBits(void) const
{
	return (_nb);
}

void Fixed::setRawBits(int const raw)
{
	_nb = raw;
}


/* ************************************************************************** */
/*                             CONVERSIONS                                    */
/* ************************************************************************** */

float Fixed::toFloat(void) const
{
	return ((float)_nb / (1 << _bits));
}

int Fixed::toInt(void) const
{
	return (_nb >> _bits);
}


/* ************************************************************************** */
/*                        COMPARISON OPERATORS                                */
/* ************************************************************************** */

bool Fixed::operator!=(const Fixed &other) const
{
	return(this->_nb != other._nb);
}

bool Fixed::operator==(const Fixed &other) const
{
	return(this->_nb == other._nb);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_nb <= other._nb);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_nb >= other._nb);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_nb < other._nb);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_nb > other._nb);
}


/* ************************************************************************** */
/*                       ASSIGNMENT OPERATOR                                  */
/* ************************************************************************** */

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_nb = other._nb;
	return(*this);
}


/* ************************************************************************** */
/*                     INCREMENT / DECREMENT OPERATORS                        */
/* ************************************************************************** */

Fixed Fixed::operator++(int)
{
	Fixed	res;
	res._nb = this->_nb; 
	this->_nb++;
	return(res);
}

Fixed& Fixed::operator++()
{
	this->_nb++;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	res;
	res._nb = this->_nb; 
	this->_nb--;
	return(res);
}

Fixed& Fixed::operator--()
{
	this->_nb--;
	return(*this);
}


/* ************************************************************************** */
/*                     INCREMENT / DECREMENT OPERATORS                        */
/* ************************************************************************** */

Fixed Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{	
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}


/* ************************************************************************** */
/*                          STATIC MIN / MAX                                  */
/* ************************************************************************** */

const Fixed&	Fixed::min(const Fixed &first, const Fixed &second)
{
	return (first < second ? first : second);
}

Fixed&	Fixed::min(Fixed &first, Fixed &second)
{
	return (first < second ? first : second);
}

const Fixed&	Fixed::max(const Fixed &first, const Fixed &second)
{
	return (first > second ? first : second);
}

Fixed&	Fixed::max(Fixed &first, Fixed &second)
{
	return (first > second ? first : second);
}


/* ************************************************************************** */
/*                       STREAM INSERTION / OUTPUT                            */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	const float nb = fixed.toFloat();
	out << nb;
	return(out);
}
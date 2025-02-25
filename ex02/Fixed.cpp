/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:32:33 by junkwak           #+#    #+#             */
/*   Updated: 2025/02/25 16:27:04 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->Fixed_save = 0;
}

// Fixed::Fixed(float a)
// {
//   Fixed_save = roundf(a / (1 << this->static_integer));
// }
/*
Fixed::Fixed(int int_Fixed)
{
	this->Fixed_save = int_Fixed;
}
*/
Fixed::Fixed(const float float_Fixed)
{
	Fixed_save = roundf(float_Fixed * (1 << static_integer));
}

Fixed& Fixed::operator = (const Fixed& copy_fixed)
{
	if (this != &copy_fixed)
	{
		this->Fixed_save = copy_fixed.Fixed_save;
	}
	return (*this);
}

Fixed::~Fixed(void)
{
}

float	Fixed::toFloat(void) const
{
	return ((float)this->Fixed_save / (1 << this->static_integer)); 
}


std::ostream& operator <<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

int	Fixed::getRawBits(void) const//고정소수점 값의 원시값 반환하는 멤버함수
{
	return (this->Fixed_save);
}
void	Fixed::setRawBits(int const raw)//고정소수점 수의 원시값을 설정하는 멤버함수
{
	this->Fixed_save = raw;
}

// Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2) {
//   return (fixed1.getRawBits() <= fixed2.getRawBits()) ? fixed2 : fixed1;
// }

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
    return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
    return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const
{
    return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
    return (this->getRawBits() != other.getRawBits());
}

Fixed   Fixed::operator+(const Fixed &other) const
{
  return Fixed(this->toFloat() + other.toFloat());
}


Fixed   Fixed::operator-(const Fixed &other) const
{
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed   Fixed::operator*(const Fixed &other) const
{
  return ((this->toFloat() * other.toFloat()));
}

Fixed   Fixed::operator/(const Fixed &other) const
{
  return Fixed(this->toFloat() / other.toFloat());
}

Fixed   Fixed::operator++()
{
  this->Fixed_save += 1;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
  Fixed temp = *this;
  this->Fixed_save += 1;
  return (temp);
}

Fixed	Fixed::operator--()
{
  this->Fixed_save -= 1;
  return (*this);
}

Fixed Fixed::operator--(int)
{
  Fixed temp = *this;
  this->Fixed_save -= 1;
  return temp;
}

const Fixed	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
  if (fixed1 > fixed2)
    return (fixed1);
  return (fixed2);
}

Fixed	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
  if (fixed1 > fixed2)
    return (fixed1);
  return (fixed2);
}

const Fixed	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
  if (fixed1 > fixed2)
    return (fixed2);
  return (fixed1);
}


Fixed	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
  if (fixed1 > fixed2)
    return (fixed2);
  return (fixed1);
}


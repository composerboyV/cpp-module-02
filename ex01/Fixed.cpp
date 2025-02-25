/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:36:52 by junkwak           #+#    #+#             */
/*   Updated: 2025/02/25 16:10:04 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->Fixed_save = 0;
}
Fixed::Fixed(int num)
{
	std::cout << "Int constructor called" << std::endl;
	Fixed_save = num << bits;
}

Fixed::Fixed(float float_Fixed)
{
	std:: cout << "Float constructor called" << std::endl;
	Fixed_save = roundf(float_Fixed * (1 << bits));
}
Fixed::Fixed(const Fixed& copy_fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy_fixed;
}

Fixed& Fixed::operator = (const Fixed& copy_fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy_fixed)
	{
		this->Fixed_save = copy_fixed.Fixed_save;
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" <<std::endl;
}
std::ostream& operator <<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->Fixed_save / (1 << this->bits)); 
}

int	Fixed::toInt(void) const
{
	return (this->Fixed_save >> this->bits);
}
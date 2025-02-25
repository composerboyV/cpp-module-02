/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:21:56 by junkwak           #+#    #+#             */
/*   Updated: 2025/02/25 19:12:44 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->Fixed_save = 0;
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
		this->Fixed_save = copy_fixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" <<std::endl;
}
int	Fixed::getRawBits(void) const//고정소수점 값의 원시값 반환하는 멤버함수
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->Fixed_save);
}
void	Fixed::setRawBits(int const raw)//고정소수점 수의 원시값을 설정하는 멤버함수
{
	this->Fixed_save = raw;
}
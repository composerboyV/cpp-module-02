/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:32:27 by junkwak           #+#    #+#             */
/*   Updated: 2025/02/25 16:27:09 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class	Fixed {
	private :
		int	Fixed_save;
		static const int static_integer = 8;
	public :
		Fixed();
		//Fixed(int int_Fixed);
		Fixed(const float num);
		Fixed& operator = (Fixed const other);
		~Fixed();
		int	getRawBits(void) const;//고정소수점 값의 원시값 반환하는 멤버함수
		void	setRawBits(int const raw);//고정소수점 수의 원시값을 설정하는 멤버함수
		float	toFloat(void) const;
		void	toFloat();
		//int		value;
		Fixed& operator = (const Fixed& copy_fixed);
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;
		static Fixed	min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed	min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed	max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed	max(const Fixed& fixed1, const Fixed& fixed2);
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;
		Fixed	operator++(void);//전위증가
		Fixed	operator++(int);//후위증가
		Fixed	operator--(void);
		Fixed	operator--(int);
};

std::ostream& operator <<(std::ostream &out, const Fixed &fixed);


#endif
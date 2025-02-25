/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:21:51 by junkwak           #+#    #+#             */
/*   Updated: 2025/02/25 16:10:21 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	FIXED_HPP
# define	FIXED_HPP

#include <iostream>
#include <string>

class	Fixed {
	private :
		int Fixed_save;//고정소수점 숫자값을 저장할 정수형 변수
		static const int static_integer = 8; //정적 정수형 상수,항상 8
	public :
		Fixed();//값을 0으로 초기화해줄 생성자
		Fixed(const Fixed& copy_fixed);//복사생성자
		Fixed& operator = (const Fixed& copy_fixed);
		~Fixed();//소멸자
		int	getRawBits(void) const;//고정소수점 값의 원시값 반환하는 멤버함수
		void	setRawBits(int const raw);//고정소수점 수의 원시값을 설정하는 멤버함수
		void	toFloat();
};


#endif
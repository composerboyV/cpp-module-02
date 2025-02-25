/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:36:52 by junkwak           #+#    #+#             */
/*   Updated: 2025/02/25 13:14:08 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	FIXED_HPP
# define	FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>


class	Fixed {
	private :
		int Fixed_save;//고정소수점 숫자값을 저장할 정수형 변수
		static const int bits = 8; //정적 정수형 상수,항상 8
	public :
		Fixed();//값을 0으로 초기화해줄 생성자
		Fixed(int num);//Int 생성자
		Fixed(float float_Fixed);
		Fixed(const Fixed& copy_fixed);//복사생성자
		Fixed& operator = (const Fixed& copy_fixed);
		~Fixed();//소멸자
		int	toInt(void) const;
		float	toFloat(void) const;
		void	toFloat();
};
std::ostream& operator <<(std::ostream &out, const Fixed &fixed);
#endif
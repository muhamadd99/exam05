/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:56:59 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/19 23:32:58 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
# define vECT2_HPP

#include <vector>
#include <iostream>

class vect2 {
private:
	int x;
	int	y;
public:
	vect2();
	vect2(int paramX, int paramY);
	vect2&	operator=(const vect2& other);
	~vect2();
	
	vect2	operator+(const vect2& other) const;
	vect2	operator-(const vect2& other) const;
	vect2	operator* (const vect2& other) const;
	//comparison
	vect2	operator==(const vect2& other) const;
	vect2	operator!=(const vect2& other) const;
	//increment, decrement
	vect2	&operator++();
	vect2	operator++(int);
	vect2	&operator--();
	vect2	operator--(int);
	//extra
	std::ostream&	operator<<(std::ostream &os, const vect2& other);
	vect2	operator+=(const vect2& other);
	vect2	operator-=(const vect2& other);
	vect2	operator*=(const int scalar);
	//signed
	vect2	operator+();
	vect2	operator-();
	
	int	operator[](const vect2& other);
	friend std::ostream&	operator<<(std::ostream os, const vect2& other);
}

vect2	operator*(const int scaler, const vect2 &other);

#endif
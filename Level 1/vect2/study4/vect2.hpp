/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:40:11 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/21 14:57:47 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2{
private:
	int	_x;
	int	_y;
public:
	vect2();
	vect2(int paramX, int paramY);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);
	~vect2();
	//addition
	vect2	operator+(const vect2 &other) const;
	vect2&	operator+=(const vect2 &other);
	//substraction
	vect2	operator-(const vect2 &other) const;
	vect2	operator-=(const vect2 &other);
	//multiplication
	vect2	operator*(const vect2 &other) const;
	vect2	operator*=(int scalar);
	//subscript
	int	operator[](int i);
	const int	operator[](int i) const;
	//increment decrement
	vect2&	operator++();
	vect2	operator++(int);
	vect2&	operator--();
	vect2	operator--(int);
	//
};

#endif